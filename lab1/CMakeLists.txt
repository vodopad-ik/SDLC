cmake_minimum_required(VERSION 3.16)
project(ProteinCalculator LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)

find_package(Qt6 COMPONENTS Widgets REQUIRED)

add_executable(ProteinCalculator
    main.cpp
    model.cpp
    view.cpp
    controller.cpp
)

target_link_libraries(ProteinCalculator PRIVATE Qt6::Widgets)
