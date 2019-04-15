#include "ProximitySensor"
#include <wiringPi.h>    

ProximitySensor::ProximitySensor() : {
 m_cup_detected = false;
 pinMode(prox_pin, INPUT);
}

bool ProximitySensor::detect_cup(){
    digitalRead(prox_pin);
}
