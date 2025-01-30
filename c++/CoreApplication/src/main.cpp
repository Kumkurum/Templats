#include <QCoreApplication>
#include <QDateTime>
#include <QDebug>

#include <csignal>

int main(int argc, char *argv[]) {
    QCoreApplication app(argc, argv);

    return app.exec();
}

void signalHandler(int signal) {
}

__attribute__((constructor)) void showVersion() {
    //std::signal(SIGINT, signalHandler);
    //std::signal(SIGTERM, signalHandler);
    qInfo() << PROJECT_NAME << "version" << PROJECT_VERSION << "source" << PROJECT_SOURCE_DATE << "build" << PROJECT_BUILD_DATE << "start" << QDateTime::currentDateTimeUtc().toString("dd.MM.yyyy hh:mm:ss").toStdString().data();
}
