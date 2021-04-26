#include "objects/object.h"
#include "objects/objectController.h"
#include "objects/ceil.h"
#include "objects/objectControllerCreator.h"
#include "objects/drawer.h"

#include <thread>
#include <chrono>

int main() {
  PacManControllerCreator a;
  std::shared_ptr<PacManController> t = std::static_pointer_cast<PacManController>(a.CreateObjectController());
  t->Move(1, 2);
  std::shared_ptr<SimpleDrawer> b = std::make_shared<BasicSimpleDrawer>();
  std::shared_ptr<SimpleDrawer> kek = std::make_shared<SimpleDrawerDecoratorA>(b);
  std::shared_ptr<SimpleDrawer> lol = std::make_shared<SimpleDrawerDecoratorA>(kek);

  lol->AddString("lol");
  lol->out();


  return 0;
}
