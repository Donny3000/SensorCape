#-------------------------------------------------
#
# Project created by QtCreator 2014-03-19T09:26:56
#
#-------------------------------------------------

QT       -= core gui

TARGET = mpu9150-i2c
TEMPLATE = lib
CONFIG += staticlib

DEFINES += MPU9150I2C_LIBRARY

SOURCES += \
    i2c.cpp \
    mpu9150.cpp

HEADERS += \
    i2c.h \
    mpu9150.h

include(../mpu9150.pri)

target.path = $$LIBDIR

headers.path = $$INCDIR
headers.files = $$HEADERS

INSTALLS += target headers
