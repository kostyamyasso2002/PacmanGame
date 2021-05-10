#pragma once
#include "ghostGroup.h"

void GhostGroup::ShowOnTheMap(std::vector<std::vector<std::string>>& map) {
  for (auto ghost : ghosts) {
    map[ghost->ghost_->x_coordinate][ghost->ghost_->y_coordinate] = "G";
  }
}