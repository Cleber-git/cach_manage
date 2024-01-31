QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += sql widgets

CONFIG += c++17

DESTDIR+= bin

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    choose.cpp \
    cont_all.cpp \
    db_manage.cpp \
    form.cpp \
    form2.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    choose.h \
    cont_all.h \
    db_manage.h \
    form.h \
    form2.h \
    mainwindow.h

FORMS += \
    choose.ui \
    cont_all.ui \
    form.ui \
    form2.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    rec.qrc
