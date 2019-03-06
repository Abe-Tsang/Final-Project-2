#-------------------------------------------------
#
# Project created by QtCreator 2019-02-04T16:59:52
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Catan
TEMPLATE = app

CONFIG += c++11

SOURCES += main.cpp\
        mainwindow.cpp \
    area.cpp \
    player.cpp \
    game.cpp \
    ai.cpp

HEADERS  += mainwindow.h \
    area.h \
    player.h \
    game.h \
    ai.h

FORMS    += mainwindow.ui
