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

INCLUDEPATH += "D:/opencv/build/install/include"
LIBS += -L"D:/opencv/build/install/x86/mingw/bin"
LIBS += -lopencv_calib3d320 \
        -lopencv_core320 \
        -lopencv_features2d320 \
        -lopencv_flann320 \
        -lopencv_highgui320 \
        -lopencv_imgcodecs320 \
        -lopencv_imgproc320 \
        -lopencv_ml320 \
        -lopencv_objdetect320 \
        -lopencv_photo320 \
        -lopencv_shape320 \
        -lopencv_stitching320 \
        -lopencv_superres320 \
        -lopencv_video320 \
        -lopencv_videoio320 \
        -lopencv_videostab320

DISTFILES +=


