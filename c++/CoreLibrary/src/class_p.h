#ifndef NAMESPACE_CLASS_P_H
#define NAMESPACE_CLASS_P_H

#include <QObject>

namespace Namespace {

    class Class;

    class ClassPrivate : public QObject {
        Q_OBJECT
        explicit ClassPrivate(Class *parent);

        Class *m_pimpl;
        friend class Class;
    };

} // namespace Namespace

#endif // NAMESPACE_CLASS_P_H
