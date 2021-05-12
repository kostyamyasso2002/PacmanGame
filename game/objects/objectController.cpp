#include "objectController.h"
#include "ceil.h"
#include "strategy.h"

void PacManController::Move(int x, int y) {
  pacman_->Move(x, y);
}

std::shared_ptr<Cell> PacManController::food() {
  ++food_eaten_;
  return std::make_shared<Empty>();
}

void PacManController::gain() {

}

void GhostController::DoNextStep(Direction direction) {
  if (stun_ == 0) {
    ghost_->Move(DirectionToCoords(direction).first, DirectionToCoords(direction).second);
  }
  if (stun_ > 0){
    --stun_;
  }
}

std::shared_ptr<Cell> GhostController::food() {
  return std::make_shared<Food>();
}

void GhostController::gain() {

}
GhostController::GhostController(const std::shared_ptr<Object>& ghost):ghost_(std::dynamic_pointer_cast<Ghost>(ghost)), strategy(std::make_shared<EasyStrategy>()) {}

void GhostController::InteractWithPacMan(std::shared_ptr<PacManController> pacman) {
  if (pacman->pacman_->x_coordinate == ghost_->x_coordinate && pacman->pacman_->y_coordinate == ghost_->y_coordinate && stun_ == 0) {
    --pacman->pacman_->health_point;
    stun_ += 2;
  }
}
