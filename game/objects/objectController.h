#include <memory>
#include <utility>
#include "object.h"
#include "complexity.h"
#pragma once

class Strategy;
class Cell;

class ObjectController {
 public:
  virtual std::shared_ptr<Cell> food() = 0;
  virtual std::string GetOutput() = 0;
};

class PacManController : public ObjectController {
 public:
  PacManController(const std::shared_ptr<Object>& pacman);

  std::shared_ptr<PacMan> pacman_;
  int food_eaten_ = 0;
  void Move(int x, int y);
  std::shared_ptr<Cell> food() override;
  int GetXCoordinate();
  int GetYCoordinate();
  std::string GetOutput() override;
  int GetHealth();
};

class GhostController : public ObjectController {
 public:
  GhostController(const std::shared_ptr<Object>& ghost, Complexity);
  std::shared_ptr<Ghost> ghost_;
  int stun_ = 0;

  void Stun(int time);
  std::shared_ptr<Strategy> strategy;
  void DoNextStep(Direction direction);
  std::shared_ptr<Cell> food() override;
  bool InteractWithPacMan(const std::shared_ptr<PacManController>&);
  int GetXCoordinate();
  int GetYCoordinate();
  std::string GetOutput() override;
};