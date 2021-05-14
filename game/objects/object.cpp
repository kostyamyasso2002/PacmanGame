#include "object.h"

void PacMan::Move(int x, int y) {
  x_coordinate += x;
  y_coordinate += y;
}

void Ghost::Move(int x, int y) {
  x_coordinate += x;
  y_coordinate += y;
}

int Object::GetXCoordinate() {
  return x_coordinate;
}

int Object::GetYCoordinate() {
  return y_coordinate;
}

Object::Object(int x_coordinate, int y_coordinate, std::shared_ptr<Color> color) : x_coordinate(
    x_coordinate), y_coordinate(y_coordinate), color_(color) {}

PacMan::PacMan(int x_coordinate, int y_coordinate, std::shared_ptr<Color> color, int hp) : Object(
    x_coordinate,
    y_coordinate,
    color), health_point(hp), direction(Direction::RIGHT) {}

Ghost::Ghost(int x_coordinate, int y_coordinate, std::shared_ptr<Color> color)
    : Object(x_coordinate, y_coordinate, color) {}