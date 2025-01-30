#ifndef NAMESPACE_WIDGET_H
#define NAMESPACE_WIDGET_H

#include <QWidget>

namespace Namespace {

    namespace Ui {
        class Widget;
    }

    class WidgetPrivate;

    class Widget : public QWidget {
        Q_OBJECT
      public:
        explicit Widget(QWidget *parent = nullptr);
        ~Widget();

      private:
        WidgetPrivate *m_pimpl;
        Ui::Widget *ui;
    };

} // namespace Namespace

#endif // NAMESPACE_WIDGET_H
