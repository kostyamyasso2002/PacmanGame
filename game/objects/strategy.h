#include "field.h"
#include "direction.h"
#pragma once

class Strategy {
public:
    virtual Direction FindNextStep(Field map, int x, int y) = 0;
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