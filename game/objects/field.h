#include "direction.h"
#include "objectController.h"
#include "ceil.h"
#include <memory>
#include <vector>
#pragma once

class Field {
public:
    int w;
    int h;
    std::vector<std::vector<std::unique_ptr<Ceil>>> map;
    Field(int h, int w) : h(h), w(w) {
        std::vector<std::unique_ptr<Ceil>> a;
        for (int i = 0; i < w; ++i) {
            
        }
    }
};

class GameField {
public:
    Field field;
    std::unique_ptr<PacManController> pacman;
    std::vector<std::unique_ptr<GhostController>> ghosts;
    void DoNextIteration(Direction direction);
};
