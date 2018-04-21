#if _MSC_VER >= 1600

#pragma execution_character_set("utf-8")

#endif

#include <stdlib.h>    
#include <crtdbg.h>    

#include "sturecord.h"
#include "ui_sturecord.h"
#include <QAudioEncoderSettings>
#include<QFile>
#include<QUrl>
#include<QDebug>
#include<QDateTime>
#include<QAudioRecorder>
#include<QMediaPlayer>
#include<QMap>
#include<QByteArray>
#include<QDir>
#include<QMessageBox>
#include<QtNetwork/QNetworkAccessManager>
#include<QtNetwork/QNetworkRequest>
#include<QtNetwork/QNetworkReply>
#include <math.h>
#include<QTimer>
#include <QHttpMultiPart>

QAudioRecorder* audioRecorder;//录音机
QMap<int,QByteArray> document;//文件安全存储
QFile file;//文件
QMediaPlayer* player;//播放器
int docn=0;//当前文件编码
bool recording=false;//是否在录音
bool playing=false;//是否在播放
int current=-1;//当前选中项目
extern QDateTime endofexam;//结束时间
QTimer *timer, *counter;
extern QString que;//题目
extern int now,count;


sturecord::sturecord(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::sturecord)
{
    ui->setupUi(this);
    init();
}

sturecord::~sturecord()
{
    delete ui;
}

void sturecord::inerst(){
    //QListWidgetItem* lst = new QListWidgetItem(QString("录音")+QString::number(docn), ui->listWidget);
    ui->listWidget->insertItem(docn, QString("录音") + QString::number(docn));
}

void sturecord::init(){
	disconnect(timer, SIGNAL(timeout()), this, SLOT(timerDone()));
    timer->deleteLater();
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(timerDone()) );
    timer->start(1000); // 1秒单触发定时器
    ui->label_3->setText(que);
    for(int i=0;i<docn;i++){
        //QListWidgetItem lst(QString("录音")+QString::number(i+1), ui->listWidget);
        ui->listWidget->insertItem(i, QString("录音") + QString::number(i + 1));
    }
}

void sturecord::stopRecording(){
    audioRecorder->stop();
	audioRecorder->deleteLater();
    qDebug()<<"录音完成";
    file.setFileName(QDir::temp().absolutePath()+"/test.wav");
    file.open(QFile::ReadOnly);
    //qDebug()<< file.readAll();//读取文件到内存，安全保存
	document[docn] = file.readAll();//使用QMap
	qDebug() << document[docn];
    docn++;
    file.close();

	file.setFileName(QDir::temp().absolutePath() + "/test.wav");
	file.open(QFile::WriteOnly);//读取内存到文件
	file.write("");
	file.close();

    //play(document[docn-1]);

    inerst();
}


void sturecord::play(QByteArray doc){
    file.setFileName(QDir::temp().absolutePath()+"/test.wav");
    file.open(QFile::WriteOnly);//读取内存到文件
    file.write(doc);
    file.close();
    player = new QMediaPlayer(this);
    player->setMedia(QUrl::fromLocalFile(QDir::temp().absolutePath()+"/test.wav"));
    player->play();//播放
}

void sturecord::on_pushButton_clicked()
{
    if(recording==false){
        if(endofexam<QDateTime::currentDateTime() || count==0){
            QMessageBox::warning(NULL,"错误","您的时间已经用尽，请选择录制版本提交");
            return;
        }
        QAudioEncoderSettings audioSettings;
		audioRecorder = new QAudioRecorder(this);
        audioSettings.setCodec("audio/pcm");
        qDebug()<<audioRecorder->supportedAudioCodecs();
        audioSettings.setQuality(QMultimedia::HighQuality);//设置音频编码
        audioRecorder->setEncodingSettings(audioSettings);

		counter = new QTimer(this);
		connect(counter, SIGNAL(timeout()), this, SLOT(countlow()));
		counter->start(15000);

        if(playing){
            player->stop();//停止播放
			player->deleteLater();
        }

		audioRecorder->setOutputLocation(QUrl::fromLocalFile(QDir::temp().absolutePath()+"/test.wav"));//设置临时文件位置
        audioRecorder->record();//开始录制
        ui->pushButton->setText("停止");
        recording=true;
    }else{
		counter->stop();
		disconnect(counter, SIGNAL(timeout()), this, SLOT(countlow()));
		counter->deleteLater();
        stopRecording();//停止录制
        ui->pushButton->setText("录制");
        recording=false;
    }
}

void sturecord::countlow() {
	count -= 1;
	ui->label_4->setText("剩余次数：" + QString::number(count));
	counter->stop();
}

void sturecord::on_listWidget_currentRowChanged(int currentRow)
{
    if(currentRow!=-1){
        current=currentRow;
        ui->pushButton_2->setEnabled(true);
    }else{
        ui->pushButton_2->setEnabled(false);

    }
}

