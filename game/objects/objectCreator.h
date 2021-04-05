#include "object.h"
#include <memory>

#pragma once

class ObjectCreator {
public:
    virtual std::shared_ptr<Object> CreateObject() = 0;
};

class PacManCreator : public ObjectCreator {
    std::shared_ptr<Object> CreateObject() override;
};

class GhostCreator : public ObjectCreator {
    std::shared_ptr<Object> CreateObject() override;
};