/*
    This file was a part of JQLibrary

    Add a easy analysis for post require
    
    It should compatible to MeowHttpd
    
    license under LGPLV3

    edited by xqqy
*/
#if _MSC_VER >= 1600

#pragma execution_character_set("utf-8")

#endif


#include "MeowHttpd_nossl_nolocal.h"

// Qt lib import
#include <QEventLoop>
#include <QTimer>
#include <QSemaphore>
#include <QMetaObject>
#include <QThread>
#include <QThreadPool>
#include <QJsonDocument>
#include <QJsonValue>
#include <QPointer>
#include <QFile>
#include <QImage>
#include <QBuffer>

#include <QtConcurrent>

#include <QTcpServer>
#include <QTcpSocket>


using namespace MeowHttpd;

static QString replyTextFormat(
        "HTTP/1.1 %1 OK\r\n"
        "Content-Type: %2\r\n"
        "Content-Length: %3\r\n"
        "Access-Control-Allow-Origin: *\r\n"
        "\r\n"
        "%4"
    );

static QString replyRedirectsFormat(
        "HTTP/1.1 %1 OK\r\n"
        "Content-Type: %2\r\n"
        "Content-Length: %3\r\n"
        "Access-Control-Allow-Origin: *\r\n"
        "\r\n"
        "%4"
    );

static QString replyFileFormat(
        "HTTP/1.1 %1 OK\r\n"
        "Content-Disposition: attachment;filename=%2\r\n"
        "Content-Length: %3\r\n"
        "Access-Control-Allow-Origin: *\r\n"
        "\r\n"
    );

static QString replyImageFormat(
        "HTTP/1.1 %1 OK\r\n"
        "Content-Type: image/png\r\n"
        "Content-Length: %2\r\n"
        "Access-Control-Allow-Origin: *\r\n"
        "\r\n"
    );

static QString replyOptionsFormat(
        "HTTP/1.1 200 OK\r\n"
        "Allow: OPTIONS, GET, POST, PUT, HEAD\r\n"
        "Access-Control-Allow-Methods: OPTIONS, GET, POST, PUT, HEAD\r\n"
        "Content-Length: 0\r\n"
        "Access-Control-Allow-Origin: *\r\n"
        "\r\n"
    );

// Session
Session::Session(const QPointer<QTcpSocket> &tcpSocket):
    ioDevice_( tcpSocket ),
    timerForClose_( new QTimer )
{
    timerForClose_->setInterval( 30 * 1000 );

    connect( ioDevice_.data(), &QIODevice::readyRead, [ this ]()
    {
        if ( this->timerForClose_->isActive() )
        {
            timerForClose_->stop();
        }

        const auto &&data = this->ioDevice_->readAll();
//        qDebug() << data;

        this->buffer_.append( data );

        this->inspectionBufferSetup1();

        timerForClose_->start();
    } );

    connect( ioDevice_.data(), &QIODevice::bytesWritten, [ this ](const qint64 &bytes)
    {
        this->waitWrittenByteCount_ -= bytes;

        if ( this->waitWrittenByteCount_ == 0 )
        {
            this->deleteLater();
            return;
        }

        if ( !ioDeviceForReply_.isNull() )
        {
            if ( ioDeviceForReply_->atEnd() )
            {
                delete ioDeviceForReply_.data();
                ioDeviceForReply_.clear();
            }
            else
            {
                ioDevice_->write( ioDeviceForReply_->read( 8 * 1024 ) );
            }
        }

        if ( this->timerForClose_->isActive() )
        {
            timerForClose_->stop();
        }

        timerForClose_->start();
    } );

    connect( timerForClose_.data(), &QTimer::timeout, this, &QObject::deleteLater );
}

Session::~Session()
{
    if ( !ioDevice_.isNull() )
    {
        delete ioDevice_.data();
    }
}

