#-------------------------------------------------
#
# Project created by QtCreator 2018-07-03T19:09:24
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = URS_Projektni
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    fpga.cpp \
    hps.cpp \
    ADLX345.cpp

HEADERS  += mainwindow.h \
    fpga.h \
    hps_0.h \
    hps.h \
    ADLX345.h

FORMS    += mainwindow.ui

INCLUDEPATH += /home/student/Desktop/hwlib/include
DEPENDPATH += /home/student/Desktop/hwlib/include

QMAKE_CXXFLAGS += -std=gnu++11
