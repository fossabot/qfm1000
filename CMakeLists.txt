cmake_minimum_required(VERSION 3.1)
project(qfm1000)

if (UNIX)
    include(GNUInstallDirs)
endif ()

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

set(QT5_PREFIX "$ENV{QTDIR}" CACHE PATH "Qt5 prefix path")

find_program(QT5_QMAKE_BIN
        qmake
        PATHS "${QT5_PREFIX}/bin")

if (NOT QT5_QMAKE_BIN)
    message(FATAL_ERROR "Qt5 QMake not found")
endif ()

set(CMAKE_PREFIX_PATH "${QT5_PREFIX}/lib/cmake")

if (WIN32 OR APPLE)
    if (WIN32)
        find_program(QT5_DEPLOYQT_BIN
                windeployqt
                PATHS "${QT5_PREFIX}/bin")
    elseif (APPLE)
        find_program(QT5_DEPLOYQT_BIN
                macdeployqt
                PATHS "${QT5_PREFIX}/bin")
    endif ()

    if (NOT QT5_DEPLOYQT_BIN)
        message(FATAL_ERROR "No Qt Deploy command found")
    endif ()
endif ()

set(QFM1000_APPLICATION_NAME "qFM1000")
set(QFM1000_APPLICATION_VERSION_MAJOR "0")
set(QFM1000_APPLICATION_VERSION_MINOR "8")
set(QFM1000_APPLICATION_VERSION_PATCH "0")

set(QFM1000_ORGANIZATION_NAME "The HellNet.org")
set(QFM1000_ORGANIZATION_DOMAIN "thehellnet.org")

set(QFM1000_APPLICATION_VERSION "${QFM1000_APPLICATION_VERSION_MAJOR}.${QFM1000_APPLICATION_VERSION_MINOR}.${QFM1000_APPLICATION_VERSION_PATCH}")

enable_testing()

add_subdirectory(src)

add_subdirectory(desktop)

include(cmake/packaging.cmake)
