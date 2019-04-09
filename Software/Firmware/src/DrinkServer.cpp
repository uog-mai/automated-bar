#include "DrinkServer.h"

DrinkServer::DrinkServer(const DrinksConfig &drinks_config) {
    for (const auto& drink: drinks_config) {
        const Drinks::DrinkType drink_type = drink.first;
        const Drinks::DrinkPosition drink_pos = drink.second;
        drink_servos[drink.first] = ServoHandler(static_cast<int>(drink_pos));
    }
}

DrinkServer::DrinkStatus DrinkServer::dispense_drink(const Drinks::DrinkType drink_type) {
    /* @TODO */
    ServoHandler& drink_servo = drink_servos.find(drink_type)->second;
    return DrinkServer::DrinkStatus::DISPENSE_SUCCESS;
}
