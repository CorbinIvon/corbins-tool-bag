# Initialize aplication
debug {
    # Qt application (for debugger)

    QT += core
    QT -= gui

    CONFIG += c++14

    CONFIG += console
    CONFIG -= app_bundle
} else {
    # C++ application

    CONFIG += console c++14
    CONFIG -= app_bundle

    CONFIG -= qt
}

TEMPLATE = app

TARGET = Character_Quest

# Files
SOURCES += main.cpp \
    biome.cpp \
    bobj.cpp \
    button.cpp \
    character.cpp \
    font.cpp \
    gmapslot.cpp \
    label.cpp \
    rands.cpp \
    scene.cpp \
    screen.cpp \
    text.cpp \
    timer.cpp \
    coord.cpp \
    gmap.cpp \
    gmaphome.cpp \
    gmapworld.cpp \
    rect.cpp \
    saveslot.cpp \
    bobjcat.cpp \
    pushmessage.cpp

HEADERS += \
    biome.h \
    biomes.h \
    bobj.h \
    bobjcat.h \
    button.h \
    character.h \
    font.h \
    fonts.h \
    gmapslot.h \
    keycodes.h \
    label.h \
    main.h \
    ncursesall.h \
    pushmessage.h \
    rands.h \
    savedelete.h \
    scene.h \
    scenes.h \
    screen.h \
    text.h \
    timer.h \
    coord.h \
    gmap.h \
    gmaphome.h \
    gmapworld.h \
    rect.h \
    saveslot.h

# NCurses lib

# Instruction for intall:
# Linux: sudo apt-get install libncursesw5-dev
# Windows: Download PDCurses (from https://sourceforge.net/projects/pdcurses/files/pdcurses/3.4/pdcurs34.zip/download)
#                Extract zip
#                In cmd: path = "path to MinGW Compiler (C:/Qt/5.6/mingw49_32/bin)"
#                In cmd: cd "path to zip + /win32"
#                In cmd: mingw32-make -f mingwin32.mak
#                Copy / Paste panel.a and ncurses.a to "path to MinGW Compiler" + /lib
#                Copy / Paste curses.h to "path to MinGW Compiler" + /include

win32 {
    INCLUDEPATH += C:/Qt/5.6/mingw49_32/include
    LIBS += C:/Qt/5.6/mingw49_32/lib/pdcurses.a
}

unix:!macx {
    LIBS += -lncursesw
}

# Defines

# Debug / Release
debug {
  DEFINES += DEBUG
} else {
  DEFINES += RELEASE
}

# Systems
win32 {
  DEFINES += WINDOWS
} else {
  DEFINES += LINUX
}

# Other

# Icon
win32:RC_FILE = resource.rc

DISTFILES += \
    icon.ico \
    resource.rc
