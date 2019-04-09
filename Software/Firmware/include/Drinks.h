#include <map>

#include "ServoHandler.h"

class Drinks {
public:

    enum class DrinkType {
        BUCKFAST,
        COKE,
        GIN,
        IRNBRU,
        LEMONADE,
        RUM,
        TONIC,
        VODKA
    };

    enum class DrinkStatus {
        DISPENSE_FAILURE,
        DISPENSE_SUCCESS
    };

    static DrinkType resolve_drink(const std::string &drink) {
      if (drink == "buckfast")
        return DrinkType::BUCKFAST;
      else if (drink == "coke")
        return DrinkType::COKE;
      else if (drink == "gin")
        return DrinkType::GIN;
      else if (drink == "irnbru")
        return DrinkType::IRNBRU;
      else if (drink == "lemonade")
        return DrinkType::LEMONADE;
      else if (drink == "rum")
        return DrinkType::RUM;
      else if (drink == "tonic")
        return DrinkType::TONIC;
      else if (drink == "vodka")
        return DrinkType::VODKA;
      else
        throw std::runtime_error("Could not resolve drink type: " + drink);
    }

    DrinkStatus dispense_drink(const int volume_ml);

private:

    const std::map<DrinkTypes, ServoHandler> drink_servos = {
        { DrinkTypes::BUCKFAST, ServoHandler(0)},
        { DrinkTypes::COKE, ServoHandler(1)},
        { DrinkTypes::GIN, ServoHandler(2)},
        { DrinkTypes::IRNBRU, ServoHandler(3)},
        { DrinkTypes::LEMONADE, ServoHandler(4)},
        { DrinkTypes::RUM, ServoHandler(5)},
        { DrinkTypes::TONIC, ServoHandler(6)},
        { DrinkTypes::VODKA, ServoHandler(7)}
    };

};