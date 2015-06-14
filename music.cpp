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
