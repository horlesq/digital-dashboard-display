cmake_minimum_required(VERSION 3.16)
project(digital-dashboard-display)

set(CMAKE_CXX_STANDARD 17)

# SFML path
set(SFML_DIR "C:/Tools/SFML-2.6.2/lib/cmake/SFML")
find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

# Include dirs
include_directories(include)

# Src files
file(GLOB SOURCES "src/*.cpp")

add_executable(digital-dashboard-display ${SOURCES})

target_link_libraries(digital-dashboard-display sfml-graphics sfml-window sfml-system)