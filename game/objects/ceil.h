#include "objectController.h"
#include <memory>

#pragma once

class Cell {
 public:
  virtual std::shared_ptr<Cell> Interact(std::shared_ptr<ObjectController> obj) = 0;
  virtual bool CanMove() = 0;
  virtual std::string Output() = 0;
};

class Movable : public Cell {
  bool CanMove() override;
};

class Empty : public Movable {
  std::shared_ptr<Cell> Interact(std::shared_ptr<ObjectController> obj) override;
  std::string Output() override;
};

class Food : public Movable {
  std::shared_ptr<Cell> Interact(std::shared_ptr<ObjectController> obj) override;
  std::string Output() override;
};

class Power : public Movable {

};

class Wall : public Cell {
  bool CanMove() override;
  std::shared_ptr<Cell> Interact(std::shared_ptr<ObjectController> obj) override;
  std::string Output() override;
};
