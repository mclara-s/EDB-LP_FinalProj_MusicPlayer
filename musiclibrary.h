#ifndef MUSICLIBRARY_H
#define MUSICLIBRARY_H

#include <QMediaMetaData>
#include <QMediaPlaylist>
#include <QDir>

class MusicLibrary: public QMediaPlaylist
{
    QList<QMediaContent> contentList;
    //QMediaPlaylist *content;
    QString sourceDir;
    
public:
    MusicLibrary();
    ~MusicLibrary();
    
    void setDir();
    void setContent(QString);
    void setContentList();
    QStringList getMusicsList();
    QList<QMediaContent> getContentMedia();
    QMediaPlaylist* getPlaylist();
    bool isEmpty();
};

#endif // MUSICLIBRARY_H
