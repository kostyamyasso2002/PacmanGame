#pragma once
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

SimpleDrawerDecoratorA::SimpleDrawerDecoratorA(std::shared_ptr<SimpleDrawer>& wrappee) : SimpleDrawerDecorator(wrappee) {}

void SimpleDrawerDecoratorA::out() {
  std::cout << "KEK" << std::endl;
  wrappee->out();
}

SimpleDrawerDecoratorB::SimpleDrawerDecoratorB(std::shared_ptr<SimpleDrawer>& wrappee) : SimpleDrawerDecorator(wrappee) {}

void SimpleDrawerDecoratorB::out() {
  std::cout << "LOL\n";
  wrappee->out();
}