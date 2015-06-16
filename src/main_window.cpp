#include "main_window.h"
#include "ui_main_window.h"

#include <QtMultimedia>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::MainWindow)
{
  ui->setupUi(this);

  setupMusicsView();
  setupAlbunsView();
  setupArtistsView();
}

MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::setupMusicsView()
{
  QStringList headers;

  headers << "Musica" << "Artista" << "Album" << "Tempo" << "Genero";

  ui->musicsView->setColumnCount(5);
  ui->musicsView->setHorizontalHeaderLabels(headers);
}

void MainWindow::setupAlbunsView()
{
  QStringList headers;

  headers << "Album" << "Genero" << "Ano" << "Faixas" <<  "Artista";

  ui->albunsView->setColumnCount(5);
  ui->albunsView->setHorizontalHeaderLabels(headers);
}

void MainWindow::setupArtistsView()
{
  QStringList headers;

  headers << "Artista" << "Genero" << "Albuns";

  ui->artistsView->setColumnCount(3);
  ui->artistsView->setHorizontalHeaderLabels(headers);
}

// Private Slots
// =============================================================================
void MainWindow::on_musicsButton_clicked()
{
  ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_albunsButton_clicked()
{
  ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_artistsButton_clicked()
{
  ui->stackedWidget->setCurrentIndex(2);
}