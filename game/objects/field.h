#include "direction.h"
#include "objectController.h"
#include "ceil.h"
#include <memory>
#include <vector>
#pragma once

class Field {
public:
    std::vector<std::vector<Ceil>> map;
};

class GameField {
public:
    Field field;
    std::unique_ptr<PacManController> pacman;
    std::vector<std::unique_ptr<GhostController>> ghosts;
    void DoNextIteration(Direction direction);
};
