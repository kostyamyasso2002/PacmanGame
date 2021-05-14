#include "direction.h"
#include "constants.h"
#include "random.h"
#include <chrono>

std::pair<int, int> DirectionToCoords(Direction direction) {
  switch (direction) {
    case Direction::LEFT:return {0, -1};
    case Direction::RIGHT:return {0, 1};
    case Direction::DOWN:return {1, 0};
    case Direction::UP:return {-1, 0};
    case Direction::NONE:return {0, 0};
  }
}

Direction CoordsToDirection(std::pair<int, int> coordinates) {
  if (coordinates.first > 0) {
    return Direction::DOWN;
  }
  if (coordinates.first < 0) {
    return Direction::UP;
  }
  if (coordinates.second > 0) {
    return Direction::RIGHT;
  }
  if (coordinates.second < 0) {
    return Direction::LEFT;
  }
  return Direction::NONE;
}

Direction GetRandomDirection() {
  int rnd =
      static_cast<int>((Random::GetNextNumber() % Constants::amount_directions + Constants::amount_directions))
          % Constants::amount_directions;
  return Direction(rnd);
}