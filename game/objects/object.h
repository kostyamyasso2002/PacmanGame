#pragma once

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