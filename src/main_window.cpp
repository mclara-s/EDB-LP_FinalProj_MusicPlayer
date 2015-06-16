#include "main_window.h"

#include "ui_main_window.h"
#include "music.h"
#include "application.h"

MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent), ui(new Ui::MainWindow)
{
  ui->setupUi(this);

  player = new QMediaPlayer(this);

  setupMusicsView();
  setupAlbunsView();
  setupArtistsView();

  connect(ui->searchBox, &QLineEdit::returnPressed, this, &MainWindow::on_returnPressed);
  connect(player, &QMediaPlayer::positionChanged, this, &MainWindow::on_positionChanged);
  connect(player, &QMediaPlayer::durationChanged, this, &MainWindow::on_durationChanged);
}

MainWindow::~MainWindow()
{
  delete ui;
  delete player;
}

void MainWindow::setupMusicsView()
{
  QStringList headers;
  auto app = (Application*) qApp;

  headers << "Musica" << "Artista" << "Album" << "Tempo" << "Genero";

  ui->musicsView->setColumnCount(5);
  ui->musicsView->setRowCount(app->library->count());
  ui->musicsView->setHorizontalHeaderLabels(headers);

  // Lista todas as músicas da biblioteca.
  for (int i = 0; i < app->library->count(); ++i)
  {
    auto music = app->library->music(i);

    ui->musicsView->setItem(i, 0, new QTableWidgetItem(music.getName()));
    ui->musicsView->setItem(i, 1, new QTableWidgetItem(music.getArtist()));
    ui->musicsView->setItem(i, 2, new QTableWidgetItem(music.getAlbum()));
    ui->musicsView->setItem(i, 3, new QTableWidgetItem(music.getDuration().toString()));
    ui->musicsView->setItem(i, 4, new QTableWidgetItem(music.getGenre()));
  }
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

void MainWindow::on_playButton_clicked()
{
  auto app = (Application*) qApp;

  switch (player->state())
  {
    case QMediaPlayer::PlayingState:
      ui->playButton->setText("Play");
      player->pause();
      break;
    case QMediaPlayer::PausedState:
      ui->playButton->setText("Pause");
      player->play();
      break;
    default:
      ui->playButton->setText("Pause");
      player->setPlaylist(app->library);
      ui->musicsView->setCurrentCell(0, 0);
      app->library->setCurrentIndex(0);
      player->play();
  }
}

void MainWindow::on_stopButton_clicked()
{
  player->stop();
}

void MainWindow::on_shuffleButton_clicked()
{
  auto app = (Application*) qApp;

  if (app->library->playbackMode() != QMediaPlaylist::Random)
    app->library->setPlaybackMode(QMediaPlaylist::Random);
  else
    app->library->setPlaybackMode(QMediaPlaylist::Sequential);
}

void MainWindow::on_repeatButton_clicked()
{
  auto app = (Application*) qApp;

  if (app->library->playbackMode() != QMediaPlaylist::CurrentItemInLoop)
    app->library->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);
  else
    app->library->setPlaybackMode(QMediaPlaylist::Sequential);
}

void MainWindow::on_prevButton_clicked()
{
  auto app = (Application*) qApp;

  app->library->previous();
  ui->musicsView->setCurrentCell(app->library->currentIndex(), 0);
}

void MainWindow::on_nextButton_clicked()
{
  auto app = (Application*) qApp;

  app->library->next();
  ui->musicsView->setCurrentCell(app->library->currentIndex(), 0);
}

void MainWindow::on_returnPressed()
{
  qDebug() << "initializing search...";

  auto app = (Application*) qApp;
  auto term = ui->searchBox->text();

  app->library->search(term);

  qDebug() << term;
  qDebug() << "finalizing search...";
}

void MainWindow::on_positionChanged(qint64 position)
{
  auto duration = new Duration(position / 1000);

  ui->musicProgressBar->setValue(position);
  ui->startLabel->setText(duration->toString());
}

void MainWindow::on_durationChanged(qint64 position)
{
  auto duration = new Duration(position / 1000);

  ui->musicProgressBar->setMaximum(position);
  ui->endLabel->setText(duration->toString());
}