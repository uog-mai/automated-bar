//
// Created by peter on 15/04/2019.
//

#include "drink.h"

Drink::Drink(std::string name, int servoPin, int volume) : name(std::move(name)), servoNum(servoPin), volume(volume) {}

