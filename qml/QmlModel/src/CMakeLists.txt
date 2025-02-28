file(GLOB_RECURSE CPP_SOURCES
        cpp/*
)

set(PROJECT_SOURCES
        qml/qml.qrc
        cpp/Model.cpp
        cpp/Model.h
)


add_executable(${PROJECT_NAME}
        ${PROJECT_SOURCES}
        ${CPP_SOURCES}
)

if (QML_RELOAD)
    add_compile_definitions(QML_PATH="${CMAKE_CURRENT_SOURCE_DIR}")
endif ()

target_link_libraries(${PROJECT_NAME}
        PRIVATE Qt${QT_VERSION_MAJOR}::Quick
        Qt${QT_VERSION_MAJOR}::Gui
        Qt${QT_VERSION_MAJOR}::QuickControls2
)
