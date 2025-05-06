QT       += core gui network  sql multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17
CONFIG += link_psql
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    apiurls.cpp \
    main.cpp \
    mainwidget.cpp

HEADERS += \
    apiurls.h \
    mainwidget.h

FORMS += \
    mainwidget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    images.qrc

QMAKE_EXTRA_TARGETS += setmediabackend
    setmediabackend.CONFIG = env
    setmediabackend.VARIABLES = QT_MEDIA_BACKEND=windows
    QMAKE_EXTRA_TARGETS += setmediabackend


PLUGINPATH = /path/to/mysql/plugin
QMAKE_PLUGIN_PATH = $$PLUGINPATH
