// C++ code
//
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

void setup()
{
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
}

void loop()
{
  ultrasonic = 0.01723 * readUltrasonicDistance(6, 4);
  Serial.println(ultrasonic);
  if (ultrasonic > 200) {
    digitalWrite(13, HIGH);
    digitalWrite(12, HIGH);
  } else {
    digitalWrite(11, HIGH);
  }
  delay(10); // Delay a little bit to improve simulation performance
}