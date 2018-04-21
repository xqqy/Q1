/********************************************************************************
** Form generated from reading UI file 'stulogin.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STULOGIN_H
#define UI_STULOGIN_H

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

class Ui_stulogin
{
public:
    QLabel *label;
    QFrame *line;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QCommandLinkButton *commandLinkButton;
    QLineEdit *lineEdit_2;
    QLabel *label_3;

    void setupUi(QDialog *stulogin)
    {
        if (stulogin->objectName().isEmpty())
            stulogin->setObjectName(QStringLiteral("stulogin"));
        stulogin->resize(400, 300);
        label = new QLabel(stulogin);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 221, 81));
        QFont font;
        font.setPointSize(40);
        label->setFont(font);
        line = new QFrame(stulogin);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(0, 80, 391, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        lineEdit = new QLineEdit(stulogin);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(70, 140, 231, 28));
        label_2 = new QLabel(stulogin);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(60, 110, 41, 31));
        QFont font1;
        font1.setPointSize(15);
        label_2->setFont(font1);
        commandLinkButton = new QCommandLinkButton(stulogin);
        commandLinkButton->setObjectName(QStringLiteral("commandLinkButton"));
        commandLinkButton->setGeometry(QRect(319, 260, 81, 41));
        lineEdit_2 = new QLineEdit(stulogin);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(70, 210, 231, 28));
        label_3 = new QLabel(stulogin);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(60, 180, 41, 31));
        label_3->setFont(font1);
        QWidget::setTabOrder(lineEdit, lineEdit_2);
        QWidget::setTabOrder(lineEdit_2, commandLinkButton);

        retranslateUi(stulogin);

        QMetaObject::connectSlotsByName(stulogin);
    } // setupUi

    void retranslateUi(QDialog *stulogin)
    {
        stulogin->setWindowTitle(QApplication::translate("stulogin", "\345\255\246\347\224\237\347\231\273\345\275\225", nullptr));
        label->setText(QApplication::translate("stulogin", "\345\255\246\347\224\237\347\231\273\345\275\225", nullptr));
        label_2->setText(QApplication::translate("stulogin", "\345\255\246\345\217\267", nullptr));
        commandLinkButton->setText(QApplication::translate("stulogin", "\347\241\256\345\256\232", nullptr));
        lineEdit_2->setText(QString());
        label_3->setText(QApplication::translate("stulogin", "\345\247\223\345\220\215", nullptr));
    } // retranslateUi

};

namespace Ui {
    class stulogin: public Ui_stulogin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STULOGIN_H
