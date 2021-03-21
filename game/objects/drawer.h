#pragma once
#include "color.h"

class Drawer {
public:
    std::vector<std::vector<char>> field;
    std::vector<std::vector<Color>> color;
    void ChangeSymbol(int x, int y, char newChar, Color newColor);
    void Print();
};