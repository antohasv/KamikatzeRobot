#-------------------------------------------------
#
# Project created by QtCreator 2013-05-16T18:29:11
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets multimedia

TARGET = QtQRobot
TEMPLATE = app

INCLUDEPATH += C:\boost_1_53_0

SOURCES += main.cpp\
        mainwindow.cpp \
    menu.cpp \
    game.cpp \
    scen.cpp \
    window.cpp \
    medium.cpp \
    hard.cpp \
    easy.cpp \
    battery.cpp \
    bomb.cpp \
    door.cpp \
    power.cpp \
    robot.cpp \
    points.cpp \
    util.cpp \
    image.cpp \
    star.cpp \
    qtpoints.cpp \
    timer.cpp \
    result.cpp \
    score.cpp \
    scoreclient.cpp

HEADERS  += mainwindow.h \
    window.h \
    menu.h \
    game.h \
    scen.h \
    level.h \
    medium.h \
    hard.h \
    easy.h \
    battery.h \
    bomb.h \
    door.h \
    power.h \
    robot.h \
    points.h \
    src.h \
    util.h \
    image.h \
    star.h \
    qtpoints.h \
    timer.h \
    result.h \
    score.h \
    scoreclient.h

FORMS    += mainwindow.ui
