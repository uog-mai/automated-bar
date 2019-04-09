#include "gtest/gtest.h"

#include "DrinksConfig.h"

using namespace mai;

TEST(DrinksConfigTest, DefaultConstruction) {
  DrinksConfig drinks_config;
    
  ASSERT_EQ(drinks_config.get_position(Drinks::Type::BUCKFAST),
            Drinks::Position(4));

  ASSERT_EQ(drinks_config.get_position(Drinks::Type::COKE),
            Drinks::Position(0));

  ASSERT_EQ(drinks_config.get_position(Drinks::Type::GIN),
            Drinks::Position(5));
    
  ASSERT_EQ(drinks_config.get_position(Drinks::Type::IRNBRU),
            Drinks::Position(1));

  ASSERT_EQ(drinks_config.get_position(Drinks::Type::LEMONADE),
            Drinks::Position(2));

  ASSERT_EQ(drinks_config.get_position(Drinks::Type::RUM),
            Drinks::Position(6));

  ASSERT_EQ(drinks_config.get_position(Drinks::Type::TONIC),
            Drinks::Position(3));

  ASSERT_EQ(drinks_config.get_position(Drinks::Type::VODKA),
            Drinks::Position(7));
}

class Test_DrinksConfig : public ::testing::Test {
protected:
  Test_DrinksConfig() {}

  virtual void SetUp() {}

  virtual void TearDown() {}
};