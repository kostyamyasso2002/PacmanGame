#include "color.h"
#include <iostream>
#include <vector>

#pragma once

class Drawer {
 public:
  int width_;
  int height_;
  std::vector<std::vector<char>> field;
  std::vector<std::vector<Color>> color;
  void ChangeSymbol(int x, int y, char newChar, Color newColor);
  void Print();

  Drawer(int height, int width);

  void Flush();
};
