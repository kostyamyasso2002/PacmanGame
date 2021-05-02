#include "objectCreator.h"

std::shared_ptr<Object> PacManCreator::CreateObject() {
    return std::make_shared<PacMan>(color_);
}

std::shared_ptr<Object> GhostCreator::CreateObject() {
    return std::make_shared<Ghost>(color_);
}