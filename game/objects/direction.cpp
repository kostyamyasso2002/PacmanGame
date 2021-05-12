#include "direction.h"
#include <random>
#include <chrono>

std::pair<int, int> DirectionToCoords(Direction direction) {
  switch (direction) {
    case Direction::LEFT:
      return {0, -1};
    case Direction::RIGHT:
      return {0, 1};
    case Direction::DOWN:
      return {1, 0};
    case Direction::UP:
      return {-1, 0};
    case Direction::NONE:
      return {0, 0};
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
  std::mt19937 Generate
      (std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now().time_since_epoch()).count());
  int rnd = static_cast<int>((Generate() % 5 + 5)) % 5;
  return Direction(rnd);
}