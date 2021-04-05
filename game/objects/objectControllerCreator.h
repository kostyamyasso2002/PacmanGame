#include "objectController.h"
#include "objectCreator.h"

#pragma once

class ObjectControllerCreator {
private:
    std::shared_ptr<ObjectCreator> creator;
public:
    virtual std::shared_ptr<ObjectController> CreateObjectController() = 0;
};

class PacManControllerCreator : ObjectControllerCreator {
public:
    std::shared_ptr<ObjectController> CreateObjectController() override;
};

class GhostControllerCreator : ObjectControllerCreator {
public:
    std::shared_ptr<ObjectController> CreateObjectController() override;
};