TARGET = model
TEMPLATE = lib
CONFIG += shared x86_64
QT += sql qml
QT -= gui
DEFINES += TF_DLL
DESTDIR = ../lib
INCLUDEPATH += ../helpers
DEPENDPATH  += ../helpers
LIBS += -L../lib -lhelper
MOC_DIR = .obj/
OBJECTS_DIR = .obj/

include(../appbase.pri)
HEADERS += sqlobjects/t001userobject.h
HEADERS += objects/t001user.h
SOURCES += objects/t001user.cpp
HEADERS += t001userservice.h
SOURCES += t001userservice.cpp
