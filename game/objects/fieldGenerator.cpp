#include "fieldGenerator.h"
#include "objectControllerCreator.h"

std::vector<std::vector<std::shared_ptr<Cell>>> FieldGenerator::CreateEmptyField(int height,
                                                                                 int width) {
  std::vector<std::vector<std::shared_ptr<Cell>>> ans;
  ans.assign(height, std::vector<std::shared_ptr<Cell>>(width));
  for (int i = 0; i < height; ++i) {
    for (int j = 0; j < width; ++j) {
      if (i == 0 || j == 0 || i == height - 1 || j == width - 1) {
        ans[i][j] = std::make_shared<Wall>();
      } else {
        ans[i][j] = std::make_shared<Food>();
      }
    }
  }
  return ans;
}

std::shared_ptr<GameField> FieldGenerator::GenerateSimpleField(const GameParameters& parameters) {
  const int height = 15;
  const int width = 30;

  PacManControllerCreator pacman_creator(parameters);
  GhostControllerCreator ghost_creator(parameters);

  std::shared_ptr<GhostGroup> group = std::make_shared<GhostGroup>(parameters.complexity_);

  if (parameters.complexity_ == Complexity::NORMAL) {
    group->AddGhost(std::dynamic_pointer_cast<GhostController>(ghost_creator.CreateObjectController(
        height - 2,
        width - 2)));
  } else {
    group->AddGhost(std::dynamic_pointer_cast<GhostController>(ghost_creator.CreateObjectController(
        height - 2,
        width - 2)));
    group->AddGhost(std::dynamic_pointer_cast<GhostController>(ghost_creator.CreateObjectController(
        1,
        width - 2)));
  }

  std::shared_ptr<PacManController> pac =
      std::dynamic_pointer_cast<PacManController>(pacman_creator.CreateObjectController(1, 1));
  return std::make_shared<GameField>(CreateEmptyField(height, width), group, pac);
}
