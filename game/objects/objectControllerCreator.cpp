#include "objectControllerCreator.h"


std::shared_ptr<ObjectController> PacManControllerCreator::CreateObjectController() {
  return std::make_shared<PacManController>(creator->CreateObject());;
}

std::shared_ptr<ObjectController> GhostControllerCreator::CreateObjectController() {
    return std::make_shared<GhostController>(creator->CreateObject());
}