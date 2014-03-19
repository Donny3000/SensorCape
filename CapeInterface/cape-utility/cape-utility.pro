TEMPLATE = app
CONFIG += console
CONFIG -= qt

include(../common.pri)

TARGET = cape-utility

SOURCES += main.cpp

LIBS += -lmpu9150-i2c -lCommon

target.path = $$BINDIR

INSTALLS += target
