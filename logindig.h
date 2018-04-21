#if _MSC_VER >= 1600

#pragma execution_character_set("utf-8")

#endif

#ifndef LOGINDIG_H
#define LOGINDIG_H


#include <QDialog>
#include<QtNetwork/QNetworkReply>


namespace Ui {
class LoginDig;
}

class LoginDig : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDig(QWidget *parent = 0);
    ~LoginDig();

private slots:
    void check(QNetworkReply *reply);

    void on_commandLinkButton_clicked();

private:
    Ui::LoginDig *ui;
};

#endif // LOGINDIG_H
