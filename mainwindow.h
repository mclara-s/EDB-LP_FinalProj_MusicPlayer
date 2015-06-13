#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMediaPlayer>
#include <QMediaMetaData>
#include <QMediaPlaylist>
#include <QFileDialog>
#include "musiclibrary.h"
#include <QStandardItem>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void createLibrary();

    void setLibrary();

    void on_sliderProgress_sliderMoved(int position);

    void on_sliderVolume_sliderMoved(int position);

    void on_positionChanged(qint64 position);

    void on_durationChanged(qint64 position);

    void setCurrentData();

    void on_playPause_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_2_clicked();

    void on_shuffle_clicked();

    void on_repeat_clicked();

    void on_listWidget_doubleClicked(const QModelIndex &index);

private:
    Ui::MainWindow *ui;
    QMediaPlayer *player;
    QMediaPlaylist *nowPlaying;
    QString directory;
    MusicLibrary *myLib;
};

#endif // MAINWINDOW_H
