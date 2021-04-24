#include "objects/object.h"
#include "objects/objectController.h"
#include "objects/ceil.h"
#include "objects/objectControllerCreator.h"

#include <thread>
#include <chrono>

int main() {
  PacManControllerCreator a;
  std::shared_ptr<PacManController> t = std::static_pointer_cast<PacManController>(a.CreateObjectController());
  t->Move(1, 2);
  return 0;
}
