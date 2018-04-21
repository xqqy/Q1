#if _MSC_VER >= 1600

#pragma execution_character_set("utf-8")

#endif

#include <QApplication>
#include "logindig.h"
#include "stulogin.h"
#include "sturecord.h"
#include<QTcpServer>
#include<qmessagebox.h>
#include<QTcpSocket>
#include"aes/qaeswrap.h"
#include<http/MeowHttpd_nossl_nolocal.h>
#include<QHostAddress>
#include<QDateTime>

QString ip;//服务器主机
QString pswd;//安全密钥
QString token;//随机令牌
QString que;//问题
QDateTime endofexam;//考试结束时间
int count;//考试次数限制
int now;//考试时间提醒

void running();
void restart();

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
        LoginDig dig;                        // 建立自己新建的LoginDlg类的实例dig
        qDebug()<<"MeowClient-1.1 Login start";
        if(dig.exec() == QDialog::Accepted){
            qDebug()<<"MeowClient-1.1 Login step1 done";
            qDebug()<<"Forward address:"<<ip;
            running();
        }else
            return 0;
}

void running(){
    stulogin stul;
       if(stul.exec() == QDialog::Accepted){
        qDebug()<<"MeowClient-1.1 Login step2 done";
        qDebug()<<"Question:"<<que;
        endofexam=QDateTime::currentDateTime().addSecs(600);
        now=600;
		count = 3;
		sturecord stur;
        if(stur.exec() == QDialog::Accepted){
            qDebug()<<"MeowClient-1.1 reLogin step2";
            running();
        }else{
            restart();
        }
       }else{
           QMessageBox::warning(NULL,"警告","请不要关闭本窗口，结束进程请在学生ID处输入$#$#end#$#$");
           running();
       }
}

void restart(){
    QMessageBox::warning(NULL,"警告","请不要关闭本窗口，完成考试请点击提交键");
    sturecord stur;
    if(stur.exec() == QDialog::Accepted){
        qDebug()<<"MeowClient-1.1 reLogin step2";
        running();
    }else{
        restart();
    }
}
