#include "objectCreator.h"

std::shared_ptr<Object> PacManCreator::CreateObject(int x_coordinate, int y_coordinate, int hp) {
    return std::make_shared<PacMan>(x_coordinate, y_coordinate, color_, hp);
}

std::shared_ptr<Object> GhostCreator::CreateObject(int x_coordinate, int y_coordinate, int hp) {
    return std::make_shared<Ghost>(x_coordinate, y_coordinate, color_);
}

ObjectCreator::ObjectCreator(std::shared_ptr<Color> color) : color_(color) {}

PacManCreator::PacManCreator(std::shared_ptr<Color> color) : ObjectCreator(color) {}

GhostCreator::GhostCreator(std::shared_ptr<Color> color) : ObjectCreator(color) {}