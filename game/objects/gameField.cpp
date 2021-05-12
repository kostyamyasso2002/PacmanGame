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
  map[pacman_->pacman_->x_coordinate][pacman_->pacman_->y_coordinate] = pacman_->pacman_->color_->color + "P" + pacman_->pacman_->color_->SetDefaultColor();
  for (auto x : map) {
    for (auto y : x) {
      drawer->AddString(y);
    }
  }
  drawer->flush();
  drawer->out();
}

int GameField::DoNextStep(Direction direction) {
  ++num;
  std::pair<int, int> diff = DirectionToCoords(direction);
  if (num % 2 == 0){
    ghost_group_->DoNextStep(cells_, pacman_->pacman_->x_coordinate, pacman_->pacman_->y_coordinate);
  }
  int pac_to_x = pacman_->pacman_->x_coordinate + diff.first;
  int pac_to_y = pacman_->pacman_->y_coordinate + diff.second;
  if (cells_[pac_to_x][pac_to_y]->CanMove()) {
    pacman_->Move(diff.first, diff.second);
    cells_[pac_to_x][pac_to_y] = cells_[pac_to_x][pac_to_y]->Interact(pacman_);
  }
  ghost_group_->InteractWithPacMan(pacman_);
  if (pacman_->food_eaten_ == 20) {
    return 1;
  }
  if (pacman_->pacman_->health_point == 0) {
    return 2;
  }
  return 0;
}