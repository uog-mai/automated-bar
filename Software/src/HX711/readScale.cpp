#include "HX711.h"
#include <stdio.h>
#include <wiringPi.h>
#include <unistd.h>
#include <cmath> 

int main(void)
{
    if (wiringPiSetup() == -1) 
    {
        printf ("Setup wiringPi Failed!\n");
    }
    
    HX711 scale(2, 0, 128);
    long sum = 0;
    for (int i =0; i < 10; i++)
    {
	sum += scale.get_value();
    }

    const long offset = scale.read_trimmed_avg();
    printf("Offset: %ld \n\n", offset);
    //const float ratio;
    int v = 1;
    long previous_value = scale.read_average();
    long current_value;
    
    float steady_confidence;
    const float filter_cutoff = 40000;

    while(v)
    {
 	//current_value = scale.read_average();
	//if (std::abs(current_value - previous_value) > filter_cutoff)
	//{
		//current_value += filter_cutoff;
	//}
    	printf("%ld \n", scale.read_trimmed_avg() - offset);
	
	usleep(500000);
	//previous_value = current_value;
    }
}

