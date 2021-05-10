#include "direction.h"

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
