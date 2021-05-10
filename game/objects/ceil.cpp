#include "ceil.h"

bool Movable::CanMove() {
  return true;
}

void Empty::Interact(std::shared_ptr<ObjectController> obj) {
 //тут пусто
}
std::string Empty::Output() {
  return " ";
}

std::string Wall::Output() {
  return "#";
}

bool Wall::CanMove() {
  return false;
}
void Wall::Interact(std::shared_ptr<ObjectController> obj) {

}
