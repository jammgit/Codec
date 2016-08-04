#-------------------------------------------------
#
# Project created by QtCreator 2016-08-04T16:28:33
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
QT += network
CONFIG += c++11
QT += multimedia
QT += core
QT += multimediawidgets
TARGET = Codec
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

INCLUDEPATH +=  ffmpeg/include

LIBS += ./ffmpeg/lib/libavcodec.dll.a \
        ./ffmpeg/lib/libavfilter.dll.a \
        ./ffmpeg/lib/libavformat.dll.a \
        ./ffmpeg/lib/libswscale.dll.a \
        ./ffmpeg/lib/libavutil.dll.a \

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui
