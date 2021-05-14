#include "objectControllerCreator.h"
#include "constants.h"

std::shared_ptr<ObjectController> PacManControllerCreator::CreateObjectController(int x_coordinate,
                                                                                  int y_coordinate) {
  int hp = Constants::normal_pacman_health;
  if (parameters.complexity_ == Complexity::HARD)
    hp = Constants::hard_pacman_health;
  return std::make_shared<PacManController>(creator->CreateObject(x_coordinate, y_coordinate, hp));
}

std::shared_ptr<ObjectController> GhostControllerCreator::CreateObjectController(int x_coordinate,
                                                                                 int y_coordinate) {
  return std::make_shared<GhostController>(creator->CreateObject(x_coordinate, y_coordinate),
                                           parameters.complexity_);
}

PacManControllerCreator::PacManControllerCreator(const GameParameters& param) {
  parameters = param;
  creator = std::make_shared<PacManCreator>(parameters.pacman_color);
}

GhostControllerCreator::GhostControllerCreator(const GameParameters& param) {
  parameters = param;
  creator = std::make_shared<GhostCreator>(parameters.ghost_color);
}