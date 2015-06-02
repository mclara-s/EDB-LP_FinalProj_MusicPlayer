#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMediaPlayer>
#include <QMediaMetaData>

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
    void on_sliderProgress_sliderMoved(int position);

    void on_sliderVolume_sliderMoved(int position);

    void on_positionChanged(qint64 position);

    void on_durationChanged(qint64 position);

    void on_playPause_toggled(bool checked);

    void setCurrentData();

    void on_playPause_clicked();

private:
    Ui::MainWindow *ui;
    QMediaPlayer *player;
};

#endif // MAINWINDOW_H
