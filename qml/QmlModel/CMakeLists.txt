cmake_minimum_required(VERSION 3.7)
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
project(QMLModel VERSION 0.1 LANGUAGES CXX)


set(COMPANY "Kumkurum")
set(COPYRIGHT "Copyright (c) 2023 ${COMPANY}. All rights reserved.")
set(IDENTIFIER "${PROJECT_NAME}")


set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt5 REQUIRED COMPONENTS Core Quick )
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS
        Quick
        QuickControls2
        Gui
)

set(BUILD_DIR ${CMAKE_BINARY_DIR})
add_subdirectory(src)