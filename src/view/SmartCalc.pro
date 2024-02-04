QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ../controller/controller.c \
    ../model/converter.c \
    ../model/eval.c \
    ../model/helpres.c \
    ../model/stack.c \
    main.cpp \
    mainwindow.cpp \
    qcustomplot.cpp \

HEADERS += \
    ../controller/controller.h \
    ../model/headers/converter.h \
    ../model/headers/eval.h \
    ../model/headers/helpers.h \
    ../model/headers/stack.h \
    mainwindow.h \
    qcustomplot.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
