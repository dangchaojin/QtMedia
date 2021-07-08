#-------------------------------------------------
#
# Project created by QtCreator 2021-07-08T15:03:46
#
#-------------------------------------------------

QT       += core gui multimedia multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QtMedia
TEMPLATE = app

CONFIG += c++11

SOURCES += main.cpp\
        mainwindow.cpp \
    camerawidget.cpp \
    choosepicwidget.cpp \
    otheroperwidget.cpp \
    picoperwidget.cpp \
    popupwidget.cpp \
    printfile.cpp

HEADERS  += mainwindow.h \
    camerawidget.h \
    choosepicwidget.h \
    common.h \
    otheroperwidget.h \
    picoperwidget.h \
    popupwidget.h \
    printfile.h
