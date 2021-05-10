#include "drawer.h"

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
  system("clear");
  std::cout << "--------PACMAN---------\n";
  wrappee->out();
}

SimpleDrawerDecoratorRules::SimpleDrawerDecoratorRules(std::shared_ptr<SimpleDrawer>& wrappee) : SimpleDrawerDecorator(wrappee) {}

void SimpleDrawerDecoratorRules::out() {
  wrappee->out();
  // output of Rules
}
