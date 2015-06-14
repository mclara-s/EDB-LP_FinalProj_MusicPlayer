#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <QUrl>
#include <QList>
#include <QString>
#include <QMediaPlaylist>

#include "music.h"

/**
 * @brief Uma playlist.
 *
 * A classe Playlist provê funcionalidades de uma playlist.
 */
class Playlist : public QMediaPlaylist
{
public:
  /**
   * Formato de arquivo de playlist.
   */
  static const char FORMAT[];

  /**
   * Inicializa um objeto Playlist com o nome informado.
   *
   * @param n Nome do playlist.
   */
  Playlist(QString);

  /**
   * Inicializa uma playlist com o nome e músicas informadas.
   *
   * @param n Nome da playlist.
   * @param m Músicas da playlist.
   */
   Playlist(QString, QList<Music>*);

  ~Playlist();

  /**
   * Retorna o nome da playlist.
   *
   * @returns O nome da playlist.
   */
  QString getName();

  /**
   * Cria um objeto Playlist a partir de um arquivo em disco.
   *
   * @param url QUrl para o arquivo da playlist.
   * @retutns Playlist& O Playlist criado a partir do arquivo.
   */
  static Playlist& fromFile(QUrl);
private:
  QString name;
  QList<Music>* musics;
};
#endif
