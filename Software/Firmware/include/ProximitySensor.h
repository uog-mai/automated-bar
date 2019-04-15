#pragma once

class ProximitySensor{
public:

    ProximitySensor();

    bool detect_cup();
 
private:
bool m_cup_detected;
const signed int prox_pin;

}
