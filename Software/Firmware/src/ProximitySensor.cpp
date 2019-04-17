#include "ProximitySensor.h"
#include <wiringPi.h>    
#include <cstdio>

ProximitySensor::ProximitySensor() {
    m_cup_detected = false;
    pinMode(m_prox_pin, INPUT);
}

bool ProximitySensor::detect_cup(){
    m_cup_detected =  !digitalRead(m_prox_pin);
    printf("cup detected: %s \n\n ", m_cup_detected?"true":"false");  
    return m_cup_detected;
}
