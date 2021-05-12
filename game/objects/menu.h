#pragma once
#include <vector>
#include <memory>
#include "ceil.h"
#include "gameParametres.h"
#include "objectCreator.h"
#include "objectControllerCreator.h"
#include "gameField.h"

class Menu {
 private:
  std::vector<std::vector<std::shared_ptr<Cell>>> CreateField(int height, int width);
  std::shared_ptr<Color> pacman_color_;
  std::shared_ptr<Color> ghost_color_;
  Complexity complexity_;
  void SetPacmanColor();
  void SetGhostColor();
 public:
  void Start();
  void Game();
  void Settings();
  Menu() {
    pacman_color_ = std::make_shared<White>();
    ghost_color_ = std::make_shared<White>();
    complexity_ = Complexity::NORMAL;
  }
};