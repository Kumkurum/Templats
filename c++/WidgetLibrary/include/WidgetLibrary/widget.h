#ifndef NAMESPACE_WIDGET_H
#define NAMESPACE_WIDGET_H

#include <QWidget>

namespace Namespace {

    class WidgetPrivate;

    class Widget : public QWidget {
        Q_OBJECT
      public:
        explicit Widget(QWidget *parent = nullptr);

      private:
        WidgetPrivate *m_pimpl;
    };

} // namespace Namespace

#endif // NAMESPACE_WIDGET_H
