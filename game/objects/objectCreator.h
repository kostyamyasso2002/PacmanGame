#include "object.h"
#include <memory>
#include "color.h"

#pragma once

class ObjectCreator {
 protected:
  Color color_;
 public:
  ObjectCreator(Color color) : color_(color) {}
  virtual std::shared_ptr<Object> CreateObject() = 0;
};

class PacManCreator : public ObjectCreator {
 public:
  PacManCreator(Color color) : ObjectCreator(color) {}
  std::shared_ptr<Object> CreateObject() override;
};

class GhostCreator : public ObjectCreator {
 public:
  GhostCreator(Color color) : ObjectCreator(color) {}
  std::shared_ptr<Object> CreateObject() override;
};