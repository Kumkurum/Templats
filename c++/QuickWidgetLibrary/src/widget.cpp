#include <QuickWidgetLibrary/widget.h>
#include "widget_p.h"

namespace Namespace {

    Widget::Widget(QWidget *parent)
        : QQuickWidget(parent)
        , m_pimpl(new WidgetPrivate(this))
    {
        setSource(QUrl("qrc:/widget.qml"));
        setResizeMode(QQuickWidget::SizeRootObjectToView);
    }

    WidgetPrivate::WidgetPrivate(Widget *parent)
        : QObject(parent)
        , m_pimpl(parent)
    {}

} // namespace Namespace

__attribute__((constructor)) void showVersionQuickWidgetLibrary() {
    qInfo() << PROJECT_NAME << "version" << PROJECT_VERSION << "source" << PROJECT_SOURCE_DATE << "build" << PROJECT_BUILD_DATE;
    Q_INIT_RESOURCE(widget);
}
