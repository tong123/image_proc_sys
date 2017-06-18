TEMPLATE = app

QT += qml quick
CONFIG += c++11

SOURCES += main.cpp \
    image-item.cpp \
    image-operator.cpp

RESOURCES += qml.qrc \
    src.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    image-item.h \
    image-operator.h

