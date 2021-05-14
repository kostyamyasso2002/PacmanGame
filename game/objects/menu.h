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
  GameParameters parameters_;
  void SetPacmanColor();
  void SetGhostColor();
  void ChangeComplexity();
 public:
  void Start();
  void Game();
  void Settings();
  GameState DoStep(std::shared_ptr<GameField> game_field, std::shared_ptr<SimpleDrawer> drawer);
};