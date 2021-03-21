#include "objects/object.h"
#include "objects/objectController.h"
#include "objects/ceil.h"
#include "objects/strategy.h"
#include "objects/field.h"
#include "objects/drawer.h"

#pragma "once"

int main() {
  GameField a(25, 50);
  Drawer b(25 ,50);
  a.AddToDrawer(b);
  b.Print();
  return 0;
}
