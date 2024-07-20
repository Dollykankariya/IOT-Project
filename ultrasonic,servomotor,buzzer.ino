// C++ code
//
#include <Servo.h>

int ultrasonic = 0;

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

Servo servo_10;

void setup()
{
  Serial.begin(9600);
  servo_10.attach(10, 500, 2500);
  pinMode(9, OUTPUT);
}

void loop()
{
  ultrasonic = 0.01723 * readUltrasonicDistance(7, 6);
  Serial.println(ultrasonic);
  if (ultrasonic < 200) {
    servo_10.write(90);
    tone(9, 523, 2000); // play tone 60 (C5 = 523 Hz)
  } else {
    servo_10.write(0);
  }
  delay(10); // Delay a little bit to improve simulation performance
}