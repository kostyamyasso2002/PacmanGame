#include "objectController.h"

void PacManController::Move(int x, int y){
  pacman.Move(x, y);
}

void PacManController::food() {

}

void PacManController::gain() {

}

void GhostController::DoNextStep() {
  ghost.Move(1, 0);
}

void GhostController::food() {

}

void GhostController::gain() {

}
