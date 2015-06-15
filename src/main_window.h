#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

// #include <QFileDialog>
#include <QMediaPlayer>
#include <QMediaPlaylist>
// #include <QMediaMetaData>

namespace Ui {
  class MainWindow;
}

/**
 * @brief Janela principal da aplicação.
 */
class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();

private slots:
  void setLibrary();
  void setCurrentData();

  void on_sliderProgress_sliderMoved(int position);
  void on_sliderVolume_sliderMoved(int position);
  void on_positionChanged(qint64 position);
  void on_durationChanged(qint64 position);
  void on_playPause_clicked();
  void on_pushButton_4_clicked();
  void on_pushButton_2_clicked();
  void on_shuffle_clicked();
  void on_repeat_clicked();
  void on_listWidget_doubleClicked(const QModelIndex &index);

private:
  void setUpPlayer();

private:
  Ui::MainWindow* ui;
  QMediaPlayer* player;
  QMediaPlaylist* nowPlaying;
};

#endif // MAINWINDOW_H