# μS82
μS82 Board Lib for Arduino

## How to use
จำเป็นต้องเรียกใช้งาน Function uSetup(); ก่อนเพื่อกำหนดค่าเริ่มต้น

## คำสั่งทาง Input
อ่านค่าอนาล็อก analog(ch) : ch คือพอร์ทที่ต้องการอ่านค่าประกอบด้วย 0-7

## คำสั่งเกี่ยวกับมอเตอร์
motor(ch,power) : ch คือหมายเลขพอร์ทมอเตอร์บนบอร์ด μS82 และ power คือกำลังมีค่าตั้งแต่ -100 จนถึง 100
motor_stop(ch) : ใช้ในการสั่งหยุดมอเตอร์


## Example for use
```C++
#include <us82.h>

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
  
}

void loop() {
  int Value;
  for (int pins = 0; pins < 8; pins++){
    Value = analog(pins);  // read analog value 
    Serial.print(Value);
    Serial.print("\t");
  }
  Serial.println("");
  delay(100);
}
```
