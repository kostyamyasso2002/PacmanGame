#include "object.h"
#include <memory>
#include "color.h"

#pragma once

class ObjectCreator {
 protected:
  std::shared_ptr<Color> color_;
 public:
  ObjectCreator(std::shared_ptr<Color> color);
  virtual std::shared_ptr<Object> CreateObject(int x_coordinate, int y_coordinate, int hp = 0) = 0;
};

class PacManCreator : public ObjectCreator {
 public:
  PacManCreator(std::shared_ptr<Color> color);
  std::shared_ptr<Object> CreateObject(int x_coordinate, int y_coordinate, int hp) override;
};

class GhostCreator : public ObjectCreator {
 public:
  GhostCreator(std::shared_ptr<Color> color);
  std::shared_ptr<Object> CreateObject(int x_coordinate, int y_coordinate, int hp) override;
};