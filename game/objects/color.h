#pragma once
#include <iostream>

class Color {
 public:
  std::string color;
  virtual std::string GetName() = 0;
  std::string SetDefaultColor();
};

class White : public Color {
 public:
  White() {
    color = "\033[37m";
  }
  std::string GetName() override;
};

class Green : public Color {
 public:
  Green() {
    color = "\033[32m";
  }
  std::string GetName() override;
};

class Red : public Color {
 public:
  Red() {
    color = "\033[31m";
  }
  std::string GetName() override;
};