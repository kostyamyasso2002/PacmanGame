#include "objectController.h"
#include "objectCreator.h"

#pragma once

class ObjectControllerCreator {
 protected:
  std::shared_ptr<ObjectCreator> creator;
 public:
  virtual std::shared_ptr<ObjectController> CreateObjectController() = 0;
};

class PacManControllerCreator : public ObjectControllerCreator {
 public:
  PacManControllerCreator() {
    creator = std::make_shared<PacManCreator>();
  }
  std::shared_ptr<ObjectController> CreateObjectController() override;
};

class GhostControllerCreator : public ObjectControllerCreator {
 public:
  GhostControllerCreator() {
    creator = std::make_shared<GhostCreator>();
  }
  std::shared_ptr<ObjectController> CreateObjectController() override;
};