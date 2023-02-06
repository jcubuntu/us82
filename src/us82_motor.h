#ifndef     US82_MOTOR_H_
#define     US82_MOTOR_H_
#include <Arduino.h>

#ifndef 	ALL
#define 	ALL     12
#endif

#define PWM1    5
#define INA1    2
#define INB1    3
#define PWM2    6
#define INA2    4
#define INB2    7  

void motor(char ch, int Pow){
    bool dir  = (Pow >= 0 ? true : false);
    Pow = abs(Pow);
    Pow = (Pow * 255) / 100;
    if (ch == 1){
        digitalWrite(INA1,dir);
        digitalWrite(INB1,!dir);
        analogWrite(PWM1,Pow);
    }
    else if (ch == 2){
        digitalWrite(INA2,dir);
        digitalWrite(INB2,!dir);
        analogWrite(PWM2,Pow);
    }
    else if (ch == 12){
        digitalWrite(INA1,dir);
        digitalWrite(INB1,!dir);
        analogWrite(PWM1,Pow);
        
        digitalWrite(INA2,dir);
        digitalWrite(INB2,!dir);
        analogWrite(PWM2,Pow);
    }
}

void motor_stop(uint8_t ch){
    if (ch == 1){
        digitalWrite(PWM1, 0);
    }
    else if (ch == 2){
        digitalWrite(PWM2, 0);
    }
    else if (ch == 12){
        digitalWrite(PWM1, 0);
        digitalWrite(PWM2, 0);
    }
}


void fd2(int _speed1,int _speed2){
  motor(1,_speed1);
  motor(2,_speed2);  
}
void bk2(int _speed1,int _speed2){
 
  motor(1,-(_speed1));
  motor(2,-(_speed2));  
}

void fd(int _speed1){
  motor(1,_speed1);
  motor(2,_speed1);   
}
void bk(int _speed1){
  motor(1,-(_speed1));
  motor(2,-(_speed1));     
}

void sl(int _speeds){
  motor(1,-(_speeds));
  motor(2,_speeds);    
}
void sr(int _speeds){
  motor(1,_speeds);
  motor(2,-(_speeds));      
}

void tl(int _speeds){
  motor(1,0);
  motor(2,_speeds);       
}
void tr(int _speeds){
  
  motor(1,_speeds);
  motor(2,0); 
}

void motorControl(int _speedL, int _speedR){
    motor(1, _speedL);
    motor(2, _speedR);
}


#endif
