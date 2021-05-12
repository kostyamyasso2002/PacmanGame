#include "objectCreator.h"

std::shared_ptr<Object> PacManCreator::CreateObject(int x_coordinate, int y_coordinate) {
    return std::make_shared<PacMan>(x_coordinate, y_coordinate, color_);
}

std::shared_ptr<Object> GhostCreator::CreateObject(int x_coordinate, int y_coordinate) {
    return std::make_shared<Ghost>(x_coordinate, y_coordinate, color_);
}