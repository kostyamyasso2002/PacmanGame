#include "objectController.h"
#include <memory>
#pragma once

class Ceil {
public:
    void Interact(std::unique_ptr<ObjectController> obj);
    bool CanMove(std::unique_ptr<ObjectController> obj);
};

class Movable : public Ceil {

};

class Empty : public Movable {

};

class Food : public Movable {

};

class Power : public Movable {

};

class Wall : public Ceil {

};