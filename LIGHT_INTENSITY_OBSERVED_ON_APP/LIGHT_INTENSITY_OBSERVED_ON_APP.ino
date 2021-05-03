#include<SoftwareSerial.h>
int ldr=A0;
int x;
SoftwareSerial mySerial(10,11);
void setup() {
pinMode(ldr,INPUT);
mySerial.begin(9600);
Serial.begin(9600);
}

void loop() {
  x= analogRead(ldr);
  mySerial.print("intensity:");
  mySerial.println(x);
  Serial.println(x);
  delay(1000);
}

