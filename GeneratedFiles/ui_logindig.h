/********************************************************************************
** Form generated from reading UI file 'logindig.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINDIG_H
#define UI_LOGINDIG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_LoginDig
{
public:
    QLabel *Lip;
    QLabel *Lpswd;
    QLineEdit *Eip;
    QLineEdit *Epswd;
    QFrame *line;
    QLabel *label;
    QCommandLinkButton *commandLinkButton;

    void setupUi(QDialog *LoginDig)
    {
        if (LoginDig->objectName().isEmpty())
            LoginDig->setObjectName(QStringLiteral("LoginDig"));
        LoginDig->resize(400, 300);
        Lip = new QLabel(LoginDig);
        Lip->setObjectName(QStringLiteral("Lip"));
        Lip->setGeometry(QRect(30, 90, 91, 20));
        Lpswd = new QLabel(LoginDig);
        Lpswd->setObjectName(QStringLiteral("Lpswd"));
        Lpswd->setGeometry(QRect(30, 170, 66, 20));
        Eip = new QLineEdit(LoginDig);
        Eip->setObjectName(QStringLiteral("Eip"));
        Eip->setGeometry(QRect(50, 110, 271, 28));
        Eip->setEchoMode(QLineEdit::Normal);
        Epswd = new QLineEdit(LoginDig);
        Epswd->setObjectName(QStringLiteral("Epswd"));
        Epswd->setGeometry(QRect(50, 190, 271, 28));
        Epswd->setEchoMode(QLineEdit::PasswordEchoOnEdit);
        line = new QFrame(LoginDig);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(0, 70, 351, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        label = new QLabel(LoginDig);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 321, 71));
        QFont font;
        font.setPointSize(40);
        label->setFont(font);
        commandLinkButton = new QCommandLinkButton(LoginDig);
        commandLinkButton->setObjectName(QStringLiteral("commandLinkButton"));
        commandLinkButton->setGeometry(QRect(319, 260, 81, 41));

        retranslateUi(LoginDig);

        QMetaObject::connectSlotsByName(LoginDig);
    } // setupUi

    void retranslateUi(QDialog *LoginDig)
    {
        LoginDig->setWindowTitle(QApplication::translate("LoginDig", "\347\231\273\345\275\225\345\210\260\346\234\215\345\212\241\345\231\250", nullptr));
        Lip->setText(QApplication::translate("LoginDig", "\346\234\215\345\212\241\345\231\250IP\345\234\260\345\235\200", nullptr));
        Lpswd->setText(QApplication::translate("LoginDig", "\345\256\211\345\205\250\345\257\206\347\240\201", nullptr));
        label->setText(QApplication::translate("LoginDig", "\347\231\273\345\275\225\345\210\260\346\234\215\345\212\241\345\231\250", nullptr));
        commandLinkButton->setText(QApplication::translate("LoginDig", "\347\241\256\345\256\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginDig: public Ui_LoginDig {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINDIG_H
