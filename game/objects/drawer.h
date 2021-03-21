#include "color.h"
#include <iostream>
#pragma once

class Drawer {
public:
    int w;
    int h;
    std::vector<std::vector<char>> field;
    std::vector<std::vector<Color>> color;
    void ChangeSymbol(int x, int y, char newChar, Color newColor);
    void Print();
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
        std::cout << '\n';
    }
}