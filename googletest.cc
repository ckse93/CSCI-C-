

#include <gtest/gtest.h>
#include "src/arena.h"
#include "src/entity_type.h"
#include "src/params.h"
#include "src/EntityFactory.h"
#include "src/light.h"
#include "src/common.h"
#include "src/arena_mobile_entity.h"
#include "src/motion_behavior_differential.h"
#include "src/wheel_velocity.h"
#include "src/behavior_enum.h"
#include "src/rgb_color.h"
NAMESPACE_BEGIN(csci3081);

 /******************************************************
* TEST FEATURE SetUp
*******************************************************/
class BVTest : public ::testing::Test {

 protected:
  virtual void SetUp() { // setting up the variables in line 33 and 34
    factory = new csci3081::BVFactory();
    std::string json = "{\"type\": \"Braitenberg\", \"x\":270, \"y\":270, \"r\":15, \"theta\": 215, \"light_behavior\": \"None\", \"food_behavior\": \"Explore\" }";
    json_value * config = new json_value();
    std::string err = parse_json(config, json);
    bv = factory->Create(config->get<json_object>());
  }
  virtual void TearDown() {
    delete factory;
  }
csci3081::BVFactory * factory; // following tests below will use these variables
BraitenbergVehicle *bv;
};

/*******************************************************************************
 * Test Cases
 ******************************************************************************/

TEST_F(BVTest, BVCreateDefault) {
    EXPECT_EQ(bv->get_pose().x, 270);
    EXPECT_EQ(bv->get_pose().y, 270);
    EXPECT_EQ(bv->get_pose().theta, 215);
    EXPECT_EQ(bv->get_food_behavior(), kExplore);
    EXPECT_EQ(bv->get_light_behavior(), kNone);
    EXPECT_EQ(bv->count, 1);
    EXPECT_EQ(bv->get_radius(), 15);
    EXPECT_EQ(bv->get_color(), RgbColor(kMaroon));
    EXPECT_EQ(bv->get_type(), kBraitenberg);
    EXPECT_EQ(bv->get_id(), 1) << "get_id() error";
    EXPECT_EQ(bv->is_mobile(), true) << "is_mobile() error";

}

TEST_F(BVTest, BVsetter_test) {
  Pose pose(350,350,325);
  bv->set_pose(pose);
  EXPECT_EQ(bv->get_pose().x, 350);
  EXPECT_EQ(bv->get_pose().y, 350);
  EXPECT_EQ(bv->get_pose().theta, 325);

  bv->set_position(150,210);
  bv->set_heading(100);
  EXPECT_EQ(bv->get_pose().x, 150);
  EXPECT_EQ(bv->get_pose().y, 210);
  EXPECT_EQ(bv->get_pose().theta, 100);
  bv->RelativeChangeHeading(12);
  EXPECT_EQ(bv->get_pose().theta, 112);

  bv->set_food_behavior(kCoward);
  bv->set_light_behavior(kLove); // moth.
  EXPECT_EQ(bv->get_food_behavior(), kCoward);
  EXPECT_EQ(bv->get_light_behavior(), kLove);
  EXPECT_EQ(bv->get_color(), RgbColor(kMaroon));
  bv->set_color(RgbColor(kGold));
  EXPECT_EQ(bv->get_color(), RgbColor(kGold));

  bv->set_type(kFood);
  EXPECT_EQ(bv->get_type(), kFood); // now the moth is food.
}

NAMESPACE_END(csci3081);
