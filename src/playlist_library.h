#ifndef PLAYLIST_LIBRARY_H
#define PLAYLIST_LIBRARY_H

#include <QList>

#include "playlist.h"

/**
 * @brief Repositório de playlists do usuário.
 *
 * Esta classe oferece uma interface simplificada para lidar com as playlists
 * registradas na aplicação.
 */
class PlaylistLibrary
{
public:
  /**
   * Inicializa um objeto PlaylistLibrary vazio.
   */
  PlaylistLibrary();
  ~PlaylistLibrary();

  /**
   * Adiciona uma playlist à biblioteca.
   *
   * @params playlist Uma playlist.
   */
  void addPlaylist(Playlist&);
private:
  QList<Playlist>* playlists;
};

#endif