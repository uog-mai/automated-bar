#include "DrinksConfig.h"

using namespace mai;

DrinksConfig::DrinksConfig() {
    m_drinks_map = {
      { Drinks::Type::COKE, Drinks::Position(0) },
      { Drinks::Type::IRNBRU, Drinks::Position(1) },
      { Drinks::Type::LEMONADE, Drinks::Position(2) },
      { Drinks::Type::TONIC, Drinks::Position(3) },
      { Drinks::Type::BUCKFAST, Drinks::Position(4) },
      { Drinks::Type::GIN, Drinks::Position(5) },
      { Drinks::Type::RUM, Drinks::Position(6) },
      { Drinks::Type::VODKA, Drinks::Position(7) }
    };
}

void DrinksConfig::set_position(const Drinks::Position drink_pos, const Drinks::Type drink_type) {
    
}

Drinks::Type DrinksConfig::get_drink(const Drinks::Position drink_pos) {
}

Drinks::Position DrinksConfig::get_position(const Drinks::Type drink_type) {
  return m_drinks_map.find(drink_type)->second;

}