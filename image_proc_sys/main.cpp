#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "image-item.h"
#include "image-operator.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    qmlRegisterType<CImageItem>("ImageItem", 1, 0, "ImageItem");
    engine.rootContext()->setContextProperty("image_operator", new ImageOperator );
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}

