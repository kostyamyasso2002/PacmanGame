#include "objectController.h"
#include "objectCreator.h"

#pragma once

class ObjectControllerCreator {
protected:
    std::shared_ptr<ObjectCreator> creator;
public:
    virtual std::shared_ptr<ObjectController> CreateObjectController() = 0;
};

class PacManControllerCreator : public ObjectControllerCreator {
public:
    std::shared_ptr<ObjectController> CreateObjectController() override;
};

class GhostControllerCreator : public ObjectControllerCreator {
public:
    std::shared_ptr<ObjectController> CreateObjectController() override;
};