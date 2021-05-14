#pragma once
#include "ghostGroup.h"
#include <vector>
#include "ceil.h"
#include <memory>
#include "drawer.h"
#include "direction.h"
#include "gameState.h"

class GameField {
 private:
  std::vector<std::vector<std::shared_ptr<Cell>>> cells_;
  std::shared_ptr<GhostGroup> ghost_group_;
  std::shared_ptr<PacManController> pacman_;
  int move_number = 0;
  int food_amount = 0;
  friend class GhostGroup;
  friend class HardStrategy;
 public:
  GameField(const std::vector<std::vector<std::shared_ptr<Cell>>>& cells,
            const std::shared_ptr<GhostGroup>& ghost_group,
            const std::shared_ptr<PacManController>& pacman);
  GameState DoNextStep(Direction direction);
  void print(std::shared_ptr<SimpleDrawer> drawer);
};
