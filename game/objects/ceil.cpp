#include "ceil.h"

void Empty::Interact(std::unique_ptr<ObjectController> obj) {

}


bool Movable::CanMove(std::unique_ptr<ObjectController> obj) {
  return true;
}

bool Wall::CanMove(std::unique_ptr<ObjectController> obj) {
  return false;
}
