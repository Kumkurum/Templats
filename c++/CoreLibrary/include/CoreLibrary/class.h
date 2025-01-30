#ifndef NAMESPACE_CLASS_H
#define NAMESPACE_CLASS_H

#include <QObject>

namespace Namespace {

    class ClassPrivate;

    class Class : public QObject {
        Q_OBJECT
      public:
        explicit Class(QObject *parent = nullptr);

      private:
        ClassPrivate *m_pimpl;
    };

} // namespace Namespace

#endif // NAMESPACE_CLASS_H
