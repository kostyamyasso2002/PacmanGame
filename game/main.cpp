#include "objects/object.h"
#include "objects/objectController.h"
#include "objects/ceil.h"
#include "objects/objectControllerCreator.h"

#include <thread>
#include <chrono>

int main() {
  PacManControllerCreator a;
  std::shared_ptr<PacManController> t = std::static_pointer_cast<PacManController>(a.CreateObjectController());
  return 0;
}
