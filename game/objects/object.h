#include "direction.h"
#include "color.h"
#include "constants.h"
#include <memory>

#pragma once

class Object {
 public:
  int x_coordinate;
  int y_coordinate;
  std::shared_ptr<Color> color_;
 public:
  Object(int x_coordinate, int y_coordinate, std::shared_ptr<Color> color);
  virtual void Move(int x, int y) = 0;
  virtual ~Object() = default;
  int GetXCoordinate();
  int GetYCoordinate();
};

class PacMan : public Object {
 public:
  Direction direction;
  int health_point;
  void Move(int x, int y) override;

  PacMan(int x_coordinate, int y_coordinate, std::shared_ptr<Color> color, int hp);

  ~PacMan() override = default;
};

class Ghost : public Object {
 public:
  Ghost(int x_coordinate, int y_coordinate, std::shared_ptr<Color> color);
  void Move(int x, int y) override;
};
