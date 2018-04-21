#if _MSC_VER >= 1600

#pragma execution_character_set("utf-8")

#endif

#include "logindig.h"
#include "ui_logindig.h"
#include<QtNetwork/QNetworkAccessManager>
#include<QtNetwork/QNetworkRequest>
#include<QtNetwork/QNetworkReply>
#include<qmessagebox.h>
#include<QByteArray>

LoginDig::LoginDig(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDig)
{
    ui->setupUi(this);
}

LoginDig::~LoginDig()
{
    delete ui;
}

void LoginDig::check(QNetworkReply *reply){//解析响应包
    extern QString token;
    ui->commandLinkButton->setEnabled(true);
    if(reply->error() == QNetworkReply::NoError)
        {
            QByteArray bytes = reply->readAll();  //获取字节
            QString result(bytes);  //转化为字符串
            qDebug()<<"MeowServer-1.1 reply:"<<result;
            if(result.section("\r\n",0,0).toStdString()=="done"){
                token=result.section("\r\n",1,1);
                qDebug()<<"MeowClient-1.1 get token:"<<token;
                reply->deleteLater();//销毁回复
                accept();
            }else{
                QMessageBox::warning(this, "警告！",//注册错误
                                     "向喵网络注册失败，反馈信息："+result,
                                     QMessageBox::Yes);
                reply->deleteLater();//销毁回复
            }
        }
        else
        {
            //处理错误
             qDebug()<<"喵网络连接失败";
             QMessageBox::warning(this, "警告！",
                                  "不能连接到指定的喵网络",
                                  QMessageBox::Yes);
             reply->deleteLater();//销毁回复
        }
}

void LoginDig::on_commandLinkButton_clicked()
{
    extern QString ip;
    extern QString pswd;
    ui->commandLinkButton->setEnabled(false);
    ip=ui->Eip->text();
    pswd=ui->Epswd->text();//收集登录信息
    qDebug()<<"MeowClient-1.1 pswd:"<<pswd;

    QNetworkAccessManager *login=new QNetworkAccessManager(this);//发送注册包
    connect(login, SIGNAL(finished(QNetworkReply*)),this, SLOT(check(QNetworkReply*)));
    QNetworkRequest send(QUrl("http://"+ip+"/login/"));
    send.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
    send.setHeader(QNetworkRequest::UserAgentHeader,"MeowClient-1.1");//设置文件头
    QByteArray data;
    data.append("PSWD="+pswd);//密码
    login->post(send,data);
    qDebug()<<"Registing to MeowServer-1.1";
}
