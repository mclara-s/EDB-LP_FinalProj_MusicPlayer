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

QList<Music>& Playlist::search(QString& term)
{
  QList<Music>::const_iterator itr;
  auto results = new QList<Music>();

  for (itr = musics->begin(); itr != musics->end(); ++itr)
  {
    auto music = *itr;

    if (term == music.getName())
    {
      results->push_back(music);
    }
  }

  return *results;
}

Playlist& Playlist::fromFile(QUrl url)
{
  auto playlist = new Playlist(url.toString());

  playlist->load(url, Playlist::FORMAT);

  return *playlist;
}