#include "objectController.h"
#include <memory>

#pragma once

class Cell {
 public:
  virtual void Interact(std::shared_ptr<ObjectController> obj) = 0;
  virtual bool CanMove() = 0;
  virtual std::string Output() = 0;
};

class Movable : public Cell {
  bool CanMove() override;
};

class Empty : public Movable {
  void Interact(std::shared_ptr<ObjectController> obj) override;
  std::string Output() override;
};

class Food : public Movable {

};

class Power : public Movable {

};

class Wall : public Cell {
  bool CanMove() override;
  void Interact(std::shared_ptr<ObjectController> obj) override;
  std::string Output() override;
};
