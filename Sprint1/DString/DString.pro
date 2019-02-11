TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    dstring.cpp \
    tests.cpp

HEADERS += \
    dstring.h \
    catch.hpp
