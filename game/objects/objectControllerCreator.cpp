#include "objectControllerCreator.h"


std::shared_ptr<ObjectController> PacManControllerCreator::CreateObjectController(int x_coordinate, int y_coordinate) {
  return std::make_shared<PacManController>(creator->CreateObject(x_coordinate, y_coordinate));;
}

std::shared_ptr<ObjectController> GhostControllerCreator::CreateObjectController(int x_coordinate, int y_coordinate) {
    return std::make_shared<GhostController>(creator->CreateObject(x_coordinate, y_coordinate), parameters.complexity_);
}