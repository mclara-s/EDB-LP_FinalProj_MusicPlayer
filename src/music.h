#ifndef MUSIC_H
#define MUSIC_H

#include <QUrl>
#include <QString>
#include <QMediaContent>

#include "duration.h"

/**
 * @brief Uma música.
 *
 * A classe Music provê funcionalidades de uma música.
 */
class Music
{
public:
  /**
   * Inicializa um objeto Music com o nome, duração, em segundos, e o caminho
   * informados.
   *
   * @param n Nome da música.
   * @param a Nome do álbum da música.
   * @param ar Nome do artista.
   * @param g Gênero musical.
   * @param d Duração em segundos.
   * @param c QMediaContent para a música.
   */
  Music(QString, QString, QString, QString, int, QMediaContent*);
  ~Music();

  /**
   * Retorna o nome da música.
   *
   * @returns Nome da música.
   */
  QString getName();

  /**
   * Retorna o gênero da música.
   *
   * @returns O gênero da música.
   */
  QString getGenre();

  /**
   * Retorna o nome do álbum do qual essa música faz parte.
   *
   * @returns Nome da álbum.
   */
  QString getAlbum();

  /**
   * Retorna o nome do artista.
   *
   * @returns Nome do artista.
   */
  QString getArtist();

  /**
   * Retorna o duration da música.
   *
   * @returns Duration da música.
   */
  Duration& getDuration();

  QMediaContent& getContent();

  /**
   * Inicializa uma Musica a partir de um QUrl.
   *
   * @param QUrl para o arquivo da música.
   * @returns Um objeto Music.
   */
  static Music& fromUrl(QUrl);
private:
  QString name;
  QString genre;
  QString album;
  QString artist;
  Duration* duration;
  QMediaContent* content;
};

#endif