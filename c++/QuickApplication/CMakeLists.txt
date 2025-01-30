cmake_minimum_required(VERSION 3.13)

project(QuickApplication)

set(CMAKE_AUTORCC ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Quick)

file(GLOB SOURCE src/*)

if(ANDROID)
    add_library(${PROJECT_NAME} SHARED ${SOURCE})
else()
    add_executable(${PROJECT_NAME} ${SOURCE})
endif()

target_link_libraries(${PROJECT_NAME}
    Qt${QT_VERSION_MAJOR}::Quick
)

add_subdirectory(submodule)

execute_process(COMMAND git describe --tags --always WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} OUTPUT_VARIABLE GIT_VERSION OUTPUT_STRIP_TRAILING_WHITESPACE)
execute_process(COMMAND ${CMAKE_COMMAND} -E env TZ=UTC git log -1 --format=%cd --date=format-local:"%d.%m.%Y %H:%M:%S" WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} OUTPUT_VARIABLE GIT_SOURCE_DATE OUTPUT_STRIP_TRAILING_WHITESPACE)
string(TIMESTAMP PROJECT_BUILD_DATE "%d.%m.%Y %H:%M:%S" UTC)
add_definitions(-DPROJECT_NAME="${PROJECT_NAME}" -DPROJECT_VERSION="${GIT_VERSION}" -DPROJECT_SOURCE_DATE=${GIT_SOURCE_DATE} -DPROJECT_BUILD_DATE="${PROJECT_BUILD_DATE}")
