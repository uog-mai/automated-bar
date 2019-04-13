#pragma once

#include <string>

namespace mai {

  namespace Drinks {

      enum class Type {
        BUCKFAST,
        COKE,
        GIN,
        IRNBRU,
        LEMONADE,
        RUM,
        TONIC,
        VODKA
      };

      class Position {
      public:
        Position(const unsigned int pin_num) : m_pin_num(pin_num) {}
      
        bool operator==(const Position &rhs) const {
          return m_pin_num == rhs.m_pin_num;
        }

      private:
        unsigned int m_pin_num;
      };
      
      static Type resolve_drink(const std::string &drink) {
        if (drink == "buckfast")
          return Drinks::Type::BUCKFAST;
        else if (drink == "coke")
          return Drinks::Type::COKE;
        else if (drink == "gin")
          return Drinks::Type::GIN;
        else if (drink == "irnbru")
          return Drinks::Type::IRNBRU;
        else if (drink == "lemonade")
          return Drinks::Type::LEMONADE;
        else if (drink == "rum")
          return Drinks::Type::RUM;
        else if (drink == "tonic")
          return Drinks::Type::TONIC;
        else if (drink == "vodka")
          return Drinks::Type::VODKA;
        else
          throw std::runtime_error("Could not resolve drink type: " + drink);
      }

  }

}