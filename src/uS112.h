#include "us82_motor.h"

#ifndef US112_H_
#define US112_H_

#define SW_PORT 8  // SW Port and Remote Port
#define GLED    13

#define USCK    13
#define UMISO   12
#define UMOSI   11
#define USS     10


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

bool in(int __ch){
    __ch = (__ch == 13 ? __ch : __ch+14);
    pinMode(__ch, INPUT);
    return digitalRead(__ch);
}

void out(int __ch, bool __state){
    __ch = (__ch == 13 ? __ch : __ch+14);
    pinMode(__ch, OUTPUT);
    digitalWrite(__ch,__state);
}

void SW_press(){
    while(!SW());
    while(SW());
}

#endif
