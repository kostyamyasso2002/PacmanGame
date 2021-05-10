#pragma once
#include "gameField.h"

void GameField::print(std::shared_ptr<SimpleDrawer> drawer) {
  std::vector<std::vector<std::string>> map;
  for (auto x : cells_) {
    std::vector<std::string> line;
    for (auto y : x) {
      line.push_back(y->Output());
    }
    line.push_back("\n");
    map.push_back(line);
  }
  ghost_group_->ShowOnTheMap(map);
  map[pacman_->pacman_->x_coordinate][pacman_->pacman_->y_coordinate] = "P";
  for (auto x : map) {
    for (auto y : x) {
      drawer->AddString(y);
    }
  }
  drawer->out();
}

void GameField::DoNextStep(Direction direction) {
  std::pair<int, int> diff = DirectionToCoords(direction);
  pacman_->Move(diff.first, diff.second);
}