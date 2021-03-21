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
  void Move(int x, int y) override;

  PacMan();

  ~PacMan() override = default;
};

class Ghost : public Object {
 public:
  void Move(int x, int y) override;
};