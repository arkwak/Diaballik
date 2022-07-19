QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
    console/Controller.cpp \
    console/View.cpp \
    display/gametile.cpp \
    display/gamewindow.cpp \
    display/mainwindow.cpp \
    main/main.cpp \
    model/board.cpp \
    model/color.cpp \
    model/direction.cpp \
    model/game.cpp \
    model/move.cpp \
    model/piece.cpp \
    model/player.cpp \
    model/position.cpp \
    model/square.cpp \
    model/status.cpp \
    model/type.cpp \

HEADERS += \
    console/Controller.h \
    console/View.h \
    display/gametile.h \
    display/gamewindow.h \
    display/mainwindow.h \
    model/board.h \
    model/color.h \
    model/direction.h \
    model/game.h \
    model/move.h \
    model/piece.h \
    model/player.h \
    model/position.h \
    model/square.h \
    model/status.h \
    model/type.h \

FORMS += \
    gamewindow.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resources.qrc
