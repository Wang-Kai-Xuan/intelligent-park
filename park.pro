#-------------------------------------------------
#
# Project created by QtCreator 2015-11-17T14:28:12
#
#-------------------------------------------------

QT       += core gui serialport sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = park
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    mapwindow.cpp \
    carzone.cpp \
    database.cpp \
    carpositioninfo.cpp

HEADERS  += mainwindow.h \
    mapwindow.h \
    carzone.h \
    database.h \
    carpositioninfo.h

FORMS    += mainwindow.ui \
    carzone.ui

RESOURCES += \
    image.qrc
