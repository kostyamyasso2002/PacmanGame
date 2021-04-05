#include "objectCreator.h"

#pragma once

std::shared_ptr<Object> PacManCreator::CreateObject() {
    return std::make_shared<PacMan>();
}

std::shared_ptr<Object> GhostCreator::CreateObject() {
    return std::make_shared<Ghost>();
}