#-------------------------------------------------
#
# Project created by QtCreator 2016-07-09T19:06:07
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = StudentRecordSystem
TEMPLATE = app


SOURCES += main.cpp\
        login.cpp \
    splashscreenform.cpp \
    loginform.cpp \
    aboutbox.cpp \
    sqlite3.c \
    changepassword.cpp \
    signup.cpp \
    insertform.cpp

HEADERS  += login.h \
    splashscreenform.h \
    loginform.h \
    aboutbox.h \
    sqlite3.h \
    changepassword.h \
    signup.h \
    insertform.h \
    Node.h \
    List.h

FORMS    += login.ui \
    splashscreenform.ui \
    loginform.ui \
    aboutbox.ui \
    changepassword.ui \
    signup.ui \
    insertform.ui

DISTFILES +=

RESOURCES += \
    resources.qrc
