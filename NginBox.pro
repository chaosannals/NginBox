#-------------------------------------------------
#
# Project created by QtCreator 2016-12-21T10:55:21
#
#-------------------------------------------------

QT += core gui widgets

TARGET = NginBox
TEMPLATE = app
RC_ICONS = NginBox.ico

SOURCES += src/main.cpp \
    src/form/mainwindow.cpp \
    src/form/nginxview.cpp \
    src/form/phpview.cpp

HEADERS += \
    src/form/mainwindow.h \
    src/form/nginxview.h \
    src/form/phpview.h

FORMS += \
    src/form/mainwindow.ui \
    src/form/nginxview.ui \
    src/form/phpview.ui
