#include "direction.h"
#include "objectController.h"
#include "ceil.h"
#include "drawer.h"
#include <memory>
#include <vector>

#pragma once

class Field {
 public:
  int w;
  int h;
  std::vector<std::vector<std::shared_ptr<Ceil>>> map;


  Field(int h, int w): h(h), w(w) {
    for (int i = 0; i < h; ++i) {
      std::vector<std::shared_ptr<Ceil>> a;
      for (int i = 0; i < w; ++i) {
        a.push_back(std::make_shared<Empty>());
      }
      map.push_back(a);
    }
  }
};

class GameField {
 public:
  Field field;
  int w;
  int h;
  std::unique_ptr<PacManController> pacman;
 // std::vector<std::unique_ptr<GhostController>> ghosts;
  void DoNextIteration(Direction direction) {
    pacman->move(1, 0);
  }

  GameField(int h, int w): h(h), w(w), field(h, w) {
    pacman = std::make_unique<PacManController>();
  }

  void AddToDrawer(Drawer& drawer) {
    drawer.ChangeSymbol(pacman->pacman.XCoordinate, pacman->pacman.YCoordinate, '&', Color());
  }
};