QMap< QString, QString > Session::requestPost() const
{
if(requestBody_.isEmpty() || requestBody_.isNull()){return { };}
    QMap< QString, QString > result;
    int all=0;
    QString body=requestBody_;

    for (int i = 0; i < body.length(); i++)
    {
        if (body.toStdString()[i] == '=')
        {
            all++;
        }
    }
    for(int now=0;now<all;now++){
        result[body.section('&',now,now).section('=',0,0)]=body.section('&',now,now).section('=',1,1);
    }

    return result;
}

QString Session::requestUrlPath() const
{
    QString result;
    const auto indexForQueryStart = requestUrl_.indexOf( "?" );

    if ( indexForQueryStart >= 0 )
    {
        result = requestUrl_.mid( 0, indexForQueryStart );
    }
    else
    {
        result = requestUrl_;
    }

    if ( result.startsWith( "//" ) )
    {
        result = result.mid( 1 );
    }

    if ( result.endsWith( "/" ) )
    {
        result = result.mid( 0, result.size() - 1 );
    }

    result.replace( "%5B", "[" );
    result.replace( "%5D", "]" );
    result.replace( "%7B", "{" );
    result.replace( "%7D", "}" );
    result.replace( "%5E", "^" );

    return result;
}

QStringList Session::requestUrlPathSplitToList() const
{
    auto list = this->requestUrlPath().split( "/" );

    while ( !list.isEmpty() && list.first().isEmpty() )
    {
        list.pop_front();
    }

    while ( !list.isEmpty() && list.last().isEmpty() )
    {
        list.pop_back();
    }

    return list;
}

QMap< QString, QString > Session::requestGet() const
{
    const auto indexForQueryStart = requestUrl_.indexOf( "?" );
    if ( indexForQueryStart < 0 ) { return { }; }

    QMap< QString, QString > result;

    auto lines = QUrl::fromEncoded( requestUrl_.mid( indexForQueryStart + 1 ).toUtf8() ).toString().split( "&" );

    for ( const auto &line_: lines )
    {
        auto line = line_;
        line.replace( "%5B", "[" );
        line.replace( "%5D", "]" );
        line.replace( "%7B", "{" );
        line.replace( "%7D", "}" );
        line.replace( "%5E", "^" );

        auto indexOf = line.indexOf( "=" );
        if ( indexOf > 0 )
        {
            result[ line.mid( 0, indexOf ) ] = line.mid( indexOf + 1 );
        }
    }

    return result;
}

void Session::replyText(const QString &replyData, const int &httpStatusCode)
{
    auto this_ = this;
    if ( !this_ )
    {
        qDebug() << "MeowHttpd::Session::replyText: current session this is null";
        return;
    }

    if ( QThread::currentThread() != this->thread() )
    {
        QMetaObject::invokeMethod( this, "replyText", Qt::QueuedConnection, Q_ARG( QString, replyData ), Q_ARG( int, httpStatusCode ) );
        return;
    }

    if ( alreadyReply_ )
    {
        qDebug() << "MeowHttpd::Session::replyText: already reply";
        return;
    }
    alreadyReply_ = true;

    if ( ioDevice_.isNull() )
    {
        qDebug() << "MeowHttpd::Session::replyText: error1";
        this->deleteLater();
        return;
    }

    const auto &&data = replyTextFormat.arg(
                QString::number( httpStatusCode ),
                "text;charset=UTF-8",
                QString::number( replyData.toUtf8().size() ),
                replyData
            ).toUtf8();

    waitWrittenByteCount_ = data.size();
    ioDevice_->write( data );
}

