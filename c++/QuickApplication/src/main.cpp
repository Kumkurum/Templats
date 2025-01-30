#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QDateTime>
#include <QDebug>

int main(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine("qrc:/main.qml");

    return app.exec();
}

__attribute__((constructor)) void showVersion() {
    qInfo() << PROJECT_NAME << "version" << PROJECT_VERSION << "source" << PROJECT_SOURCE_DATE << "build" << PROJECT_BUILD_DATE << "start" << QDateTime::currentDateTimeUtc().toString("dd.MM.yyyy hh:mm:ss").toStdString().data();
}
