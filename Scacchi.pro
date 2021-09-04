QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    alfiere.cpp \
    cavallo.cpp \
    donna.cpp \
    main.cpp \
    mainwindow.cpp \
    pedone.cpp \
    pezzo.cpp \
    re.cpp \
    scacchiera.cpp \
    torre.cpp

HEADERS += \
    TuttiPezzi.h \
    alfiere.h \
    cavallo.h \
    clonable.h \
    deepptr.h \
    donna.h \
    mainwindow.h \
    pedone.h \
    pezzo.h \
    re.h \
    scacchiera.h \
    torre.h \
    vector.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
