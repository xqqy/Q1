#if _MSC_VER >= 1600

#pragma execution_character_set("utf-8")

#endif

#ifndef STULOGIN_H
#define STULOGIN_H

#include <QDialog>
#include<QtNetwork/QNetworkReply>


namespace Ui {
class stulogin;
}

class stulogin : public QDialog
{
    Q_OBJECT

public:
    explicit stulogin(QWidget *parent = 0);
    ~stulogin();

private slots:

    void check(QNetworkReply *reply);

    void on_commandLinkButton_clicked();

private:
    Ui::stulogin *ui;
};

#endif // STULOGIN_H
