#pragma once

#include <map>

#include "Drinks.h"

namespace mai {

    class DrinksConfig {
    public:

        DrinksConfig();

        void set_position(const Drinks::Position drink_pos, const Drinks::Type drink_type);

        Drinks::Type get_drink(const Drinks::Position drink_pos);
        Drinks::Position get_position(const Drinks::Type drink_type);

    private:
        std::map<Drinks::Type, Drinks::Position> m_drinks_map;
         
    };

}