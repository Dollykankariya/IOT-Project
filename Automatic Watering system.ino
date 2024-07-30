// C++ code
//
#include <Servo.h>

int soil = 0;

Servo servo_7;

void setup()
{
  pinMode(A0, INPUT);
  Serial.begin(9600);
  servo_7.attach(7, 500, 2500);
  pinMode(13, OUTPUT);
}

void loop()
{
  soil = analogRead(A0);
  Serial.println(soil);
  if (soil < 300) {
    servo_7.write(90);
    digitalWrite(13, HIGH);
  } else {
    if (soil < 600) {
      servo_7.write(0);
      digitalWrite(13, LOW);
    }
  }
  delay(10); // Delay a little bit to improve simulation performance
}