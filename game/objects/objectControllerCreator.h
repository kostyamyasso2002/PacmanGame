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
  PacManControllerCreator(const GameParameters& param) {
    parameters = param;
    creator = std::make_shared<PacManCreator>(parameters.pacman_color);
  }
  std::shared_ptr<ObjectController> CreateObjectController(int x_coordinate, int y_coordinate) override;
};

class GhostControllerCreator : public ObjectControllerCreator {
 public:
  GhostControllerCreator(const GameParameters& param) {
    parameters = param;
    creator = std::make_shared<GhostCreator>(parameters.ghost_color);
  }
  std::shared_ptr<ObjectController> CreateObjectController(int x_coordinate, int y_coordinate) override;
};