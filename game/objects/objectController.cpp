#include "objectController.h"
#include "ceil.h"
#include "strategy.h"
#include "complexity.h"

void PacManController::Move(int x, int y) {
  pacman_->Move(x, y);
}

std::shared_ptr<Cell> PacManController::food() {
  ++food_eaten_;
  return std::make_shared<Empty>();
}

void GhostController::DoNextStep(Direction direction) {
  if (stun_ == 0) {
    ghost_->Move(DirectionToCoords(direction).first, DirectionToCoords(direction).second);
  }
  if (stun_ > 0) {
    --stun_;
  }
}

std::shared_ptr<Cell> GhostController::food() {
  return std::make_shared<Food>();
}

GhostController::GhostController(const std::shared_ptr<Object>& ghost, Complexity complexity)
    : ghost_(std::dynamic_pointer_cast<Ghost>(ghost)) {
  if (complexity == Complexity::NORMAL) {
    strategy = std::make_shared<NormalStrategy>();
  }
  if (complexity == Complexity::HARD) {
    strategy = std::make_shared<HardStrategy>();
  }
}

bool GhostController::InteractWithPacMan(const std::shared_ptr<PacManController>& pacman) {
  if (pacman->GetXCoordinate() == ghost_->GetXCoordinate()
      && pacman->GetYCoordinate() == ghost_->GetYCoordinate() && stun_ == 0) {
    --pacman->pacman_->health_point;
    Stun(2);
    return true;
  }
  return false;
}

int PacManController::GetYCoordinate() {
  return pacman_->GetYCoordinate();
}

int PacManController::GetXCoordinate() {
  return pacman_->GetXCoordinate();
}

int GhostController::GetXCoordinate() {
  return ghost_->GetXCoordinate();
}

int GhostController::GetYCoordinate() {
  return ghost_->GetYCoordinate();
}

void GhostController::Stun(int time) {
  stun_ += time;
}

PacManController::PacManController(const std::shared_ptr<Object>& pacman)
    : pacman_(std::dynamic_pointer_cast<PacMan>(pacman)) {}

std::string PacManController::GetOutput() {
  return pacman_->color_->color + "P" + pacman_->color_->SetDefaultColor();
}
int PacManController::GetHealth() {
  return pacman_->health_point;
}

std::string GhostController::GetOutput() {
  return ghost_->color_->color + "G" + ghost_->color_->SetDefaultColor();
}