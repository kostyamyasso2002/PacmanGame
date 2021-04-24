#pragma once
#include "objectController.h"
#include <vector>

class GhostGroup {
private:
    std::vector<GhostController> ghosts;
public:
    void AddGhost();
    void DoNextStep();
};