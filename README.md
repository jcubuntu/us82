# μS82
μS82 & μS112+ Board Lib for Arduino

## How to use
จำเป็นต้องเรียกใช้งาน Function uSetup(); ก่อนเพื่อกำหนดค่าเริ่มต้น

## คำสั่งทาง Input
อ่านค่าอนาล็อก -> analog(ch) : ch คือพอร์ทที่ต้องการอ่านค่าประกอบด้วย 0-7

อ่านค่าดิจิทัล -> in(ch) : ch คือพอร์ทที่ต้องการอ่านค่าประกอบด้วย 0-5 ในกรณีใช้คำสั่ง in ไม่ต้องกำหนด pinMode ก่อนใช้คำสั่งนี้

อ่านค่าดิจิทัล -> digitalRead(ch) : ch คือพอร์ทที่ต้องการอ่านค่าประกอบด้วย 14-19 จำเป็นต้องกำหนด pinMode ตามมาตรฐาน Arduino ก่อน

อ่านค่าจากพอร์ท Remote หรือ SW -> SW() จะให้ค่าออกมาเป็น 0 หรือ 1

รอการกดปุ่ม SW -> SW_press() : หยุดรอการกดปุ่ม SW แล้วจึงทำงานต่อไป

## คำสั่งเกี่ยวกับมอเตอร์
motor(ch,power) : ch คือหมายเลขพอร์ทมอเตอร์บนบอร์ด μS82 และ power คือกำลังมีค่าตั้งแต่ -100 จนถึง 100

motor_stop(ch) : ใช้ในการสั่งหยุดมอเตอร์


## Example for use
```C++
#include <us82.h>

bool ledState = 1;

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
  ledState = !ledState;
  out(GLED,ledState);       // GLED is Green LED on Pin 13
  for (int pins = 0; pins < 8; pins++){
    Value = analog(pins);  // read analog value form pin A0,A1,A2 ... A7
    Serial.print(Value);
    Serial.print("\t");
  }
  for (int pins = 0; pins < 6; pins++){
    Value = in(pins);  // read Digital value form pin With "in" command 0,1,2...5 if use "digitalRead" pins is 14,15,16..19
    Serial.print(Value);
    Serial.print("\t");
  }
  Serial.println("");
  delay(100);
}
```
