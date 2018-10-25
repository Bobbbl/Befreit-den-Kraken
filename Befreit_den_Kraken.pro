#-------------------------------------------------
#
# Project created by QtCreator 2018-03-19T10:01:10
#
#-------------------------------------------------

QT       += core gui network sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets console

TARGET = Befreit_den_Kraken
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    mcp3008Spi.cpp \
    wlan_dialog.cpp \
    sensorscanner.cpp \
    calibrate_ph_dialog.cpp \
    uhr.cpp \
    calibrate_trueb_dialog.cpp \
    database.cpp

HEADERS  += mainwindow.h \
    mcp3008Spi.h \
    wlan_dialog.h \
    sensorscanner.h \
    calibrate_ph_dialog.h \
    uhr.h \
    calibrate_trueb_dialog.h \
    database.h

FORMS    += mainwindow.ui \
    wlan_dialog.ui \
    calibrate_ph_dialog.ui \
    calibrate_trueb_dialog.ui



win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../usr/lib/arm-linux-gnueabihf/release/ -liw
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../usr/lib/arm-linux-gnueabihf/debug/ -liw
else:unix: LIBS += -L$$PWD/../../../../../usr/lib/arm-linux-gnueabihf/ -liw

INCLUDEPATH += $$PWD/../../../../../usr/lib/arm-linux-gnueabihf
DEPENDPATH += $$PWD/../../../../../usr/lib/arm-linux-gnueabihf

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../../../../usr/lib/arm-linux-gnueabihf/release/libiw.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../../../../usr/lib/arm-linux-gnueabihf/debug/libiw.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../../../../usr/lib/arm-linux-gnueabihf/release/iw.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../../../../usr/lib/arm-linux-gnueabihf/debug/iw.lib
else:unix: PRE_TARGETDEPS += $$PWD/../../../../../usr/lib/arm-linux-gnueabihf/libiw.a
