TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    Character.cpp \
    Command.cpp \
    CommandWords.cpp \
    Monster.cpp \
    Parser.cpp \
    Player.cpp \
    Room.cpp \
    Type.cpp \
    ZorkUL.cpp \
    item.cpp

HEADERS += \
    Character.h \
    Command.h \
    CommandWords.h \
    Monster.h \
    Parser.h \
    Player.h \
    Room.h \
    Type.h \
    ZorkUL.h \
    item.h
