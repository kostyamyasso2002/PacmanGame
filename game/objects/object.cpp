#include "object.h"

void PacMan::Move(int x, int y) {
  x_coordinate += x;
  y_coordinate += y;
}

void Ghost::Move(int x, int y) {
  x_coordinate += x;
  y_coordinate += y;
}