void Session::replyRedirects(const QUrl &targetUrl, const int &httpStatusCode)
{
    auto this_ = this;
    if ( !this_ )
    {
        qDebug() << "MeowHttpd::Session::replyRedirects: current session this is null";
        return;
    }

    if ( QThread::currentThread() != this->thread() )
    {
        QMetaObject::invokeMethod( this, "replyRedirects", Qt::QueuedConnection, Q_ARG( QUrl, targetUrl ), Q_ARG( int, httpStatusCode ) );
        return;
    }

    if ( alreadyReply_ )
    {
        qDebug() << "MeowHttpd::Session::replyRedirects: already reply";
        return;
    }
    alreadyReply_ = true;

    if ( ioDevice_.isNull() )
    {
        qDebug() << "MeowHttpd::Session::replyRedirects: error1";
        this->deleteLater();
        return;
    }

    const auto &&buffer = QString( "<head>\n<meta http-equiv=\"refresh\" content=\"0;URL=%1/\" />\n</head>" ).arg( targetUrl.toString() );

    const auto &&data = replyRedirectsFormat.arg(
                QString::number( httpStatusCode ),
                "text;charset=UTF-8",
                QString::number( buffer.toUtf8().size() ),
                buffer
            ).toUtf8();

    waitWrittenByteCount_ = data.size();
    ioDevice_->write( data );
}

void Session::replyJsonObject(const QJsonObject &jsonObject, const int &httpStatusCode)
{
    auto this_ = this;
    if ( !this_ )
    {
        qDebug() << "MeowHttpd::Session::replyJsonObject: current session this is null";
        return;
    }

    if ( QThread::currentThread() != this->thread() )
    {
        QMetaObject::invokeMethod( this, "replyJsonObject", Qt::QueuedConnection, Q_ARG( QJsonObject, jsonObject ), Q_ARG( int, httpStatusCode ) );
        return;
    }

    if ( alreadyReply_ )
    {
        qDebug() << "MeowHttpd::Session::replyJsonObject: already reply";
        return;
    }
    alreadyReply_ = true;

    if ( ioDevice_.isNull() )
    {
        qDebug() << "MeowHttpd::Session::replyJsonObject: error1";
        this->deleteLater();
        return;
    }

    const auto &&data = QJsonDocument( jsonObject ).toJson( QJsonDocument::Compact );
    const auto &&data2 = replyTextFormat.arg(
                QString::number( httpStatusCode ),
                "application/json;charset=UTF-8",
                QString::number( data.size() ),
                QString( data )
            ).toUtf8();

    waitWrittenByteCount_ = data2.size();
    ioDevice_->write( data2 );
}

void Session::replyJsonArray(const QJsonArray &jsonArray, const int &httpStatusCode)
{
    auto this_ = this;
    if ( !this_ )
    {
        qDebug() << "MeowHttpd::Session::replyJsonArray: current session this is null";
        return;
    }

    if ( QThread::currentThread() != this->thread() )
    {
        QMetaObject::invokeMethod( this, "replyJsonArray", Qt::QueuedConnection, Q_ARG( QJsonArray, jsonArray ), Q_ARG( int, httpStatusCode ) );
        return;
    }

    if ( alreadyReply_ )
    {
        qDebug() << "MeowHttpd::Session::replyJsonArray: already reply";
        return;
    }
    alreadyReply_ = true;

    if ( ioDevice_.isNull() )
    {
        qDebug() << "MeowHttpd::Session::replyJsonArray: error1";
        this->deleteLater();
        return;
    }

    const auto &&data = QJsonDocument( jsonArray ).toJson( QJsonDocument::Compact );
    const auto &&data2 = replyTextFormat.arg(
                QString::number( httpStatusCode ),
                "application/json;charset=UTF-8",
                QString::number( data.size() ),
                QString( data )
            ).toUtf8();

    waitWrittenByteCount_ = data2.size();
    ioDevice_->write( data2 );
}

