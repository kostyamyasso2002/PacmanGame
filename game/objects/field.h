#include "direction.h"
#include "objectController.h"
#include "ceil.h"
#include "drawer.h"
#include <memory>
#include <vector>

#pragma once

class Field {
 public:
  int width;
  int height;
  std::vector<std::vector<std::shared_ptr<Ceil>>> map;


  Field(int height, int width): height(height), width(width) {
    for (int i = 0; i < height; ++i) {
      std::vector<std::shared_ptr<Ceil>> a;
      for (int j = 0; j < width; ++j) {
        a.push_back(std::make_shared<Empty>());
      }
      map.push_back(a);
    }
  }
};

class GameField {
 public:
  Field field;
  int width;
  int height;
  std::unique_ptr<PacManController> pacman;
 // std::vector<std::unique_ptr<GhostController>> ghosts;
  void DoNextIteration(Direction direction) {
    pacman->Move(DirectionToCoords(direction).first, DirectionToCoords(direction).second);
  }

  GameField(int height, int width): height(height), width(width), field(height, width) {
    pacman = std::make_unique<PacManController>();
  }

  void AddToDrawer(Drawer& drawer) {
    drawer.ChangeSymbol(pacman->pacman.XCoordinate, pacman->pacman.YCoordinate, '&', Color());
  }
};
