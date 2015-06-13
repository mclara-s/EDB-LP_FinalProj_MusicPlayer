#include "musiclibrary.h"

MusicLibrary::MusicLibrary()
{
    load(QUrl::fromLocalFile("MyLibrary.m3u"), "m3u");
    if (mediaCount() != 0)
        setContentList();
}

MusicLibrary::~MusicLibrary()
{

}

void MusicLibrary::setContent(QString directory){
    if(directory.isEmpty())
            return;

    QDir dir(directory);
    QStringList files = dir.entryList(QStringList() << "*.mp3",QDir::Files);
    QString f;
    for(int i = 0; i < files.size(); i++)
    {
        f = files.at(i);
        contentList.push_back(QUrl::fromLocalFile(dir.path()+"/" + f));
        qDebug() << dir.path()+"/"+f;
    }
    addMedia(contentList);
    save(QUrl::fromLocalFile("MyLibrary.m3u"), "m3u");
}

void MusicLibrary::setContentList(){
    for (int i = 0; i < mediaCount(); i++)
            contentList << media(i);
}

QStringList MusicLibrary::getMusicsList(){
    QStringList fileNames;
    QString f;
    for(int i = 0; i < contentList.size(); i++)
    {
        f = contentList.at(i).canonicalUrl().toString();
        QFileInfo fi(f);
        fileNames << fi.fileName();
    }
    return fileNames;
}

QList<QMediaContent> MusicLibrary::getContentMedia(){
    return contentList;
}

