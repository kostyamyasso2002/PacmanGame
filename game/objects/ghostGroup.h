#pragma once
#include "objectController.h"
#include <vector>
#include "ceil.h"

class GhostGroup {
private:
    std::vector<std::shared_ptr<GhostController>> ghosts;
public:
    void AddGhost();
    void DoNextStep();
    void ShowOnTheMap(std::vector<std::vector<std::string>>& map);
};