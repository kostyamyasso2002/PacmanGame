#include <utility>

#include "objectController.h"
#include "objectCreator.h"
#include "gameParametres.h"
#include "complexity.h"

#pragma once

class ObjectControllerCreator {
 protected:
  std::shared_ptr<ObjectCreator> creator;
  GameParameters parameters;
 public:
  virtual std::shared_ptr<ObjectController> CreateObjectController(int x_coordinate, int y_coordinate) = 0;
};

class PacManControllerCreator : public ObjectControllerCreator {
 public:
  PacManControllerCreator(const GameParameters& param);
  std::shared_ptr<ObjectController> CreateObjectController(int x_coordinate, int y_coordinate) override;
};

class GhostControllerCreator : public ObjectControllerCreator {
 public:
  GhostControllerCreator(const GameParameters& param);
  std::shared_ptr<ObjectController> CreateObjectController(int x_coordinate, int y_coordinate) override;
};