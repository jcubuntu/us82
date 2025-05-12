#include <uS112.h>

void setup() {
  uSetup();  // initial uS82 system
  Serial.begin(115200);
  
  SW_press(); // Wair For Press SW

  motor(1, 100);  // motor 1 forward maximun speed is 100
  motor(2, 100);  // motor 2 forward maximun speed is 100
  delay(1000);

  motor(1, -100);  // motor 1 backward maximun speed is -100
  motor(2, -100);  // motor 2 backward maximun speed is -100
  delay(1000);

  fd(100);        // motor 1  & 2 forward maximun speed is 100
  delay(1000);

  bk(100);        // motor 1  & 2 backward maximun speed is 100
  delay(1000);

  fd2(100,100);        // motor 1  & 2 forward maximun speed is 100
  delay(1000);

  bk2(100,100);        // motor 1  & 2 backward maximun speed is 100
  delay(1000);

  sl(100);        // spin left maximun speed is 100
  delay(1000);

  sr(100);        // spin right maximun speed is 100
  delay(1000);

  tl(100);        // turn left maximun speed is 100
  delay(1000);

  tr(100);        // turn right maximun speed is 100
  delay(1000);

  motor_stop(ALL); // stop all motor
  
}

void loop() {
  int Value;
  for (int pins = 0; pins < 8; pins++){
    Value = analog(pins);  // read analog value form pin A0,A1,A2 ... A7
    Serial.print(Value);
    Serial.print("\t");
  }
  Serial.println("");
  for (int pins = 0; pins < 8; pins++){
    Value = in(pins);  // read Digital value form pin With "in" command 0,1,2...7 if use "digitalRead" pins is 14,15,16..19
    Serial.print(Value);
    Serial.print("\t");
  }
  Serial.println("");
  delay(100);
}