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

int Playlist::count()
{
  return musics->size();
}

QString Playlist::getName()
{
  return name;
}

void Playlist::addMusic(Music& music)
{
  musics->push_back(music);
  addMedia(music.getContent());
}

const Music& Playlist::music(int index)
{
  return musics->at(index);
}

Playlist& Playlist::fromFile(QUrl url)
{
  auto playlist = new Playlist(url.toString());

  playlist->load(url, Playlist::FORMAT);

  return *playlist;
}