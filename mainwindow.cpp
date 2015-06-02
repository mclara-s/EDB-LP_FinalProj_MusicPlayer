#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtMultimedia>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    player = new QMediaPlayer(this);

    connect(player, &QMediaPlayer::positionChanged, this, &MainWindow::on_positionChanged);
    connect(player, &QMediaPlayer::durationChanged, this, &MainWindow::on_durationChanged);
    connect(player, &QMediaPlayer::mediaStatusChanged, this, &MainWindow::setCurrentData);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_sliderProgress_sliderMoved(int position)
{
    player->setPosition(position);
}

void MainWindow::on_sliderVolume_sliderMoved(int position)
{
    player->setVolume(position);
}

void MainWindow::on_positionChanged(qint64 position)
{
    ui->sliderProgress->setValue(position);
    int time = position/1000;
    QString duration, min, sec;
    min.setNum(time/60);
    sec.setNum(time%60);
    duration = min + ":" + sec;
    ui->labelDurationI->setText(duration);


}

void MainWindow::on_durationChanged(qint64 position)
{
    int time;
    ui->sliderProgress->setMaximum(position);
    time = position/1000;
    QString duration, min, sec;
    min.setNum(time/60);
    sec.setNum(time%60);
    duration = min + ":" + sec;
    ui->labelDuration->setText(duration);
}
void MainWindow::on_playPause_toggled(bool checked)
{
    //SE TIVER TOCANDO
    //if (player->state() == 1){
      //  player->pause();
    //}
    //SE NAO TIVER TOCANDO
    //else{
       // player->setMedia(QUrl::fromLocalFile("/home/maria/Música/18 Hot Kiss (Juliette & The Licks).mp3"));
        //player->play();
        //qDebug() << player->errorString();
    //}
}

void MainWindow::setCurrentData(){
    //qDebug() << "Chamou setCurrentData\n";
    if (player->state() == 1){
        if (player->isMetaDataAvailable()){
           ui->labelTitle->setText(player->metaData(QMediaMetaData::Title).toString());
           ui->labelAlbum->setText(player->metaData(QMediaMetaData::AlbumTitle).toString());
           ui->labelArtist->setText(player->metaData(QMediaMetaData::AlbumArtist).toString());
           //QStringList Authors = player->metaData(QMediaMetaData::Author).toStringList();
           //QString test;
           //test.setNum(Authors.count());
           //ui->labelArtist->setText(test);
        }
        else
          qDebug() << "Metadata nao disp\n";
    }

}

void MainWindow::on_playPause_clicked()
{
    //if (player->state() == 1)
      //  player->pause();
    //else if (player->state() == 2)
      //  player->
    //else{
//        if(player->state() == )
        player->setMedia(QUrl::fromLocalFile("/home/maria/Música/18 Hot Kiss (Juliette & The Licks).mp3"));
        player->play();
        qDebug() << player->errorString();
    //}
}
