#include <memory>
#include <utility>
#include "object.h"
#pragma once

class Strategy;
class Cell;

class ObjectController {
 public:
  virtual std::shared_ptr<Cell> food() = 0;
  virtual void gain() = 0;

};

class PacManController : public ObjectController {
 public:
  PacManController(const std::shared_ptr<Object>& pacman): pacman_(std::dynamic_pointer_cast<PacMan>(pacman)) {}

  std::shared_ptr<PacMan> pacman_;
  int food_eaten_ = 0;
  void Move(int x, int y);
  std::shared_ptr<Cell> food() override;
  void gain() override;
};

class GhostController : public ObjectController {
 public:
  GhostController(const std::shared_ptr<Object>& ghost);
  std::shared_ptr<Ghost> ghost_;
  int stun_ = 0;
  std::shared_ptr<Strategy> strategy;
  void DoNextStep(Direction direction);
  std::shared_ptr<Cell> food() override;
  void gain() override;
  void InteractWithPacMan(std::shared_ptr<PacManController>);
};