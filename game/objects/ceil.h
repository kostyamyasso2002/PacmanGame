#include "objectController.h"
#include <memory>

#pragma once

class Cell {
 public:
  virtual void Interact(std::shared_ptr<ObjectController> obj) = 0;
  virtual bool CanMove(std::shared_ptr<ObjectController> obj) = 0;
};

class Movable : public Cell {
  virtual bool CanMove(std::shared_ptr<ObjectController> obj) override;
};

class Empty : public Movable {
  void Interact(std::shared_ptr<ObjectController> obj) override;
};

class Food : public Movable {

};

class Power : public Movable {

};

class Wall : public Cell {
  bool CanMove(std::shared_ptr<ObjectController> obj) override;
};