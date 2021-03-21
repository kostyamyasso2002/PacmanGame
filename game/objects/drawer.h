#include "color.h"
#include <iostream>
#include <vector>

#pragma once

class Drawer {
 public:
  int w;
  int h;
  std::vector<std::vector<char>> field;
  std::vector<std::vector<Color>> color;
  void ChangeSymbol(int x, int y, char newChar, Color newColor);
  void Print();

  Drawer(int h, int w): h(h), w(w) {
    color.resize(h, std::vector<Color>(w));
    field.resize(h, std::vector<char>(w, '.'));
  }
};

void Drawer::ChangeSymbol(int x, int y, char newChar, Color newColor) {
  field[x][y] = newChar;
  color[x][y] = newColor;
}

void Drawer::Print() {
  system("clear");
  for (int x = 0; x < h; ++x) {
    for (int y = 0; y < w; ++y) {
      std::string output = color[x][y].color + field[x][y];
      std::cout << output;
    }
    std::cout << std::endl;
  }
}