#pragma once
#include "complexity.h"
#include "color.h"

class GameParameters {
 public:
  Color pacman_color;
  Color ghost_color;

  Complexity complexity_;
};