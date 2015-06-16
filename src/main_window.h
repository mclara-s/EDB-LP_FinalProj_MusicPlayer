#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
  class MainWindow;
}

/**
 * @brief Janela principal da aplicação.
 *
 * Esta classe atua como um controller para a aplicação, recebendo todos os eventos
 * dos widgets e repassando para as classes responsáveis por tratar tais eventos.
 */
class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();
private:
  void setupMusicsView();
  void setupAlbunsView();
  void setupArtistsView();
private slots:
  void on_musicsButton_clicked();
  void on_albunsButton_clicked();
  void on_artistsButton_clicked();
private:
  Ui::MainWindow* ui;
};

#endif