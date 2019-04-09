#include "Servos.h"

#include "pca9685/src/pca9685.h"
#include <wiringPi.h>
#include <wiringPiI2C.h>


ServoHandler::ServoHandler(const int pin_num)
                          : m_activated(false),
                            m_pin_num(pin_num) {
  /* Check the GPIO Pins are Setup. */
  if (wiringPiSetupGpio() == -1)
    throw std::runtime_error("Failed to setup GPIO for wiringPi");

  pwmSetClock(m_clockValue);
  pwmSetRange(m_rangeValue);
}

ServoHandler::ServoStatus ServoHandler::activate() {
    /* @TODO */
    m_activated = true;
    return ServoHandler::ServoStatus::ACTION_SUCCESS;
}

ServoHandler::ServoStatus ServoHandler::deactivate() {
    /* @TODO */
    m_activated = false;
    return ServoHandler::ServoStatus::ACTION_SUCCESS;
}