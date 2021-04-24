#pragma once
#include <string>

class SimpleDrawer {
 public:
  virtual void AddString(std::string str) = 0;
  virtual void out() = 0;
};

class BasicSimpleDrawer : public SimpleDrawer {
 private:
  std::string buffer;
 public:
  void AddString(std::string str) override;
  void out() override;
};

class SimpleDrawerDecorator : public SimpleDrawer {
 private:
  SimpleDrawer wrappee;
 public:
  void AddString(std::string str) override;
  void out() override;
};

class SimpleDrawerDecoratorA : public SimpleDrawerDecorator {
 public:
  void out() override;
};

class SimpleDrawerDecoratorB : public SimpleDrawerDecorator {
 public:
  void out() override;
};