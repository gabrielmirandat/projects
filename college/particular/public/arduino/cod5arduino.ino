#include <Servo.h>

int motor = 5;
int luz = 0;
int ldr=A0;
int luzMap = 0;
Servo ServoLegal;

void setup() {
  ServoLegal.attach(motor);
  Serial.begin(9600); 
  pinMode(motor,OUTPUT);
  pinMode(ldr,INPUT);
}

void loop() {
  luz=analogRead(ldr);
  luzMap = map(luz, 0 , 1023, 0, 180);
  Serial.println(luzMap);
  ServoLegal.write(luzMap);
  delay(1000);
}
