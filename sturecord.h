#if _MSC_VER >= 1600

#pragma execution_character_set("utf-8")

#endif

#ifndef STURECORD_H
#define STURECORD_H

#include <QDialog>
#include<QAudio>
#include<QMediaPlayer>
#include<QNetworkReply>

namespace Ui {
class sturecord;
}

class sturecord : public QDialog
{
    Q_OBJECT

public:
    explicit sturecord(QWidget *parent = 0);
    ~sturecord();

private slots:
    void stopRecording();
    void play(QByteArray doc);
    void inerst();
    void on_pushButton_clicked();

    void on_listWidget_currentRowChanged(int currentRow);

    void on_pushButton_2_clicked();

    void playerstate(QMediaPlayer::State state);

    void on_commandLinkButton_2_clicked();

    void check(QNetworkReply *reply);

    void done();
    void timerDone();
    void init();
	void countlow();

private:
    Ui::sturecord *ui;


};

#endif // STURECORD_H
