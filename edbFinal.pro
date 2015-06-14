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

SOURCES += main.cpp\
        mainwindow.cpp \
    musiclibrary.cpp \
    music.cpp \
    playlist.cpp \
    duration.cpp

HEADERS  += mainwindow.h \
    musiclibrary.h \
    music.h \
    playlist.h \
    duration.h

FORMS    += mainwindow.ui
