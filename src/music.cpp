#include "music.h"

Music::Music(QString n, int d, QUrl u)
  : QMediaContent(u), name(n), duration(new Duration(d)) {}

Music::~Music()
{
  if (duration)
    delete duration;
}

QString Music::getName()
{
  return name;
}

Duration& Music::getDuration()
{
  return *duration;
}

Music& Music::fromUrl(QUrl url)
{
  auto music = new Music(url.fileName(), 0, url);

  return *music;
}