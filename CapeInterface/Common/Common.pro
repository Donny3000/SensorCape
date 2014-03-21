#-------------------------------------------------
#
# Project created by QtCreator 2014-03-19T13:05:32
#
#-------------------------------------------------

QT       -= core gui

TARGET = Common
TEMPLATE = lib
CONFIG += staticlib

include(../common.pri)

SOURCES += \
    I2CInterface.cpp \
    SignalHandler.cpp

HEADERS += \
    I2CInterface.h \
    SignalHandler.h

target.path = $$LIBDIR

headers.path = $$INCDIR
headers.files = $$HEADERS

INSTALLS += target headers
