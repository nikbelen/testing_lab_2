TEMPLATE = subdirs

CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++17

QMAKE_CXXFLAGS += -fprofile-arcs -ftest-coverage -O0 -std=c++11

SUBDIRS = app tests

CONFIG += ordered
