#pragma once
#include "ghostGroup.h"
#include <vector>
#include "ceil.h"
#include <memory>
#include "drawer.h"
#include "direction.h"

class GameField {
 private:
  std::vector<std::vector<std::shared_ptr<Cell>>> cells_;
  std::shared_ptr<GhostGroup> ghost_group_;
  std::shared_ptr<PacManController> pacman_;

 public:
  GameField(std::vector<std::vector<std::shared_ptr<Cell>>> cells, std::shared_ptr<GhostGroup> ghost_group, std::shared_ptr<PacManController> pacman) : cells_(cells),
                                                                                                     ghost_group_(ghost_group),
                                                                                                     pacman_(pacman) {}
  void DoNextStep(Direction direction);
  void print(std::shared_ptr<SimpleDrawer> drawer);
};
