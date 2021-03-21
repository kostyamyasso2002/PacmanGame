#include "direction.h"
#include "objectController.h"
#include "ceil.h"
#include "drawer.h"
#include <memory>
#include <vector>

#pragma once

class Field {
 public:
  int width_;
  int height_;
  std::vector<std::vector<std::shared_ptr<Ceil>>> map;


  Field(int height, int width);
};

class GameField {
 public:
  Field field;
  int width_;
  int height_;
  std::unique_ptr<PacManController> pacman;
 // std::vector<std::unique_ptr<GhostController>> ghosts;
  void DoNextIteration(Direction direction);

  GameField(int height, int width);

  void AddToDrawer(Drawer& drawer);
};
