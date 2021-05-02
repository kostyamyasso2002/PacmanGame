cmake_minimum_required(VERSION 3.16)
project(game)

set(CMAKE_CXX_STANDARD 17)

add_executable(game main.cpp objects/object.h objects/objectController.h objects/ceil.h objects/direction.h objects/color.h objects/object.cpp objects/direction.cpp objects/objectController.cpp objects/objectControllerCreator.h objects/objectCreator.h objects/objectControllerCreator.cpp objects/objectCreator.cpp objects/ghostGroup.h objects/drawer.h objects/complexity.h objects/gameParametres.h objects/gameField.h objects/drawer.cpp)
