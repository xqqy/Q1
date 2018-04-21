/********************************************************************************
** Form generated from reading UI file 'sturecord.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STURECORD_H
#define UI_STURECORD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_sturecord
{
public:
    QLabel *label;
    QFrame *line;
    QProgressBar *progressBar;
    QCommandLinkButton *commandLinkButton_2;
    QPushButton *pushButton;
    QLabel *label_3;
    QPushButton *pushButton_2;
    QListWidget *listWidget;
    QLabel *label_4;

    void setupUi(QWidget *sturecord)
    {
        if (sturecord->objectName().isEmpty())
            sturecord->setObjectName(QStringLiteral("sturecord"));
        sturecord->resize(400, 300);
        label = new QLabel(sturecord);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 111, 61));
        QFont font;
        font.setPointSize(40);
        label->setFont(font);
        line = new QFrame(sturecord);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(0, 60, 401, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        progressBar = new QProgressBar(sturecord);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(20, 130, 361, 23));
        progressBar->setToolTipDuration(-1);
        progressBar->setLayoutDirection(Qt::LeftToRight);
        progressBar->setAutoFillBackground(false);
        progressBar->setStyleSheet(QLatin1String("QProgressBar {\n"
"color:rgb(255, 255, 255);\n"
"text-align:center\n"
"}"));
        progressBar->setMaximum(600);
        progressBar->setValue(600);
        progressBar->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        progressBar->setTextVisible(true);
        progressBar->setInvertedAppearance(true);
        progressBar->setTextDirection(QProgressBar::BottomToTop);
        commandLinkButton_2 = new QCommandLinkButton(sturecord);
        commandLinkButton_2->setObjectName(QStringLiteral("commandLinkButton_2"));
        commandLinkButton_2->setGeometry(QRect(319, 260, 81, 41));
        commandLinkButton_2->setLayoutDirection(Qt::LeftToRight);
        pushButton = new QPushButton(sturecord);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(240, 160, 91, 41));
        label_3 = new QLabel(sturecord);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(70, 80, 271, 20));
        label_3->setAlignment(Qt::AlignCenter);
        pushButton_2 = new QPushButton(sturecord);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setEnabled(false);
        pushButton_2->setGeometry(QRect(240, 220, 91, 41));
        listWidget = new QListWidget(sturecord);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(10, 160, 191, 131));
        label_4 = new QLabel(sturecord);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(20, 110, 81, 16));
        QWidget::setTabOrder(pushButton, listWidget);
        QWidget::setTabOrder(listWidget, pushButton_2);
        QWidget::setTabOrder(pushButton_2, commandLinkButton_2);

        retranslateUi(sturecord);

        QMetaObject::connectSlotsByName(sturecord);
    } // setupUi

    void retranslateUi(QWidget *sturecord)
    {
        sturecord->setWindowTitle(QApplication::translate("sturecord", "\345\275\225\345\210\266", nullptr));
        label->setText(QApplication::translate("sturecord", "\345\275\225\345\210\266", nullptr));
        progressBar->setFormat(QApplication::translate("sturecord", "\345\211\251\344\275\231\347\247\222\346\225\260%v", nullptr));
        commandLinkButton_2->setText(QApplication::translate("sturecord", "\346\217\220\344\272\244", nullptr));
        pushButton->setText(QApplication::translate("sturecord", "\345\275\225\345\210\266", nullptr));
        label_3->setText(QApplication::translate("sturecord", "\350\257\225\351\242\230", nullptr));
        pushButton_2->setText(QApplication::translate("sturecord", "\346\222\255\346\224\276", nullptr));
        label_4->setText(QApplication::translate("sturecord", "\345\211\251\344\275\231\346\254\241\346\225\260\357\274\2323", nullptr));
    } // retranslateUi

};

namespace Ui {
    class sturecord: public Ui_sturecord {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STURECORD_H
