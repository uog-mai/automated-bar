#pragma once

#include <map>

#include "Drinks.h"
#include "DrinksConfig.h"
#include "ServoHandler.h"
#include "HX711/HX711.h"

class DrinkServer {
typedef unsigned int pin_num_t;
public:

    HX711 scale();

    enum class Status {
        DISPENSE_FAILURE,
        DISPENSE_SUCCESS
    };

    DrinkServer(const mai::DrinksConfig &drinks_config);

    Status dispense_drink(const mai::Drinks::Type drink_type, const float weight_gm);

private:
    std::map<mai::Drinks::Type, ServoHandler> servo_map;
};
