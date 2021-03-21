cmake_minimum_required(VERSION 3.16)
project(game)

set(CMAKE_CXX_STANDARD 17)

add_executable(game main.cpp objects/object.h objects/objectController.h objects/ceil.h objects/strategy.h objects/field.h objects/direction.h objects/color.h objects/drawer.h objects/ceil.cpp objects/drawer.cpp objects/object.cpp objects/direction.cpp objects/objectController.cpp objects/field.cpp)