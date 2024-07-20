// C++ code
//
#include <Servo.h>

int ultrasonic = 0;

int soilmoisture = 0;

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

Servo servo_6;

void setup()
{
  Serial.begin(9600);
  servo_6.attach(6, 500, 2500);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
}

void loop()
{
  ultrasonic = 0.01723 * readUltrasonicDistance(9, 10);
  Serial.println(ultrasonic);
  if (ultrasonic > 100) {
    servo_6.write(180);
    Serial.println("Bin is Full");
    if (soilmoisture < 500) {
      digitalWrite(11, HIGH);
      Serial.println("Dry Waste Detected");
    } else {
      digitalWrite(12, HIGH);
      Serial.println("Wet Waste Detected");
    }
  } else {
    Serial.println("Bin is Empty");
  }
  delay(10); // Delay a little bit to improve simulation performance
}