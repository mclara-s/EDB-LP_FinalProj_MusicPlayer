#ifndef MUSIC_LIBRARY_H
#define MUSIC_LIBRARY_H

#include <QDir>
#include <QUrl>
#include <QString>

#include "playlist.h"

class MusicLibrary : public Playlist
{
public:
  /**
   * Inicializa um objeto MusicLibrary com o nome "Músicas".
   */
  MusicLibrary()
    : Playlist("Músicas") {}

  /**
   * Cria e inicializa um MusicLibrary com músicas carregadas a partir do
   * diretório indicado.
   *
   * @param url Caminho para pasta de onde carregar as músicas.
   * @returns Um objeto MusicLibrary com as músicas encontradas no diretório dir.
   */
  static MusicLibrary* fromDirectory(QString url)
  {
    auto dir = QDir(url);
    auto file_types = QStringList();
    auto library = new MusicLibrary();

    if (!dir.exists())
      throw "O diretório informado não existe!";

    file_types << "*.mp3";

    QStringList::const_iterator itr;
    auto files = dir.entryList(file_types, QDir::Files);

    for (itr = files.begin(); itr != files.end(); ++itr)
    {
      qDebug() << *itr;

      auto path = dir.filePath(*itr);
      auto url = QUrl::fromLocalFile(path);

      library->addMusic(Music::fromUrl(url));
    }

    return library;
  }
};

#endif