#include <string>

#include "DrinksConfig.h"
#include "DrinkServer.h"
#include "Drinks.h"

using namespace mai;

DrinksConfig drinks_config;
DrinkServer drink_server(drinks_config);

bool dispense_drink(const std::string &drinkname, const float weight_gm) {
    // TODO
    const Drinks::Type drink = Drinks::resolve_drink(drinkname);
    Drinks::Position drink_pos = drinks_config.get_position(drink);
    const DrinkServer::Status status = drink_server.dispense_drink(drink, weight_gm);
    return true;
}

bool replace_drink(const int position, const std::string &new_drink) {
    // TODO
    return true;
}