#pragma once

class ServoHandler {
public:

    enum class ServoStatus {
        ACTION_FAILURE,
        ACTION_SUCCESS
    };

    ServoHandler(const int pin_num);
    
    ServoStatus activate();

    ServoStatus deactivate();

private:

    bool m_activated;
    const unsigned int m_pin_num;
    const unsigned int m_RPI_pwm_pin = 18;
    const unsigned int m_clockValue = 192;
    //const unsigned int m_freq = 50;
    const unsigned int m_max_pwm = -1;
    const unsigned int m_pin_base = 300;
    const unsigned int m_rangeValue = 2000;
    const unsigned int m_pwm_on = 1000;
    const unsigned int m_pwm_off = 5;

};
