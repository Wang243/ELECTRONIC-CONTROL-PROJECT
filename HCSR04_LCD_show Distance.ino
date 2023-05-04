//Using the Ultrasonic sensor to measure the distance (sensor and object)
//it will show the distance unit is CM and inch;
// defines pins numbers
const int trigPin = 3;
const int echoPin = 4;
// defines variables
long duration;
int distance;
// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);
void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600); // Starts the serial communication
   // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
}
void loop() {
   delay(200);
 digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  //lcd.clear();
 float  distanceCm = duration * 0.0343 / 2;
 float distanceInch = duration * 0.0133 / 2;
  lcd.setCursor(0, 0); // Sets the location at which subsequent text written to the LCD will be displayed
  lcd.print("Distance:"); // Prints string "Distance" on the LCD
  lcd.print(distanceCm); // Prints the distance value from the sensor
  Serial.print(distanceCm); 
  lcd.print("cm");
  delay(10);
  lcd.setCursor(0, 1);
  lcd.print("Distance:");
  lcd.print(distanceInch);
  lcd.print("inch");
  delay(10);
  
}