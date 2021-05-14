#include "gameParametres.h"

GameParameters::GameParameters() {
  pacman_color = std::make_shared<Red>();
  ghost_color = std::make_shared<White>();
  complexity_ = Complexity::NORMAL;
}

GameParameters::GameParameters(const std::shared_ptr<Color>& pacman_color,
                               const std::shared_ptr<Color>& ghost_color,
                               Complexity complexity)
    : pacman_color(pacman_color), ghost_color(ghost_color), complexity_(complexity) {}