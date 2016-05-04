#-------------------------------------------------
#
# Project created by QtCreator 2016-04-28T21:44:56
#
#-------------------------------------------------

QT       -= core gui

CONFIG += C++11

TARGET = SignalProcessors
TEMPLATE = lib
CONFIG += staticlib

SOURCES += signalprocessors.cpp \
    #firfilter.tpp
    sinewavegenerator.cpp

HEADERS += signalprocessors.h \
    firfilter.h \
    sinewavegenerator.h

OTHER_FILES += \
    firfilter.tpp

#unix {
#    target.path = /usr/lib
#    INSTALLS += target
#}
