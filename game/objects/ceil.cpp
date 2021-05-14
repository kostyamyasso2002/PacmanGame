#include "ceil.h"

bool Movable::CanMove() {
  return true;
}

std::shared_ptr<Cell> Empty::Interact(std::shared_ptr<ObjectController> obj) {
 //тут пусто

  return std::make_shared<Empty>();
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
std::shared_ptr<Cell> Wall::Interact(std::shared_ptr<ObjectController> obj) {
  return std::make_shared<Wall>();
}


std::shared_ptr<Cell> Food::Interact(std::shared_ptr<ObjectController> obj) {
  return obj->food();
}
std::string Food::Output() {
  return ".";
}
