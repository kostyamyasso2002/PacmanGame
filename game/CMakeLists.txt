cmake_minimum_required(VERSION 3.16)
project(game)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_COMPILER clang++)

add_executable(game main.cpp objects/object.h objects/objectController.h objects/ceil.h objects/direction.h objects/color.h objects/object.cpp objects/objectController.cpp objects/objectControllerCreator.h objects/objectCreator.h objects/objectControllerCreator.cpp objects/objectCreator.cpp objects/ghostGroup.h objects/drawer.h objects/complexity.h objects/gameParametres.h objects/drawer.cpp objects/ceil.cpp objects/gameField.cpp objects/ghostGroup.cpp objects/direction.cpp objects/keyboard.cpp objects/strategy.cpp objects/menu.cpp objects/color.cpp objects/fieldGenerator.cpp objects/gameParametres.cpp)
