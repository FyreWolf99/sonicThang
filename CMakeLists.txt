cmake_minimum_required(VERSION 3.1)

project(sonicThang LANGUAGES CXX)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

add_executable(sonicThing src/main.cpp src/input.cpp src/player.cpp src/render.cpp src/vec2.cpp)
include_directories(include)
target_link_libraries(sonicThing ${SDL2_LIBRARIES})