#include "music.h"

#include <QDebug>
#include <fileref.h>

Music::Music(QString n, QString a, QString ar, QString g, int d, QMediaContent* c)
  : name(n), genre(g), album(a), artist(ar), duration(new Duration(d)), content(c) {}

Music::~Music()
{
  if (duration)
    delete duration;
}

QString Music::getName()
{
  return name;
}

QString Music::getGenre()
{
  return genre;
}

QString Music::getAlbum()
{
  return album;
}

QString Music::getArtist()
{
  return artist;
}

Duration& Music::getDuration()
{
  return *duration;
}

QMediaContent& Music::getContent()
{
  return *content;
}

Music& Music::fromUrl(QUrl url)
{
  TagLib::FileRef metadata(url.path().toStdString().c_str());

  auto content = new QMediaContent(url);
  auto tag = metadata.tag();
  auto music = new Music(
    tag->title().toCString(),
    tag->album().toCString(),
    tag->artist().toCString(),
    tag->genre().toCString(),
    (int) metadata.audioProperties()->length(),
    content
  );

  return *music;
}