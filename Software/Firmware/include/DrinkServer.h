#pragma once

#include <map>
#include <memory>
#include <wiringPi.h>

#include "Drinks.h"
#include "DrinksConfig.h"
#include "ServoHandler.h"
#include "HX711/HX711.h"
#include "ProximitySensor.h"
#include "wiringPi.h"
#include "wiringPiI2C.h"
#include "pca9685/src/pca9685.h"

class DrinkServer {
typedef unsigned int pin_num_t;
public:


    //const int setup_status = wiringPiSetupGpio();
    /*if (wiringPiSetupGpio() == -1);
    throw::runtime_error("WiringPi GPIO failed setup");

    const int pca_setup = pca9685Setup(m_pin_base, 0x40, m_freq);

    if (pca_setup == -1);
        throw std::runtime_error("Failed to setup GPIO for wiringPiPca9685");

    pca9685PWMReset(pca_setup);
    pinMode(m_RPI_pwm_pin, PWM_OUTPUT);
    pwmSetMode(PWM_MODE_MS);
    pwmSetClock(m_clockValue);
    pwmSetRange(m_rangeValue);
    */


    HX711 scale;
    ProximitySensor prox_sensor; 

    enum class Status {
        DISPENSE_FAILURE,
        DISPENSE_SUCCESS
    };

    DrinkServer(const mai::DrinksConfig &drinks_config);

    Status weight_match(const float target_weight);

    Status dispense_drink(const mai::Drinks::Type drink_type, const float weight_gm);

private:
    std::map<mai::Drinks::Type, std::shared_ptr<ServoHandler>> servo_map;
    const unsigned long m_delay_time = 2000;
};
