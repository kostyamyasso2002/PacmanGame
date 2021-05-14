#include <memory>
#include "gameField.h"
#include "gameParametres.h"

#pragma once

class FieldGenerator {
 private:
  static std::vector<std::vector<std::shared_ptr<Cell>>> CreateEmptyField(int height, int width);
 public:
  static std::shared_ptr<GameField> GenerateSimpleField(const GameParameters& parameters);
};
