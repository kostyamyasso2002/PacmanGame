#include<bits/stdc++.h>

class ObjectController {
public:
    virtual void food() = 0;
    virtual void gain() = 0;
};

enum class Direction {
    LEFT, RIGHT, DOWN, UP, None
};

class Element {
public:
    void Interact(std::unique_ptr<ObjectController> obj);
    bool CanMove(std::unique_ptr<ObjectController> obj);
};

class Movable : public Element {

};

class Empty : public Movable {

};

class Food : public Movable {

};

class Power : public Movable {

};

class Wall : public Element {

};

class Field {
public:
    std::vector<std::vector<Element>> map;
};

class Strategy {
public:
    virtual Direction FindNextStep(Field map, int x, int y) = 0;
};

class Object {
public:
    int XCoordinate;
    int YCoordinate;
    virtual void Move(int x, int y) = 0;
};

class PacMan : public Object {
public:
    int Direction;
    int health_point;
    int color;
    virtual void Move(int x, int y) override;
};

class Ghost : public Object {
public:
    virtual void Move(int x, int y) override;
};

class PacManController : public ObjectController {
public:
    PacMan pacman;
    void move();
};

class GhostController : public ObjectController {
public:
    Ghost ghost;
    std::unique_ptr<Strategy> strategy;
    void DoNextStep();
};

class GameField {
public:
    Field field;
    std::unique_ptr<PacManController> pacman;
    std::vector<std::unique_ptr<GhostController>> ghosts;
    void DoNextIteration(Direction direction);
};

class EasyStrategy : public Strategy {
public:
    virtual Direction FindNextStep(Field map, int x, int y) override;
};

class NormalStrategy : public Strategy {
public:
    virtual Direction FindNextStep(Field map, int x, int y) override;
};

class HardStrategy : public Strategy {
public:
    virtual Direction FindNextStep(Field map, int x, int y) override;
};

class Color {
public:
    std::string color;
};

class LowDrawer {
public:
    std::vector<std::vector<char>> field;
    std::vector<std::vector<Color>> color;
    void ChangeSymbol(int x, int y, char newChar, Color newColor);
    void Print();
};

int main() {

  return 0;
}
