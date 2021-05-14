#include "ghostGroup.h"
#include "gameField.h"
#include "strategy.h"
#include "constants.h"
#include <cassert>

void GhostGroup::ShowOnTheMap(std::vector<std::vector<std::string>>& map) {
  for (const auto& ghost : ghosts) {
    map[ghost->GetXCoordinate()][ghost->GetYCoordinate()] = ghost->GetOutput();
  }
}
void GhostGroup::AddGhost(const std::shared_ptr<GhostController>& new_ghost) {
  ghosts.push_back(new_ghost);
}

void GhostGroup::DoNextStep(std::vector<std::vector<std::shared_ptr<Cell>>>& cells,
                            int pac_x,
                            int pac_y, std::vector<std::vector<std::shared_ptr<Cell>>>& field) {
  for (auto& ghost: ghosts) {
    Direction dir = ghost->strategy->ResolveNextStep(field, ghost->GetXCoordinate(),
                                                     ghost->GetYCoordinate(),
                                                     pac_x,
                                                     pac_y);
    std::pair<int, int> diff = DirectionToCoords(dir);
    int gh_to_x = ghost->GetXCoordinate() + diff.first;
    int gh_to_y = ghost->GetYCoordinate() + diff.second;
    if (cells[gh_to_x][gh_to_y]->CanMove()) {
      ghost->DoNextStep(dir);
      cells[gh_to_x][gh_to_y] = cells[gh_to_x][gh_to_y]->Interact(ghost);
    }
  }
}

void GhostGroup::InteractWithPacMan(std::shared_ptr<PacManController> pacman) {
  bool meeting_happened = false;
  for (auto& ghost: ghosts) {
    meeting_happened |= ghost->InteractWithPacMan(pacman);
  }
  if (meeting_happened) {
    if (complexity_ == Complexity::NORMAL) {
      StunEverybody(Constants::normal_stun_time);
    }
    switch (complexity_) {
      case Complexity::NORMAL: StunEverybody(Constants::normal_stun_time);
      case Complexity::HARD: StunEverybody(Constants::hard_stun_time);
    }
  }
}

void GhostGroup::StunEverybody(int time) {
  for (auto& ghost: ghosts) {
    ghost->Stun(time);
  }
}

GhostGroup::GhostGroup(Complexity complexity) : complexity_(complexity) {}