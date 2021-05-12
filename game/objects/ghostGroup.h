#pragma once
#include "objectController.h"
#include <vector>
#include <memory>
#include "ceil.h"

class GameField;

class GhostGroup {
private:
    std::vector<std::shared_ptr<GhostController>> ghosts;
public:
    void AddGhost(std::shared_ptr<GhostController> new_ghost);
    void DoNextStep(std::vector<std::vector<std::shared_ptr<Cell>>>&, int, int);
    void ShowOnTheMap(std::vector<std::vector<std::string>>& map);
    void InteractWithPacMan(std::shared_ptr<PacManController> pacman);
};