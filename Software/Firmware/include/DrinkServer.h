#pragma once

#include <map>

#include "Drinks.h"
#include "DrinkConfig.h"
#include "ServoHandler.h"


class DrinkServer {
typedef unsigned int pin_num_t;
public:

    enum class Status {
        DISPENSE_FAILURE,
        DISPENSE_SUCCESS
    };

    DrinkServer(const DrinksConfig &drinks_config);

    DrinkStatus dispense_drink(const Drinks::DrinkType drink_type, const int volume_ml);

private:
    std::map<Drinks::DrinkType, ServoHandler> drink_servos;
};