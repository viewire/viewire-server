QT       +=  \
    core gui \
    network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11 \
          console

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    # httpserver.cpp \
    main.cpp \
    mainwindow.cpp \
    mediaserver.cpp

HEADERS += \
    # httpserver.h \
    mainwindow.h \
    mediaserver.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc

# win32:CONFIG(release, debug|release): LIBS += -L$$PWD/qhttpserver/qhttpengine-1.0.1-win64/lib/ -lqhttpengine
# else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/qhttpserver/qhttpengine-1.0.1-win64/lib/ -lqhttpengined
# else:unix: LIBS += -L$$PWD/qhttpserver/qhttpengine-1.0.1-win64/lib/ -lqhttpengine

# INCLUDEPATH += $$PWD/qhttpserver/qhttpengine-1.0.1-win64/include
# DEPENDPATH += $$PWD/qhttpserver/qhttpengine-1.0.1-win64/include
