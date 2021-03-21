#include "object.h"

void PacMan::Move(int x, int y) {
  XCoordinate += x;
  YCoordinate += y;
}

PacMan::PacMan()  {
  XCoordinate = 1;
  YCoordinate = 2;
  direction = Direction::NONE;
  health_point = 10;
}

void Ghost::Move(int x, int y) {
  XCoordinate += x;
  YCoordinate += y;
}