void Session::replyFile(const QString &filePath, const int &httpStatusCode)
{
    auto this_ = this;
    if ( !this_ )
    {
        qDebug() << "MeowHttpd::Session::replyFile: current session this is null";
        return;
    }

    if ( QThread::currentThread() != this->thread() )
    {
        QMetaObject::invokeMethod( this, "replyFile", Qt::QueuedConnection, Q_ARG( QString, filePath ), Q_ARG( int, httpStatusCode ) );
        return;
    }

    if ( alreadyReply_ )
    {
        qDebug() << "MeowHttpd::Session::replyFile: already reply";
        return;
    }
    alreadyReply_ = true;

    if ( ioDevice_.isNull() )
    {
        qDebug() << "MeowHttpd::Session::replyFile: error1";
        this->deleteLater();
        return;
    }

    ioDeviceForReply_.reset( new QFile( filePath ) );
    QPointer< QFile > file = ( qobject_cast< QFile * >( ioDeviceForReply_.data() ) );

    if ( !file->open( QIODevice::ReadOnly ) )
    {
        qDebug() << "MeowHttpd::Session::replyFile: open file error:" << filePath;
        ioDeviceForReply_.clear();
        this->deleteLater();
        return;
    }

    const auto &&data = replyFileFormat.arg(
                QString::number( httpStatusCode ),
                QFileInfo( filePath ).fileName(),
                QString::number( file->size() )
            ).toUtf8();

    waitWrittenByteCount_ = data.size() + file->size();
    ioDevice_->write( data );
}

void Session::replyImage(const QImage &image, const int &httpStatusCode)
{
    auto this_ = this;
    if ( !this_ )
    {
        qDebug() << "MeowHttpd::Session::replyImage: current session this is null";
        return;
    }

    if ( QThread::currentThread() != this->thread() )
    {
        QMetaObject::invokeMethod( this, "replyImage", Qt::QueuedConnection, Q_ARG( QImage, image ), Q_ARG( int, httpStatusCode ) );
        return;
    }

    if ( alreadyReply_ )
    {
        qDebug() << "MeowHttpd::Session::replyImage: already reply";
        return;
    }
    alreadyReply_ = true;

    if ( ioDevice_.isNull() )
    {
        qDebug() << "MeowHttpd::Session::replyImage: error1";
        this->deleteLater();
        return;
    }

    auto buffer = new QBuffer;

    if ( !buffer->open( QIODevice::ReadWrite ) )
    {
        qDebug() << "MeowHttpd::Session::replyImage: open buffer error";
        delete buffer;
        this->deleteLater();
        return;
    }

    if ( !image.save( buffer, "PNG" ) )
    {
        qDebug() << "MeowHttpd::Session::replyImage: save image to buffer error";
        delete buffer;
        this->deleteLater();
        return;
    }

    ioDeviceForReply_.reset( buffer );
    ioDeviceForReply_->seek( 0 );

    const auto &&data = replyImageFormat.arg(
                QString::number( httpStatusCode ),
                QString::number( buffer->buffer().size() )
            ).toUtf8();

    waitWrittenByteCount_ = data.size() + buffer->buffer().size();
    ioDevice_->write( data );
}

void Session::replyOptions()
{
    auto this_ = this;
    if ( !this_ )
    {
        qDebug() << "MeowHttpd::Session::replyOptions: current session this is null";
        return;
    }

    if ( QThread::currentThread() != this->thread() )
    {
        QMetaObject::invokeMethod( this, "replyOptions", Qt::QueuedConnection );
        return;
    }

    if ( alreadyReply_ )
    {
        qDebug() << "MeowHttpd::Session::replyOptions: already reply";
        return;
    }
    alreadyReply_ = true;

    if ( ioDevice_.isNull() )
    {
        qDebug() << "MeowHttpd::Session::replyOptions: error1";
        this->deleteLater();
        return;
    }

    const auto &&data2 = replyOptionsFormat.toUtf8();

    waitWrittenByteCount_ = data2.size();
    ioDevice_->write( data2 );
}

