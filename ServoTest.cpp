#include <stdio.h>
#include <wiringPi.h>

int main (void)
{
    if (wiringPiSetupGpio() == -1) 
    {
        printf ("Setup wiringPi Failed!\n");
    }

    pinMode(18, PWM_OUTPUT);
    pwmSetMode(PWM_MODE_MS);
    pwmSetClock(192);
    pwmSetRange(2000);

    int pwm_value = 50;

    for (int i = 1; i < 10; i++)
    {
        if (pwm_value == 50)
        {
            pwm_value = 250;
        }
        else
        {
            pwm_value = 50;
        }

        pwmWrite(18, pwm_value);
        delay(5000);
            
        printf("PWM Value:  %d \n", pwm_value);
    }
}