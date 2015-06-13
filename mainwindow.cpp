#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtMultimedia>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    player = new QMediaPlayer(this);
    nowPlaying = new QMediaPlaylist();
    myLib = new MusicLibrary();
    player->setPlaylist(nowPlaying);
    if (myLib->mediaCount() == 0)
      createLibrary();

    setLibrary();
    nowPlaying->setCurrentIndex(0);


    connect(player, &QMediaPlayer::positionChanged, this, &MainWindow::on_positionChanged);
    connect(player, &QMediaPlayer::durationChanged, this, &MainWindow::on_durationChanged);
    connect(player, &QMediaPlayer::mediaStatusChanged, this, &MainWindow::setCurrentData);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::createLibrary(){
    directory = QFileDialog::getExistingDirectory(this,tr("Select dir for files to import"));
    myLib->setContent(directory);
}

void MainWindow::setLibrary(){
    QStringList headers;
    headers << "Nome do arquivo" << "Musica" << "Artista" << "Album" << "Tempo" << "Genero";
    ui->allSongsTable->setHorizontalHeaderLabels(headers);
    ui->listWidget->addItems(myLib->getMusicsList());
    nowPlaying->addMedia(myLib->getContentMedia());
    ui->listWidget->setCurrentRow(nowPlaying->currentIndex() != -1? nowPlaying->currentIndex():0);
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

void MainWindow::setCurrentData(){
    QPixmap album;
    if (player->state() == 1){
        if (player->isMetaDataAvailable()){
           ui->labelTitle->setText(player->metaData(QMediaMetaData::Title).toString());
           ui->labelAlbum->setText(player->metaData(QMediaMetaData::AlbumTitle).toString());
           ui->labelArtist->setText(player->metaData(QMediaMetaData::AlbumArtist).toString());
//           QVariant v = player->metaData(QMediaMetaData::CoverArtUrlLarge);
//           album.convertFromImage(
//          album.convertFromImage(player->metaData(QMediaMetaData::CoverArtImage).value<QImage>());
//           ui->albumImage->setPixmap(album);
        }
        else
          qDebug() << "Metadata nao disp\n";
    }
    ui->listWidget->setCurrentRow(nowPlaying->currentIndex());

}

void MainWindow::on_playPause_clicked()
{
    if (player->state() != 1){
        player->play();
        ui->playPause->setText("Pause");
        qDebug() << player->errorString();
    }

    else{
        player->pause();
        ui->playPause->setText("Play");
    }

}

void MainWindow::on_pushButton_4_clicked()
{
    nowPlaying->next();
    ui->listWidget->setCurrentRow(nowPlaying->currentIndex());
}

void MainWindow::on_pushButton_2_clicked()
{
    nowPlaying->previous();
    ui->listWidget->setCurrentRow(nowPlaying->currentIndex());
}

void MainWindow::on_shuffle_clicked()
{
    if (!nowPlaying->playbackMode() == QMediaPlaylist::Random)
        nowPlaying->setPlaybackMode(QMediaPlaylist::Random);

    else
        nowPlaying->setPlaybackMode(QMediaPlaylist::Sequential);
}

void MainWindow::on_repeat_clicked()
{
    /*if (!nowPlaying->playbackMode() == QMediaPlaylist::CurrentItemInLoop)
        nowPlaying->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);
    else
        nowPlaying->setPlaybackMode(QMediaPlaylist::CurrentItemOnce);
        */
}

void MainWindow::on_listWidget_doubleClicked(const QModelIndex &index)
{
    nowPlaying->setCurrentIndex(index.row());
    player->play();
}
