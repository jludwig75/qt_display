cmake_minimum_required(VERSION 3.5)
project(weather_clock_test VERSION 1.0.0 LANGUAGES CXX)

include(CTest)
enable_testing()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

add_executable(weather_clock_test
    main.cpp
    weather_clock_display.cpp
    weather_ckock_display.h
)

target_link_libraries(weather_clock_test Qt6::Widgets)

set_target_properties(weather_clock_test PROPERTIES
    WIN32_EXECUTABLE ON
    MACOSX_BUNDLE ON
)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
