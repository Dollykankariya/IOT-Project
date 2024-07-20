// C++ code
//
#include <Servo.h>

int PIR = 0;

int soilmoisture = 0;

int flex = 0;

Servo servo_9;

void setup()
{
  pinMode(A0, INPUT);
  Serial.begin(9600);
  pinMode(12, OUTPUT);
  servo_9.attach(9, 500, 2500);
}

void loop()
{
  flex = analogRead(A0);
  Serial.println(flex);
  if (flex <= 15) {
    digitalWrite(12, HIGH);
    servo_9.write(180);
  } else {
    digitalWrite(12, LOW);
    servo_9.write(0);
  }

  soilmoisture;
  delay(10); // Delay a little bit to improve simulation performance
}