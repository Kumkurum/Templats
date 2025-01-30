#include <CoreLibrary/class.h>
#include "class_p.h"

#include <QDebug>

namespace Namespace {

    Class::Class(QObject *parent)
        : QObject(parent)
        , m_pimpl(new ClassPrivate(this))
    {}

    ClassPrivate::ClassPrivate(Class *parent)
        : QObject(parent)
        , m_pimpl(parent)
    {}

    __attribute__((constructor)) void showVersion() {
        qInfo() << PROJECT_NAME << "version" << PROJECT_VERSION << "source" << PROJECT_SOURCE_DATE << "build" << PROJECT_BUILD_DATE;
    }
} // namespace Namespace
