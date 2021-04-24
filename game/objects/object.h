#include "direction.h"
#include "color.h"

#pragma once

class Object {
 protected:
  int x_coordinate;
  int y_coordinate;
  Color color_;
 public:
  Object(Color color) : color_(color) {}
  virtual void Move(int x, int y) = 0;
  virtual ~Object() = default;
};

class PacMan : public Object {
 public:
  Direction direction;
  int health_point;
  void Move(int x, int y) override;

  PacMan(Color color) : Object(color) {}

  ~PacMan() override = default;
};

class Ghost : public Object {
 public:
  Ghost(Color color) : Object(color) {}
  void Move(int x, int y) override;
};