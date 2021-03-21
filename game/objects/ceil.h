#include "objectController.h"
#include <memory>

#pragma once

class Ceil {
 public:
  virtual void Interact(std::unique_ptr<ObjectController> obj) = 0;
  virtual bool CanMove(std::unique_ptr<ObjectController> obj) = 0;
};

class Movable : public Ceil {
  virtual bool CanMove(std::unique_ptr<ObjectController> obj) override;
};

class Empty : public Movable {
  void Interact(std::unique_ptr<ObjectController> obj) override;
};

class Food : public Movable {

};

class Power : public Movable {

};

class Wall : public Ceil {
  bool CanMove(std::unique_ptr<ObjectController> obj) override;
};