#-------------------------------------------------
#
# Project created by QtCreator 2015-04-27T20:52:06
#
#-------------------------------------------------

#QT       -= gui
QT       += xml core gui widgets

TARGET = Map
TEMPLATE = app

DEFINES += MAP_LIBRARY

SOURCES += map.cpp \
    node2d.cpp \
    node.cpp \
    map2d.cpp \
    main.cpp

HEADERS += map.h\
        map_global.h \
    node2d.h \
    node.h \
    map2d.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

RESOURCES += \
    resources.qrc
