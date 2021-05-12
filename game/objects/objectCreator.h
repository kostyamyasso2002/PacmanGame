#include "object.h"
#include <memory>
#include "color.h"

#pragma once

class ObjectCreator {
 protected:
  std::shared_ptr<Color> color_;
 public:
  ObjectCreator(std::shared_ptr<Color> color) : color_(color) {}
  virtual std::shared_ptr<Object> CreateObject() = 0;
};

class PacManCreator : public ObjectCreator {
 public:
  PacManCreator(std::shared_ptr<Color> color) : ObjectCreator(color) {}
  std::shared_ptr<Object> CreateObject() override;
};

class GhostCreator : public ObjectCreator {
 public:
  GhostCreator(std::shared_ptr<Color> color) : ObjectCreator(color) {}
  std::shared_ptr<Object> CreateObject() override;
};