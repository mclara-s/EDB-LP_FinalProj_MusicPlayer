#-------------------------------------------------
#
# Project created by QtCreator 2015-05-12T09:22:39
#
#-------------------------------------------------

QT       += core gui
QT  += multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = edbFinal
TEMPLATE = app

CONFIG += c++11

SOURCES += src/main.cpp\
    src/duration.cpp \
    src/music.cpp \
    src/playlist.cpp \
    src/main_window.cpp \
    src/playlist_library.cpp \

HEADERS  += src/duration.h \
    src/music.h \
    src/playlist.h \
    src/main_window.h \
    src/application.h \
    src/music_library.h \
    src/playlist_library.h \

FORMS    += src/main_window.ui