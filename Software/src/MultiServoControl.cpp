#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#include <wiringPiI2C.h>
#include "pca9685/src/pca9685.h"
#include <iostream>
#include "pybind11/pybind11.h"
#include <string>
#include <map>


#define PIN_BASE 300
#define MAX_PWM 4096
#define HERTZ 50

int calcTicks(float impulseMs, int hertz)

{	float cycleMs = 1000.0f / hertz;
	return (int)(MAX_PWM * impulseMs / cycleMs + 0.5f);
}

/**
 * input is [0..1]
 * output is [min..max]
 */
float map(float input, float min, float max)
{
	return (input * max) + (1 - input) * min;
}

int OutputServos(int mixerInd, int alcInd)
{
    if (wiringPiSetupGpio() == -1) 
    {
        printf ("Setup wiringPi Failed!\n");
    }

    
	printf("PCA9685 servo example\n");
	printf("Connect a servo to any pin. It will rotate to random angles\n");

    int fd = pca9685Setup(PIN_BASE, 0x40, HERTZ);
	if (fd < 0)
	{
		printf("Error in setup\n");
		return fd;
    }


    pinMode(18, PWM_OUTPUT);
    pwmSetMode(PWM_MODE_MS);
    pwmSetClock(192);
    pwmSetRange(2000);

    int pwm_value = 50;

   
    // Set servo to neutral position at 1.5 milliseconds
	// (View http://en.wikipedia.org/wiki/Servo_control#Pulse_duration)
	pca9685PWMReset(fd);
	//printf("%d \n", fd);
	delay(1000);
	float millis = 1.5;
	int tick = calcTicks(millis, HERTZ);
	printf("%d \n", mixerInd);
	printf("%d \n", alcInd);
	pwmWrite(PIN_BASE + mixerInd , 1000);
	delay(2000);

	pwmWrite(PIN_BASE + mixerInd, 5);
	delay(2000);

	pwmWrite(PIN_BASE + alcInd, 1000);
        delay(2000);

        pwmWrite(PIN_BASE +  alcInd, 5);
        delay(2000);

return 0;
}

int serveDrink(std::string mixer, std::string alcohol)
{
    std::map<std::string, int> drinkmap;
    // Initialize the drink map

    drinkmap["Coke"] = 0;
    drinkmap["Lemonade"] = 1;
    drinkmap["Tonic"] = 2;
    drinkmap["Irn-Bru"] = 3;

    drinkmap["Rum"] = 4;
    drinkmap["Vodka"] = 5;
    drinkmap["Buckfast"] = 6;
    drinkmap["Gin"] = 7;

    int mixerIndex = -1;
    int alcIndex = -1;

    const auto mixerIt = drinkmap.find(mixer);
    const auto alcIt = drinkmap.find(alcohol);
    
    if (mixerIt != drinkmap.end() && alcIt != drinkmap.end()) 
    {
        mixerIndex = (mixerIt->second);
        alcIndex = (alcIt->second);
    }
    else 
    {
        std::cout << ("No Key " +  mixer  + " " + alcohol) << "\n";
    }

    int value = OutputServos(mixerIndex, alcIndex);

    return alcIndex;
}

PYBIND11_MODULE(extension, m) 
{
    m.doc() = "pybind11 example plugin"; // optional module docstring

    m.def("serveDrink", &serveDrink, "A function which maps drinks to the appropriate servo");
}

