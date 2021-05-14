#pragma once
#include <string>
#include <memory>
#include <iostream>

class PacManController;

class SimpleDrawer {
 public:
  virtual void AddString(std::string str) = 0;
  virtual void out() = 0;
  static void flush();
  virtual ~SimpleDrawer() = default;
};

class BasicSimpleDrawer : public SimpleDrawer {
 private:
  std::string buffer_;
 public:
  void AddString(std::string str) override;
  void out() override;
};

class SimpleDrawerDecorator : public SimpleDrawer {
 protected:
  std::shared_ptr<SimpleDrawer> wrappee;
 public:
  SimpleDrawerDecorator(std::shared_ptr<SimpleDrawer>& wrappee);
  void AddString(std::string str) override;
  void out() override;
};

class SimpleDrawerDecoratorTitle : public SimpleDrawerDecorator {
 public:
  SimpleDrawerDecoratorTitle(std::shared_ptr<SimpleDrawer>& wrappee);
  void out() override;
};

class SimpleDrawerDecoratorRules : public SimpleDrawerDecorator {
 public:
  SimpleDrawerDecoratorRules(std::shared_ptr<SimpleDrawer>& wrappee);
  void out() override;
};

class SimpleDrawerDecoratorHealth: public SimpleDrawerDecorator {
 private:
  std::shared_ptr<PacManController> pacman;
 public:
  SimpleDrawerDecoratorHealth(std::shared_ptr<SimpleDrawer>& wrappee, const std::shared_ptr<PacManController>& pacman);
  void out() override;
};
