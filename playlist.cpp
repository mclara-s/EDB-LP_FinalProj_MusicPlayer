#include "playlist.h"

const char Playlist::FORMAT[] = "m3u";

Playlist::Playlist(QString n)
  : name(n), musics(new QList<Music>()) {}

Playlist::Playlist(QString n, QList<Music>* m)
  : name(n), musics(m) {}

Playlist::~Playlist()
{
  if (musics)
    delete musics;
}

QString Playlist::getName()
{
  return name;
}

Playlist& Playlist::fromFile(QUrl url)
{
  auto playlist = new Playlist(url.toString());

  playlist->load(url, Playlist::FORMAT);

  return *playlist;
}
