#include "drawer.h"
#include "objectController.h"

void BasicSimpleDrawer::AddString(std::string str) {
  buffer_ += str;
}

void BasicSimpleDrawer::out() {
  std::cout << buffer_ << std::endl;
  buffer_ = "";
}

SimpleDrawerDecorator::SimpleDrawerDecorator(std::shared_ptr<SimpleDrawer>& wrappee) : wrappee(wrappee) {}

void SimpleDrawerDecorator::AddString(std::string str) {
  wrappee->AddString(str);
}

void SimpleDrawerDecorator::out() {
  wrappee->out();
}

SimpleDrawerDecoratorTitle::SimpleDrawerDecoratorTitle(std::shared_ptr<SimpleDrawer>& wrappee) : SimpleDrawerDecorator(wrappee) {}

void SimpleDrawerDecoratorTitle::out() {
  std::cout << "--------PACMAN---------\n";
  wrappee->out();
}

SimpleDrawerDecoratorRules::SimpleDrawerDecoratorRules(std::shared_ptr<SimpleDrawer>& wrappee) : SimpleDrawerDecorator(wrappee) {}

void SimpleDrawerDecoratorRules::out() {
  wrappee->out();
  // output of Rules
}
SimpleDrawerDecoratorHealth::SimpleDrawerDecoratorHealth(std::shared_ptr<SimpleDrawer>& wrappee, const std::shared_ptr<PacManController>& pacman)
    : SimpleDrawerDecorator(wrappee), pacman(pacman) {
}

void SimpleDrawerDecoratorHealth::out() {
  wrappee->out();
  std::cout << "hp: " << pacman->pacman_->health_point << std::endl;
}

void SimpleDrawer::flush() {
  system("clear");
}
