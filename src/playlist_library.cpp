#include "playlist_library.h"

PlaylistLibrary::PlaylistLibrary()
  : playlists(new QList<Playlist>()) {}

PlaylistLibrary::~PlaylistLibrary()
{
  if (playlists)
    delete playlists;
}

void PlaylistLibrary::addPlaylist(Playlist& playlist)
{
  playlist;
  // playlists->push_back(playlist);
}