#include <iostream>
#pragma once

enum class Direction {
  LEFT, RIGHT, DOWN, UP, NONE
};

std::pair<int, int> DirectionToCoords(Direction direction) ;