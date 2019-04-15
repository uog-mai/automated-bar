#pragma once

#include <map>
#include <memory>
<<<<<<< HEAD
#include <wiringPi.h>
=======
>>>>>>> 36b313b101d76850a68fde51451006dd8bcc6803

#include "Drinks.h"
#include "DrinksConfig.h"
#include "ServoHandler.h"
#include "HX711/HX711.h"


class DrinkServer {
typedef unsigned int pin_num_t;
public:


    const int setup_status = wiringPiSetupGpio();



    HX711 scale;

    enum class Status {
        DISPENSE_FAILURE,
        DISPENSE_SUCCESS
    };

    DrinkServer(const mai::DrinksConfig &drinks_config);

    Status weight_match(HX711 scale, const float target_weight);

    Status dispense_drink(const mai::Drinks::Type drink_type, const float weight_gm);

private:
    std::map<mai::Drinks::Type, std::shared_ptr<ServoHandler>> servo_map;
};
