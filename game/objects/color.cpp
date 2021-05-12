#include "color.h"

std::string Color::SetDefaultColor() {
  return "\033[0m";
}

std::string White::GetName() {
  return "White";
}
White::White() {
  color = "\033[37m";
}

std::string Red::GetName() {
  return "Red";
}
Red::Red() {
  color = "\033[31m";
}

std::string Green::GetName() {
  return "Green";
}
Green::Green() {
  color = "\033[32m";
}
