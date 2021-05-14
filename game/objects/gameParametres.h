#pragma once
#include "complexity.h"
#include "color.h"
#include <memory>

class GameParameters {
 public:
  std::shared_ptr<Color> pacman_color;
  std::shared_ptr<Color> ghost_color;
  Complexity complexity_;
  GameParameters();
  GameParameters(const std::shared_ptr<Color>& pacman_color,
                 const std::shared_ptr<Color>& ghost_color,
                 Complexity complexity);
};