#include "field.h"

Field::Field(int height, int width): height_(height), width_(width) {
  for (int i = 0; i < height_; ++i) {
    std::vector<std::shared_ptr<Ceil>> a;
    for (int j = 0; j < width_; ++j) {
      a.push_back(std::make_shared<Empty>());
    }
    map.push_back(a);
  }
}

void GameField::DoNextIteration(Direction direction) {
  pacman->Move(DirectionToCoords(direction).first, DirectionToCoords(direction).second);
  for (std::shared_ptr<GhostController>& ghost: ghosts) {
    ghost->ghost.Move(DirectionToCoords(direction).first, DirectionToCoords(direction).second);
  }
}

GameField::GameField(int height, int width): height_(height), width_(width), field(height, width) {
  pacman = std::make_shared<PacManController>();
  ghosts.push_back(std::make_shared<GhostController>());
}

void GameField::AddToDrawer(Drawer& drawer) {
  drawer.ChangeSymbol(pacman->pacman.XCoordinate, pacman->pacman.YCoordinate, '&', Color());
  for (std::shared_ptr<GhostController>& ghost: ghosts) {
    drawer.ChangeSymbol(ghost->ghost.XCoordinate, ghost->ghost.YCoordinate, '*', Color());
  }
}