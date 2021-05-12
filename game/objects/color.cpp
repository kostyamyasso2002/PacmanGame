#include "color.h"

std::string Color::SetDefaultColor() {
  return "\033[0m";
}

std::string White::GetName() {
  return "White";
}

std::string Red::GetName() {
  return "Red";
}

std::string Green::GetName() {
  return "Green";
}