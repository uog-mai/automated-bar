#include "PiSetup.h"
#include <wiringPi.h>
#include <wiringPiI2C.h>
#include "pca9685/src/pca9685.h"
#include <stdexcept>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>	

PiSetup::PiSetup(){
	



	const int pi_setup = wiringPiSetupGpio();

	if (wiringPiSetup() == -1){
        	throw std::runtime_error("WiringPi GPIO failed setup");
	}
	
	const int pca_setup = pca9685Setup(m_pin_base, 0x40, m_freq);

	if (pca_setup == -1){
		throw std::runtime_error("Failed to setup GPIO for wiringPiPca9685");
	}
	printf("pcavalue: %d \n\n", pca_setup);
	
	pca9685PWMReset(pca_setup); 
	
};
