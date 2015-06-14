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
class Music : public QMediaContent
{
public:
  /**
   * Inicializa um objeto Music com o nome, duração, em segundos, e o caminho
   * informados.
   *
   * @param name Nome da música.
   * @param duration Duração em segundos.
   * @param url Caminho para o arquivo da música.
   */
  Music(QString, int, QUrl);
  ~Music();

  /**
   * Retorna o nome da música.
   *
   * @returns Nome da música.
   */
  QString getName();

  /**
   * Retorna o duration da música.
   *
   * @returns Duration da música.
   */
  Duration& getDuration();
private:
  QString name;
  Duration* duration;
};

#endif
