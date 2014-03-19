TEMPLATE = app
CONFIG += console
CONFIG -= qt

TARGET = cape-utility

SOURCES += main.cpp

include(../common.pri)

INCLUDEPATH += $$INCDIR
DEPENDPATH += $$LIBDIR

LIBS += -L$$LIBDIR -lmpu9150-i2c

target.path = $$BINDIR

INSTALLS += target
