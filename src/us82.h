#include "us82_motor.h"

#ifndef US82_H_
#define US82_H_

#define SW_PORT 8


void uSetup(){
    pinMode(PWM1, OUTPUT);
    pinMode(INA1, OUTPUT);
    pinMode(INB1, OUTPUT);
    pinMode(PWM2, OUTPUT);
    pinMode(INA2, OUTPUT);
    pinMode(INB2, OUTPUT);
    pinMode(SW_PORT, INPUT);
    
}

int analog(int __ch){
    return analogRead(__ch);
}

bool SW(){
    return digitalRead(SW_PORT);
}

void SW_press(){
    while(!SW());
    while(SW());
}


#endif
