include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt

HEADERS += \
        tst_addressbook.h \
        ../app/addressbook.h

SOURCES += \
        main.cpp \
        ../app/addressbook.cpp
