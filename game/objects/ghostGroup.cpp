#include "ghostGroup.h"
#include "gameField.h"
#include "strategy.h"
#include <cassert>

void GhostGroup::ShowOnTheMap(std::vector<std::vector<std::string>>& map) {
  for (const auto& ghost : ghosts) {
    map[ghost->ghost_->x_coordinate][ghost->ghost_->y_coordinate] = ghost->ghost_->color_->color + "G" + ghost->ghost_->color_->SetDefaultColor();
  }
}
void GhostGroup::AddGhost(std::shared_ptr<GhostController> new_ghost) {
  //std::cerr << "OK";
  //assert(new_ghost != nullptr);
  //std::cout << ghosts.size() << std::endl;
  ghosts.push_back(new_ghost);
  //std::cerr << "LL";
}


void GhostGroup::DoNextStep(std::vector<std::vector<std::shared_ptr<Cell>>>& cells, int pac_x, int pac_y) {
  for (auto& ghost: ghosts) {
    Direction dir = ghost->strategy->ResolveNextStep(ghost->ghost_->x_coordinate, ghost->ghost_->y_coordinate, pac_x, pac_y);
    //Direction dir = Direction::LEFT;
    std::pair<int, int> diff = DirectionToCoords(dir);
    int gh_to_x = ghost->ghost_->x_coordinate + diff.first;
    int gh_to_y = ghost->ghost_->y_coordinate + diff.second;
    if (cells[gh_to_x][gh_to_y]->CanMove()) {
      ghost->DoNextStep(dir);
      cells[gh_to_x][gh_to_y] = cells[gh_to_x][gh_to_y]->Interact(ghost);
    }
  }
}

void GhostGroup::InteractWithPacMan(std::shared_ptr<PacManController> pacman) {
  for (auto& ghost: ghosts) {
    ghost->InteractWithPacMan(pacman);
  }
}
