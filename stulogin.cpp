#if _MSC_VER >= 1600

#pragma execution_character_set("utf-8")

#endif

#include "stulogin.h"
#include "ui_stulogin.h"
#include<QtNetwork/QNetworkAccessManager>
#include<QtNetwork/QNetworkRequest>
#include<QtNetwork/QNetworkReply>
#include<qmessagebox.h>
#include<QByteArray>

stulogin::stulogin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::stulogin)
{
    ui->setupUi(this);
}

stulogin::~stulogin()
{
    delete ui;
}

void stulogin::check(QNetworkReply *reply){
    extern QString que;
    ui->commandLinkButton->setEnabled(true);
    if(reply->error() == QNetworkReply::NoError)
        {
            QByteArray bytes = reply->readAll();  //获取字节
            QString result(bytes);  //转化为字符串
            qDebug()<<"MeowServer-1.1 reply:"<<result;
            if(result.section("\r\n",0,0).toStdString()=="done"){
                QMessageBox::information(this,"注册成功",result.section("\r\n",1,1),QMessageBox::Yes);
                que=result.section("\r\n",2,2);
                qDebug()<<"MeowClient-1.1 get que:"<<que;
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

void stulogin::on_commandLinkButton_clicked()
{
    extern QString ip;
    extern QString token;
    ui->commandLinkButton->setEnabled(false);
    if(ui->lineEdit->text()=="$#$#end#$#$"){
        exit(0);
    }

    if(ui->lineEdit->text()=="" || ui->lineEdit_2->text()==""){
        QMessageBox::warning(this,"错误","请输入全部信息");
    }else{
        QNetworkAccessManager *stu=new QNetworkAccessManager(this);//发送注册包
        connect(stu, SIGNAL(finished(QNetworkReply*)),this, SLOT(check(QNetworkReply*)));
        QNetworkRequest send(QUrl("http://"+ip+"/stu/"));
        send.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
        send.setHeader(QNetworkRequest::UserAgentHeader,"MeowClient-1.1");//设置文件头
        QByteArray data;
        data.append("TOKEN="+token.toUtf8());//令牌
        data.append("&UID="+ui->lineEdit->text().toUtf8());//UID
        data.append("&NAME="+ui->lineEdit_2->text().toUtf8());//姓名
        stu->post(send,data);
        qDebug()<<"Student login to MeowServer-1.1";
    }

}
