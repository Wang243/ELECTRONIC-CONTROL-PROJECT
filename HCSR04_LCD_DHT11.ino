//Using the Ultrasonic sensor to measure the distance (sensor and object)
//it will show the distance unit is CM and inch;
//using DHT11 to measure temperature and humidity;
//base on the data,to calculate the speed of sound;
//all the data will be display on the LCD;
// defines pins numbers
#define DHTPIN 2 //Digital pin connected to the DHT sensor
#define DHTTYPE  DHT11  //DHT11;
#define trigPin  3 //Utrasonic sensor;
#define echoPin  4  //Utrasonic sensor;
#define Max_DISTANCE 400  //Utrasonic sensor measurement maximum distance in cm;
 
// include the library code:
#include <LiquidCrystal.h>
#include <NewPing.h>
#include <DHT.h>
#include "DHT.h"
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);
//DHT_Unified dht(DHTPIN, DHTTYPE);
DHT_Unified dht(DHTPIN, DHTTYPE);
uint32_t delayMS;
NewPing sonar(trigPin, echoPin, Max_DISTANCE);
//DECLARE VARIABLE
float Hum;  //humidity;
float Temperature;
float duration;  //duration of sound wave;
float distance;  //calculated the value;
float soundms;  //m/s
float soundcm;  //cm/ms
int iterations= 5; // Ultrasonic sensor reading;
void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600); // Starts the serial communication
   // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  //Initialize DHT sensor;
  //dht.begin();
}
void loop() {
   delay(1000);
   //read the value from DHT 11;
   Hum = dht.readHumidity();
   Temperature =  dht.readTemperature();
  soundms = 331.4 +( 0.606 *Temperature) + (0.0124 *Hum);  //the speed sound in m/s;
    soundcm = soundms / 10000; //the speed of sound in cm/ms
  // using the distance to calculate the distance;
  duration = sonar.ping_median(iterations);
  distance = (duration / 2) *soundcm;
  // check the distance is within the valid range;
  if (distance >=400 && distance<=2 ){
  Serial.print("out of range");

  }
  else {
Serial.print(distance);
Serial.println(" CM");
delay(100);

  }
 //print it on the serial printer;
 Serial.print("sound:=");
 Serial.print("soundms");
 Serial.print(" m/s");
 Serial.print("Humidity:=");
 Serial.print("Hum");
 Serial.print("%  Temperature:");
 Serial.print("Temperature");
 Serial.print("C ");
 Serial.print("distance");
  
// make sure the LCD is clear screen;
lcd.clear();
 
  lcd.setCursor(0, 0); // Sets the location at which subsequent text written to the LCD will be displayed
  lcd.print("Sound:"); 
  lcd.print(soundms); 
 
  lcd.print("m/s");
  delay(10);
  lcd.setCursor(0, 1);
  lcd.print("Distance:");
  lcd.print(distance);
  lcd.print("CM");
  delay(10);
  
}