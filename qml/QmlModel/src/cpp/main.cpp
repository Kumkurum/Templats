//
// Created by kumkurum on 28.02.25.
//
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "Core.h"

int main(int argc, char *argv[]){
    QGuiApplication app(argc, argv);
    Core activityCore;
    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("core", &activityCore);
    const QUrl url("qrc:/Main.qml");
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
                if (!obj && url == objUrl)
                    QCoreApplication::exit(-1);
            }, Qt::QueuedConnection);
    engine.load(url);
    return app.exec();
}