#include <memory>
#include <utility>
#include "object.h"
#pragma once

class Strategy;

class ObjectController {
 public:
  virtual void food() = 0;
  virtual void gain() = 0;

};

class PacManController : public ObjectController {
 public:
  PacManController(const std::shared_ptr<Object>& pacman): pacman_(std::dynamic_pointer_cast<PacMan>(pacman)) {}

  std::shared_ptr<PacMan> pacman_;
  void Move(int x, int y);
  void food() override;
  void gain() override;
};

class GhostController : public ObjectController {
 public:
  GhostController(const std::shared_ptr<Object>& ghost): ghost_(std::dynamic_pointer_cast<Ghost>(ghost)) {}
  std::shared_ptr<Ghost> ghost_;
  std::shared_ptr<Strategy> strategy;
  void DoNextStep(Direction direction);
  void food() override;
  void gain() override;
};