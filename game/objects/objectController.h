#include <memory>

#pragma once

class Strategy;

class ObjectController {
 public:
  virtual void food() = 0;
  virtual void gain() = 0;
};

class PacManController : public ObjectController {
 public:
  PacMan pacman;
  void move(int x, int y);
  virtual void food() override {}
  virtual void gain() override {}
};

class GhostController : public ObjectController {
 public:
  Ghost ghost;
  std::unique_ptr<Strategy> strategy;
  void DoNextStep();
};