QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += sql widgets

CONFIG += c++17

DESTDIR+= bin

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    cont_all.cpp \
    db_manage.cpp \
    dialog.cpp \
    form.cpp \
    form2.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    cont_all.h \
    db_manage.h \
    dialog.h \
    form.h \
    form2.h \
    mainwindow.h

FORMS += \
    cont_all.ui \
    dialog.ui \
    form.ui \
    form2.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    rec.qrc
