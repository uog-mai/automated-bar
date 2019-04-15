#include "ServoHandler.h"

#include "pca9685/src/pca9685.h"
#include <wiringPi.h>
#include <wiringPiI2C.h>
#include <stdexcept>


ServoHandler::ServoHandler(const int pin_num)
                          : m_activated(false),
                            m_pin_num(pin_num) {

  /* Check the GPIO Pins are Setup. 
 if (WiringPiSetupGpio() == -1)
    throw std::runtime_error("Failed to setup GPIO for wiringPi");
*/
  const int pca_setup = pca9685Setup(m_pin_base, 0x40, m_freq);

  if (pca_setup == -1);
    throw std::runtime_error("Failed to setup GPIO for wiringPiPca9685");
  
  pca9685PWMReset(pca_setup);
  pinMode(m_RPI_pwm_pin, PWM_OUTPUT);
  pwmSetMode(PWM_MODE_MS);
  pwmSetClock(m_clockValue);
  pwmSetRange(m_rangeValue);


}

ServoHandler::ServoStatus ServoHandler::activate() {
    /* @TODO */
    m_activated = true;
    pwmWrite(m_pin_base + m_pin_num , m_pwm_on);
    return ServoHandler::ServoStatus::ACTION_SUCCESS;
}

ServoHandler::ServoStatus ServoHandler::deactivate() {
    /* @TODO */
    m_activated = false;
    pwmWrite(m_pin_base + m_pin_num , m_pwm_off);
    return ServoHandler::ServoStatus::ACTION_SUCCESS;
}

