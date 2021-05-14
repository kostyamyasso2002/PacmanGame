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
  White();
  std::string GetName() override;
};

class Green : public Color {
 public:
  Green();
  std::string GetName() override;
};

class Red : public Color {
 public:
  Red();
  std::string GetName() override;
};