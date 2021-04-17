#include "object.h"

void PacMan::Move(int x, int y) {
  x_coordinate += x;
  y_coordinate += y;
}

PacMan::PacMan()  {
  x_coordinate = 1;
  y_coordinate = 2;
  direction = Direction::NONE;
  health_point = 10;
}

void Ghost::Move(int x, int y) {
  x_coordinate += x;
  y_coordinate += y;
}
