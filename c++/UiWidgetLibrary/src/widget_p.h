#ifndef NAMESPACE_WIDGET_P_H
#define NAMESPACE_WIDGET_P_H

#include <QObject>

namespace Namespace {

    class Widget;

    class WidgetPrivate : public QObject {
        Q_OBJECT
        explicit WidgetPrivate(Widget *parent);

        Widget *m_pimpl;
        friend class Widget;
    };

} // namespace Namespace

#endif // NAMESPACE_WIDGET_P_H