void sturecord::playerstate(QMediaPlayer::State state){
    switch (state) {
    case QMediaPlayer::StoppedState:
        ui->pushButton_2->setText("播放");
        playing=false;
		player->deleteLater();
        break;
    case QMediaPlayer::PlayingState:
        ui->pushButton_2->setText("停止");
    default:
        break;
    }
}

void sturecord::on_pushButton_2_clicked()
{
    if(playing==false){
        if(current!=-1){
            ui->pushButton_2->setText("停止");
            QMessageBox::information(NULL,"正在播放",QString::number(current));
            play(document[current]);
            playing=true;
            connect(player,SIGNAL(stateChanged(QMediaPlayer::State)),this,SLOT(playerstate(QMediaPlayer::State)));
        }else{
            QMessageBox::warning(NULL,"错误","请选中一个播放项目");
        }
    }else{
        player->stop();
    }
}

void sturecord::on_commandLinkButton_2_clicked()
{
    extern QString ip;
    extern QString token;
    qDebug()<<"MeowClient-1.1 token:"<<token;

    if(current==-1){
        QMessageBox::warning(NULL,"错误","请选中一个上传文件");
    }else{
        QNetworkAccessManager *push=new QNetworkAccessManager(this);//发送注册包
        connect(push, SIGNAL(finished(QNetworkReply*)),this, SLOT(check(QNetworkReply*)));

        QNetworkRequest send(QUrl("http://"+ip+"/put/"));
		QHttpMultiPart *mutilpart;//token
		mutilpart = new QHttpMultiPart(this);//mutilpart

        send.setHeader(QNetworkRequest::UserAgentHeader,"MeowClient-1.1");//设置文件头
		send.setHeader(QNetworkRequest::ContentTypeHeader, "Content-Type:multipart/form-data;boundary="+mutilpart->boundary());

		QHttpPart tokenpart;
		tokenpart.setHeader(QNetworkRequest::ContentDispositionHeader, QVariant("form-data; name='TOKEN'"));
		tokenpart.setBody(token.toUtf8());//token
		
		QHttpPart datapart;//data
		datapart.setHeader(QNetworkRequest::ContentTypeHeader, QVariant("form-data;name='DATA'; filename='me.wav'"));
		datapart.setBody(document[current]);//data
		mutilpart->setContentType(QHttpMultiPart::FormDataType);
		mutilpart->append(tokenpart);
		mutilpart->append(datapart);

/*
        data.append("--"+rnd+"\r"+"\n");//分隔符
        data.append("Content-Disposition: form-data;name='TOKEN'\r\n");//TOKEN
        data.append("Content-Type: text/plain; charset=UTF-8\r\n");
        data.append("Content-Transfer-Encoding: 8bit\r\n");
        data.append("\r\n");
        data.append(token);
        data.append("\r\n");
        data.append("--"+rnd+"\r\n");//分隔符
        data.append("Content-Disposition: form-data;name='DATA'; filename='me.wav'\r\n");
        data.append("Content-Type: application/octet-stream\r\n");
        data.append("Content-Transfer-Encoding: binary\r\n");
        data.append("\r\n");
        data.append(document[current]);
        data.append("\r\n");
        data.append("--"+rnd+"--");*/


        push->post(send, mutilpart);
        qDebug()<<"Registing to MeowServer-1.1";
    }
}

void sturecord::check(QNetworkReply *reply){//解析响应包
    if(reply->error() == QNetworkReply::NoError)
        {
            QByteArray bytes = reply->readAll();  //获取字节
            QString result(bytes);  //转化为字符串
            qDebug()<<"MeowServer-1.1 reply:"<<result;
            if(result=="done"){
                QMessageBox::information(NULL,"成功","您已成功提交");
                reply->deleteLater();//销毁回复
                done();
            }else{
                QMessageBox::warning(NULL, "警告！",//注册错误
                                     "向喵网络提交失败，反馈信息："+result,
                                     QMessageBox::Yes);
                qDebug()<<result;
                reply->deleteLater();//销毁回复
            }
        }
        else
        {
            //处理错误
             qDebug()<<"喵网络连接失败";
             QMessageBox::warning(NULL, "警告！",
                                  "不能连接到指定的喵网络",
                                  QMessageBox::Yes);
             reply->deleteLater();//销毁回复
        }
}

void sturecord::done(){
    document.clear();
    recording=false;
    playing=false;
    current=-1;
    docn=0;
	disconnect(timer, SIGNAL(timeout()), this, SLOT(timerDone()));
    accept();
}

void sturecord::timerDone(){
    now-=1;
    ui->progressBar->setValue(now);
    if(now<371){
        ui->progressBar->setStyleSheet("QProgressBar {color:rgb(0, 0, 0)}");
    }else{
        ui->progressBar->setStyleSheet("QProgressBar {color:rgb(255, 255, 255)}");
    }
}
