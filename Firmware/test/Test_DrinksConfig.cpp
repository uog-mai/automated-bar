#include "gtest/gtest.h"

#include "DrinksConfig.h"

using namespace mai;

TEST(DrinksConfigTest, DefaultConstruction) {
    DrinksConfig drinks_config;
}

class Test_DrinksConfig : public ::testing::Test {
protected:
  Test_DrinksConfig() {}

  virtual void SetUp() {}

  virtual void TearDown() {}
};