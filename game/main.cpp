#include "objects/object.h"
#include "objects/objectController.h"
#include "objects/ceil.h"
#include "objects/objectControllerCreator.h"
#include "objects/drawer.h"
#include "objects/gameField.h"

#include <thread>
#include <chrono>

std::vector<std::vector<std::shared_ptr<Cell>>> CreateField(int height, int width) {
  std::vector<std::vector<std::shared_ptr<Cell>>> ans;
  ans.assign(height, std::vector<std::shared_ptr<Cell>>(width));
  for (int i = 0; i < height; ++i) {
    for (int j = 0; j < width; ++j) {
      if (i == 0 || j == 0 || i == height - 1 || j == width - 1) {
        ans[i][j] = std::make_shared<Wall>();
      } else {
        ans[i][j] = std::make_shared<Empty>();
      }
    }
  }
  return ans;
}


int main() {
  /*PacManControllerCreator a;
  std::shared_ptr<PacManController> t = std::static_pointer_cast<PacManController>(a.CreateObjectController());
  t->Move(1, 2);
  std::cout << "Kostya loh";*/
  GameParameters parameters;
  PacManControllerCreator creator(parameters);
  GameField game_field(CreateField(10, 20), std::make_shared<GhostGroup>(), std::dynamic_pointer_cast<PacManController>(creator.CreateObjectController()));
  std::shared_ptr<SimpleDrawer> drawer = std::make_shared<BasicSimpleDrawer>();
  drawer = std::make_shared<SimpleDrawerDecoratorTitle>(drawer);
  for (int i = 0; i < 100; ++i) {

    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    game_field.DoNextStep(Direction::RIGHT);
    game_field.print(drawer);

   // drawer->out();
  }
  return 0;
}
