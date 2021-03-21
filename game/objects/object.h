#include "direction.h"
#include "color.h"
#pragma once

class Object {
 public:
  int XCoordinate;
  int YCoordinate;
  virtual void Move(int x, int y) = 0;

  virtual ~Object() = default;
};

class PacMan : public Object {
 public:
  Direction direction;
  int health_point;
  Color color;
  void Move(int x, int y) override {
    XCoordinate += x;
    YCoordinate += y;
  }

  PacMan() {
    XCoordinate = 1;
    YCoordinate = 2;
    direction = Direction::None;
    health_point = 10;
  }

  ~PacMan() override = default;
};

class Ghost : public Object {
 public:
  virtual void Move(int x, int y) override;
};