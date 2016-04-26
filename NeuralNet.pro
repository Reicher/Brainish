#-------------------------------------------------
#
# Project created by QtCreator 2016-04-21T22:19:47
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = NeuralNet
CONFIG   += console
CONFIG   -= app_bundle
CONFIG += c++11

TEMPLATE = app


SOURCES += main.cpp \
    neuralnet.cpp \
    perceptron.cpp \
    testset.cpp \
    input.cpp

HEADERS += \
    perceptron.h \
    neuralnet.h \
    testset.h \
    input.h
