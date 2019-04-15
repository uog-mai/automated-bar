//
// Created by peter on 15/04/2019.
//

#ifndef AUTOMATED_BAR_DRINK_H
#define AUTOMATED_BAR_DRINK_H

#include <string>

struct Drink {
    std::string name;
    int servoNum;
    int volume;

    Drink(std::string name, int servoNum, int volume);
};

#endif //AUTOMATED_BAR_DRINK_H
