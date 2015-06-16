#ifndef APP_H
#define APP_H

#include <QList>
#include <QApplication>

#include "music_library.h"
#include "playlist_library.h"

class Application : public QApplication
{
public:
  Application(int & argc, char ** argv)
    : QApplication(argc, argv)
  {
    auto home = QDir::home();
    home.setPath("Music");

    playlist_library = new PlaylistLibrary();
    library = MusicLibrary::fromDirectory("/Users/diegotoral/Music");
  }

  /**
   * Biblioteca de músicas.
   *
   * Armazena todas as músicas carregadas na aplicação.
   */
  MusicLibrary *library;

  /**
   * Biblioteca de playlist.
   *
   * Registro de todas as playlist disponíveis na aplicação.
   */
  PlaylistLibrary *playlist_library;
};

#endif