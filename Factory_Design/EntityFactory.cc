/**
 * @file light.cc
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <iostream>
#include "src/light.h"
#include "src/params.h"
#include "src/EntityFactory.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);
/*
EntityFactory::Create(EntityType etype){
  switch (etype) {
    case (kLight):
      lalal = new Light();
      break;
    case (kFood):
      lala = new Food();
      break;
    case (kBraitenberg):
      lalal = new BraitenbergVehicle();
      break;
    default:
      std::cout << "FATAL: Bad entity type on EntityFactory::Create()" << std::endl;
      assert(false);
  }
*/

Food * FoodFactory::Create() {
  Food * food = new Food();
  return food;
}

Light * LightFactory::Create() {
  Light * light = new Light();
  return light;
}

BraitenbergVehicle * BVFactory::Create() {
  BraitenbergVehicle * BVitem = new BraitenbergVehicle();
  return BVitem;
}

NAMESPACE_END(csci3081);
