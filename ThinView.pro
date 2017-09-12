#-------------------------------------------------
#
# Project created by QtCreator 2017-08-29T11:52:15
#
#-------------------------------------------------

QT       += core gui network xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ThinView
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        widget.cpp \
    settingdialog.cpp \
    titlebar.cpp \
    passworderror.cpp \
    setting.cpp \
    customtab.cpp \
    xml.cpp \
    vmdata.cpp \
    https.cpp

HEADERS += \
        widget.h \
    settingdialog.h \
    titlebar.h \
    passworderror.h \
    setting.h \
    customtabstyle.h \
    customtab.h \
    xml.h \
    vmdata.h \
    https.h

FORMS += \
        widget.ui \
    settingdialog.ui \
    titlebar.ui \
    passworderror.ui \
    setting.ui \
    customtab.ui

TRANSLATIONS = ThinView_zh_CN.ts

RESOURCES += \
    res.qrc
