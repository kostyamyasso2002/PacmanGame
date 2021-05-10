#include "objectCreator.h"

std::shared_ptr<Object> PacManCreator::CreateObject() {
    return std::make_shared<PacMan>(1, 1, color_);
}

std::shared_ptr<Object> GhostCreator::CreateObject() {
    return std::make_shared<Ghost>(1, 1, color_);
}