void Session::inspectionBufferSetup1()
{
    if ( !headerAcceptedFinish_ )
    {
        forever
        {
            static QByteArray splitFlag( "\r\n" );

            auto splitFlagIndex = buffer_.indexOf( splitFlag );

            // 没有获取到分割标记，意味着数据不全
            if ( splitFlagIndex == -1 )
            {
                // 没有获取到 method 但是缓冲区内已经有了数据，这可能是一个无效的连接
                if ( requestMethod_.isEmpty() && ( buffer_.size() > 4 ) )
                {
                    qDebug() << "MeowHttpd::Session::inspectionBuffer: error0";
                    this->deleteLater();
                    return;
                }

                return;
            }

            // 如果未获取到 method 并且已经定位到了分割标记符，那么直接放弃这个连接
            if ( requestMethod_.isEmpty() && ( splitFlagIndex == 0 ) )
            {
                qDebug() << "MeowHttpd::Session::inspectionBuffer: error1";
                this->deleteLater();
                return;
            }

            // 如果没有获取到 method 则先尝试分析 method
            if ( requestMethod_.isEmpty() )
            {
                auto requestLineDatas = buffer_.mid( 0, splitFlagIndex ).split( ' ' );
                buffer_.remove( 0, splitFlagIndex + 2 );

                if ( requestLineDatas.size() != 3 )
                {
                    qDebug() << "MeowHttpd::Session::inspectionBuffer: error2";
                    this->deleteLater();
                    return;
                }

                requestMethod_ = requestLineDatas.at( 0 );
                requestUrl_ = requestLineDatas.at( 1 );
                requestCrlf_ = requestLineDatas.at( 2 );

                if ( ( requestMethod_ != "GET" ) &&
                     ( requestMethod_ != "OPTIONS" ) &&
                     ( requestMethod_ != "POST" ) &&
                     ( requestMethod_ != "PUT" ) )
                {
                    qDebug() << "MeowHttpd::Session::inspectionBuffer: error3:" << requestMethod_;
                    this->deleteLater();
                    return;
                }
            }
            else if ( splitFlagIndex == 0 )
            {
                buffer_.remove( 0, 2 );

//                qDebug() << buffer_;
                headerAcceptedFinish_ = true;

                if ( ( requestMethod_.toUpper() == "GET" ) ||
                     ( requestMethod_.toUpper() == "OPTIONS" ) ||
                     ( ( requestMethod_.toUpper() == "POST" ) && ( ( contentLength_ > 0 ) ? ( !buffer_.isEmpty() ) : ( true ) ) ) ||
                     ( ( requestMethod_.toUpper() == "PUT" ) && ( ( contentLength_ > 0 ) ? ( !buffer_.isEmpty() ) : ( true ) ) ) )
                {
                    this->inspectionBufferSetup2();
                }
            }
            else
            {
                auto index = buffer_.indexOf( ':' );

                if ( index <= 0 )
                {
                    qDebug() << "MeowHttpd::Session::inspectionBuffer: error4";
                    this->deleteLater();
                    return;
                }

                auto headerData = buffer_.mid( 0, splitFlagIndex );
                buffer_.remove( 0, splitFlagIndex + 2 );

                const auto &&key = headerData.mid( 0, index );
                auto value = headerData.mid( index + 1 );

                if ( value.startsWith( ' ' ) )
                {
                    value.remove( 0, 1 );
                }

                requestHeader_[ key ] = value;

                if ( key.toLower() == "content-length" )
                {
                    contentLength_ = value.toLongLong();
                }
            }
        }
    }
    else
    {
        this->inspectionBufferSetup2();
    }
}

void Session::inspectionBufferSetup2()
{
    requestBody_ += buffer_;
    buffer_.clear();

//    qDebug() << requestBody_.size() << contentLength_;

    if ( !handleAcceptedCallback_ )
    {
        qDebug() << "MeowHttpd::Session::inspectionBuffer: error4";
        this->deleteLater();
        return;
    }

    if ( ( contentLength_ != -1 ) && ( requestBody_.size() != contentLength_ ) )
    {
        return;
    }

    handleAcceptedCallback_( this );
}

