#ifndef NAMESPACE_CLASS_H
#define NAMESPACE_CLASS_H

#include <memory>

namespace Namespace {

    class Class {
      public:
        explicit Class();
        ~Class();

      private:
        struct Impl;
        std::unique_ptr<Impl> pImpl;
    };

} // namespace Namespace

#endif // NAMESPACE_CLASS_H
