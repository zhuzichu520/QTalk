cmake_minimum_required(VERSION 3.14)

project(QTalk VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR} CACHE PATH "Install path prefix" FORCE)
set(THIRD_PARTY_DIR ${PROJECT_SOURCE_DIR}/third_party)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Core Network Widgets Quick QuickControls2 REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core Network Widgets Quick QuickControls2 REQUIRED)

add_subdirectory(src)
