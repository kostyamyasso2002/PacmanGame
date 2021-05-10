#include "direction.h"
#include "color.h"

#pragma once

class Object {
 public:
  int x_coordinate;
  int y_coordinate;
  Color color_;
 public:
  Object(int x_coordinate, int y_coordinate, Color color) : x_coordinate(x_coordinate), y_coordinate(y_coordinate), color_(color) {}
  virtual void Move(int x, int y) = 0;
  virtual ~Object() = default;
};

class PacMan : public Object {
 public:
  Direction direction;
  int health_point;
  void Move(int x, int y) override;

  PacMan(int x_coordinate, int y_coordinate, Color color, int hp = 10) : Object(x_coordinate, y_coordinate, color), health_point(hp), direction(Direction::RIGHT) {}

  ~PacMan() override = default;
};

class Ghost : public Object {
 public:
  Ghost(int x_coordinate, int y_coordinate, Color color) : Object(x_coordinate, y_coordinate, color) {}
  void Move(int x, int y) override;
};
