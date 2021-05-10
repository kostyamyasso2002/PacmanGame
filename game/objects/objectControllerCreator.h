#include <utility>

#include "objectController.h"
#include "objectCreator.h"
#include "gameParametres.h"

#pragma once

class ObjectControllerCreator {
 protected:
  std::shared_ptr<ObjectCreator> creator;
  GameParameters parameters;
 public:
  virtual std::shared_ptr<ObjectController> CreateObjectController() = 0;
};

class PacManControllerCreator : public ObjectControllerCreator {
 public:
  PacManControllerCreator(GameParameters param) {
    parameters = std::move(param);
    creator = std::make_shared<PacManCreator>(parameters.pacman_color);
  }
  std::shared_ptr<ObjectController> CreateObjectController() override;
};

class GhostControllerCreator : public ObjectControllerCreator {
 public:
  GhostControllerCreator(GameParameters param) {
    parameters = param;
    creator = std::make_shared<GhostCreator>(parameters.ghost_color);
  }
  std::shared_ptr<ObjectController> CreateObjectController() override;
};