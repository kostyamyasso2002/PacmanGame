#include "drawer.h"


void Drawer::ChangeSymbol(int x, int y, char newChar, Color newColor) {
  field[x][y] = newChar;
  color[x][y] = newColor;
}

void Drawer::Print() {
  system("clear");
  for (int x = 0; x < height_; ++x) {
    for (int y = 0; y < width_; ++y) {
      std::string output = color[x][y].color + field[x][y];
      std::cout << output;
    }
    std::cout << std::endl;
  }
}

Drawer::Drawer(int height, int width): height_(height), width_(width) {
  color.resize(height_, std::vector<Color>(width_));
  field.resize(height_, std::vector<char>(width_, '.'));
}

void Drawer::Flush() {
  color.assign(height_, std::vector<Color>(width_));
  field.assign(height_, std::vector<char>(width_, '.'));
}

