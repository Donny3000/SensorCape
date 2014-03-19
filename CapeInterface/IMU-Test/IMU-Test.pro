TEMPLATE = app
CONFIG += console
CONFIG -= qt

TARGET = imt-test

SOURCES += main.cpp

include(../mpu9150.pri)

INCLUDEPATH += $$INCDIR
DEPENDPATH += $$LIBDIR

LIBS += -L$$LIBDIR -lmpu9150-i2c

target.path = $$BINDIR

INSTALLS += target
