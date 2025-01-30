#include <WidgetLibrary/widget.h>
#include "widget_p.h"

#include <QDebug>

namespace Namespace {

    Widget::Widget(QWidget *parent)
        : QWidget(parent)
        , m_pimpl(new WidgetPrivate(this))
    {}

    WidgetPrivate::WidgetPrivate(Widget *parent)
        : QObject(parent)
        , m_pimpl(parent)
    {}

    __attribute__((constructor)) void showVersion() {
        qInfo() << PROJECT_NAME << "version" << PROJECT_VERSION << "source" << PROJECT_SOURCE_DATE << "build" << PROJECT_BUILD_DATE;
    }
} // namespace Namespace