// AbstractManage
AbstractManage::AbstractManage(const int &handleMaxThreadCount)
{
    handleThreadPool_.reset( new QThreadPool );
    serverThreadPool_.reset( new QThreadPool );

    handleThreadPool_->setMaxThreadCount( handleMaxThreadCount );
    serverThreadPool_->setMaxThreadCount( 1 );
}

AbstractManage::~AbstractManage()
{
    this->stopHandleThread();
}

bool AbstractManage::begin()
{
    if ( QThread::currentThread() != this->thread() )
    {
        qDebug() << "MeowHttpd::Manage::listen: error: listen from other thread";
        return false;
    }

    if ( this->isRunning() )
    {
        qDebug() << "MeowHttpd::Manage::close: error: already running";
        return false;
    }

    return this->startServerThread();
}

void AbstractManage::close()
{
    if ( !this->isRunning() )
    {
        qDebug() << "MeowHttpd::Manage::close: error: not running";
        return;
    }

    emit readyToClose();

    if ( serverThreadPool_->activeThreadCount() )
    {
        this->stopServerThread();
    }
}

bool AbstractManage::startServerThread()
{
    QSemaphore semaphore;

    QtConcurrent::run( serverThreadPool_.data(), [ &semaphore, this ]()
    {
        QEventLoop eventLoop;
        QObject::connect( this, &AbstractManage::readyToClose, &eventLoop, &QEventLoop::quit );

        if ( !this->onStart() )
        {
            semaphore.release( 1 );
        }

        semaphore.release( 1 );

        eventLoop.exec();

        this->onFinish();
    } );

    semaphore.acquire( 1 );

    return this->isRunning();
}

void AbstractManage::stopHandleThread()
{
    handleThreadPool_->waitForDone();
}

void AbstractManage::stopServerThread()
{
    serverThreadPool_->waitForDone();
}

void AbstractManage::newSession(const QPointer< Session > &session)
{
    session->setHandleAcceptedCallback( [ this ](const QPointer< MeowHttpd::Session > &session){ this->handleAccepted( session ); } );

    auto session_ = session.data();
    connect( session.data(), &QObject::destroyed, [ this, session_ ]()
    {
        this->mutex_.lock();
        this->availableSessions_.remove( session_ );
        this->mutex_.unlock();
    } );
    availableSessions_.insert( session.data() );
}

void AbstractManage::handleAccepted(const QPointer<Session> &session)
{
    QtConcurrent::run( handleThreadPool_.data(), [ this, session ]()
    {
        if ( !this->httpAcceptedCallback_ )
        {
            qDebug() << "MeowHttpd::Manage::handleAccepted: error, httpAcceptedCallback_ is nullptr";
            return;
        }

        this->httpAcceptedCallback_( session );
    } );
}

// TcpServerManage
TcpServerManage::TcpServerManage(const int &handleMaxThreadCount):
    AbstractManage( handleMaxThreadCount )
{ }

TcpServerManage::~TcpServerManage()
{
    if ( this->isRunning() )
    {
        this->close();
    }
}

bool TcpServerManage::listen(const QHostAddress &address, const quint16 &port)
{
    listenAddress_ = address;
    listenPort_ = port;

    return this->begin();
}

bool TcpServerManage::isRunning()
{
    return !tcpServer_.isNull();
}

bool TcpServerManage::onStart()
{
    mutex_.lock();

    tcpServer_ = new QTcpServer;

    mutex_.unlock();

    QObject::connect( tcpServer_.data(), &QTcpServer::newConnection, [ this ]()
    {
        auto socket = this->tcpServer_->nextPendingConnection();

        this->newSession( new Session(socket) );
    } );

    if ( !tcpServer_->listen( listenAddress_, listenPort_ ) )
    {
        mutex_.lock();

        delete tcpServer_.data();
        tcpServer_.clear();

        mutex_.unlock();

        return false;
    }

    return true;
}

void TcpServerManage::onFinish()
{
    this->mutex_.lock();

    tcpServer_->close();
    delete tcpServer_.data();
    tcpServer_.clear();

    this->mutex_.unlock();
}
