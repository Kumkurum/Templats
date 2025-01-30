#include <CppLibrary/class.h>

#include <cstdio>

namespace Namespace {

    struct Class::Impl {};

    Class::Class()
        : pImpl(new Impl())
    {}

    Class::~Class() {}

    __attribute__((constructor)) void showVersion() {
        printf("%s version %s source %s build %s\n", PROJECT_NAME, PROJECT_VERSION, PROJECT_SOURCE_DATE, PROJECT_BUILD_DATE);
    }
} // namespace Namespace
