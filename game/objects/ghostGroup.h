#pragma once
#include "objectController.h"
#include <vector>
#include <memory>
#include "ceil.h"
#include "complexity.h"

class GameField;

class GhostGroup {
 private:
  std::vector<std::shared_ptr<GhostController>> ghosts;
  Complexity complexity_;
 public:
  GhostGroup(Complexity complexity);

  void AddGhost(const std::shared_ptr<GhostController>& new_ghost);
  void DoNextStep(std::vector<std::vector<std::shared_ptr<Cell>>>&, int, int,
                  std::vector<std::vector<std::shared_ptr<Cell>>>& field);
  void ShowOnTheMap(std::vector<std::vector<std::string>>& map);
  void InteractWithPacMan(std::shared_ptr<PacManController> pacman);
  void StunEverybody(int time);
};