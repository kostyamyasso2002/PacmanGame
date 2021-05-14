#include "gameField.h"
#include "constants.h"

void GameField::print(std::shared_ptr<SimpleDrawer> drawer) {
  std::vector<std::vector<std::string>> map;
  for (auto& row : cells_) {
    std::vector<std::string> line;
    for (auto& cell : row) {
      line.push_back(cell->Output());
    }
    line.push_back("\n");
    map.push_back(line);
  }
  ghost_group_->ShowOnTheMap(map);
  map[pacman_->GetXCoordinate()][pacman_->GetYCoordinate()] = pacman_->GetOutput();
  for (auto& row : map) {
    for (auto& cell : row) {
      drawer->AddString(cell);
    }
  }
  drawer->flush();
  drawer->out();
}

GameState GameField::DoNextStep(Direction direction) {
  ++move_number;
  std::pair<int, int> diff = DirectionToCoords(direction);
  if (move_number % Constants::ghost_frequency == 0){
    ghost_group_->DoNextStep(cells_, pacman_->GetXCoordinate(), pacman_->GetYCoordinate(), cells_);
  }
  int pac_to_x = pacman_->GetXCoordinate() + diff.first;
  int pac_to_y = pacman_->GetYCoordinate() + diff.second;
  if (cells_[pac_to_x][pac_to_y]->CanMove()) {
    pacman_->Move(diff.first, diff.second);
    cells_[pac_to_x][pac_to_y] = cells_[pac_to_x][pac_to_y]->Interact(pacman_);
  }
  ghost_group_->InteractWithPacMan(pacman_);
  if (pacman_->food_eaten_ == food_amount) {
    return GameState::WIN;
  }
  if (pacman_->pacman_->health_point <= 0) {
    return GameState::LOSE;
  }
  return GameState::CONTINUE;
}

GameField::GameField(const std::vector<std::vector<std::shared_ptr<Cell>>>& cells,
          const std::shared_ptr<GhostGroup>& ghost_group,
          const std::shared_ptr<PacManController>& pacman): cells_(cells), ghost_group_(ghost_group), pacman_(pacman) {
  for (auto& row : cells) {
    for (auto & cell: row) {
      if (std::dynamic_pointer_cast<Food>(cell) != nullptr) {
        ++food_amount;
      }
    }
  }
}