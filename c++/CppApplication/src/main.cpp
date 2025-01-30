#include <cstdio>
#include <ctime>

int main() {}

__attribute__((constructor)) void showVersion() {
    const time_t curTime = time(nullptr);
    char curTimeStr[20];
    strftime(curTimeStr, sizeof(curTimeStr), "%d.%m.%Y %H:%M:%S", gmtime(&curTime));
    printf("%s version %s source %s build %s start %s\n", PROJECT_NAME, PROJECT_VERSION, PROJECT_SOURCE_DATE, PROJECT_BUILD_DATE, curTimeStr);
}
