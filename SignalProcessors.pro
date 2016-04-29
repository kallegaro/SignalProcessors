#-------------------------------------------------
#
# Project created by QtCreator 2016-04-28T21:44:56
#
#-------------------------------------------------

QT       -= core gui

TARGET = SignalProcessors
TEMPLATE = lib
CONFIG += staticlib

SOURCES += signalprocessors.cpp \
    firfilter.tpp

HEADERS += signalprocessors.h \
    firfilter.h
#unix {
#    target.path = /usr/lib
#    INSTALLS += target
#}
