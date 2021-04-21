#include "objectControllerCreator.h"

//#pragma once

std::shared_ptr<ObjectController> PacManControllerCreator::CreateObjectController() {
  auto x = std::make_shared<PacManController>(creator->CreateObject());
  return x;
}

std::shared_ptr<ObjectController> GhostControllerCreator::CreateObjectController() {
    return std::make_shared<GhostController>(creator->CreateObject());
}