/**
 * @file EntityFactory.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef SRC_ENTITYFACTORY_H_
#define SRC_ENTITYFACTORY_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "src/common.h"
#include "src/entity_type.h"
#include "src/arena_entity.h"
#include "src/light.h"
#include "src/food.h"
#include "src/braitenberg_vehicle.h"


NAMESPACE_BEGIN(csci3081);

// this is a header file, make sure to split into .h and .cc file later on


// main factory interface
class EntityFactory {
 public :
    EntityFactory() {}
    virtual ~EntityFactory() {}
    virtual ArenaEntity * Create() = 0;
    // change it to Create (config JSON*) later.
};

class BVFactory : public EntityFactory {
 public :
    BVFactory() {}
    virtual ~BVFactory() {}
    BraitenbergVehicle * Create() override;
  // overriding copy and assignment constructors
};

class LightFactory : public EntityFactory {
 public :
    LightFactory() {}
    virtual ~LightFactory() {}
    Light * Create() override;
  // overriding copy and assignment constructors
};

class FoodFactory : public EntityFactory {
 public :
    FoodFactory() {}
    virtual ~FoodFactory() {}
    Food * Create() override;
  // overriding copy and assignment constructors
};


NAMESPACE_END(csci3081);
#endif  // SRC_ENTITYFACTORY_H_
