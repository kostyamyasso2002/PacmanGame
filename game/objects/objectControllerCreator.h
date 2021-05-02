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
  PacManControllerCreator() {
    creator = std::make_shared<PacManCreator>(parameters.pacman_color);
  }
  std::shared_ptr<ObjectController> CreateObjectController() override;
};

class GhostControllerCreator : public ObjectControllerCreator {
 public:
  GhostControllerCreator() {
    creator = std::make_shared<GhostCreator>(parameters.ghost_color);
  }
  std::shared_ptr<ObjectController> CreateObjectController() override;
};