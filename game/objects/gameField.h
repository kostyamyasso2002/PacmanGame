#pragma once

#include "ghostGroup.h
#include "ceil.h"
#include "object.h"

class GameField {
 private:
  GhostGroup ghosts;
  std::vector<std::vector<Ceil>> cells;
  PacMan pacman;
 public:
  GameField(GhostGroup ghosts, std::vector<std::vector<Ceil>> cells, PacMan pacman);
  void DoNextStep();
};