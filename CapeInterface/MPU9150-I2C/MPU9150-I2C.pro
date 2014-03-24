#-------------------------------------------------
#
# Project created by QtCreator 2014-03-19T09:26:56
#
#-------------------------------------------------

QT       -= core gui

TARGET = mpu9150-i2c
TEMPLATE = lib
CONFIG += staticlib

include(../common.pri)

DEFINES += MPU9150I2C_LIBRARY

SOURCES += \
    mpu9150.cpp

HEADERS += \
    mpu9150.h

target.path = $$LIBDIR

headers.path = $$INCDIR
headers.files = $$HEADERS

INSTALLS += target headers
