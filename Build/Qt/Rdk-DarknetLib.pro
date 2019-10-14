#-------------------------------------------------
#
# Project created by QtCreator 2012-11-11T15:17:55
#
#-------------------------------------------------

QT       -= gui

TARGET = Rdk-DarknetLib.qt
TEMPLATE = lib
CONFIG += staticlib

include($$PWD/../../../../Rdk/Build/Lib/Qt/RdkDefines.pri)


DEFINES += LIBRDK_LIBRARY_EXPORT
DEFINES += RDK_UNICODE_RUN
DEFINES += RDK_QT

VERSION = $$system(hg parents --template '{rev}')
DEFINES += RDK_LIB_CVS_REVISION=$$VERSION

INCLUDEPATH += $$PWD/../../../../Rdk/Deploy/Include

unix {
    CONFIG += c++11

    DESTDIR = $$PWD/../../../../Bin/Platform/Linux/Lib.Qt

    contains(DEFINES,RDK_USE_DARKNET) {
    INCLUDEPATH += ../../ThirdParty/darknet/include/

    HEADERS += ../../ThirdParty/darknet/include/darknet.h \
    ../../Core/TDarknetObjectDetector.h \
    ../../Core/TDarknetUBitmapClassifier.h \
    ../../ThirdParty/darknet/include/darknet_utils.h

    SOURCES += ../../ThirdParty/darknet/include/darknet_utils.cpp \
    ../../Core/TDarknetUBitmapClassifier.cpp \
    ../../Core/TDarknetObjectDetector.cpp
}
} else:windows {
    DESTDIR = $$PWD/../../../../Bin/Platform/Win/Lib.Qt
}


HEADERS += \
    ../../Core/Lib.h


SOURCES += \
    ../../Core/Lib.cpp


