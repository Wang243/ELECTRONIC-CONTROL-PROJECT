// DHT Temperature & Humidity Sensor
//IT WILL display it on the LCD
//using pushbutton to select different options;
//three options:temperature Celsius, Fahrenheit,and the humidity

#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

#define DHTPIN 2     // Digital pin connected to the DHT sensor 
 
// Uncomment the type of sensor in use:
#define DHTTYPE    DHT11     // DHT 11
 

DHT_Unified dht(DHTPIN, DHTTYPE);

uint32_t delayMS;
// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);
byte customChar[] = {
  B00000,
  B00000,
  B01110,
  B10001,
  B10001,
  B01110,
  B00000,
  B00000
};
int PBpin=13;
//int button_state;
int counter=0;
int lastButtonState = HIGH;
void setup() {
  Serial.begin(9600);
  // Initialize device.
  dht.begin();
  Serial.println(F("DHT11 Unified Sensor Example"));
  // Print temperature sensor details.
  sensor_t sensor;
  dht.temperature().getSensor(&sensor);
  Serial.println(F("------------------------------------"));
  Serial.println(F("Temperature Sensor"));
  Serial.print  (F("Sensor Type: ")); Serial.println(sensor.name);
  Serial.print  (F("Driver Ver:  ")); Serial.println(sensor.version);
  Serial.print  (F("Unique ID:   ")); Serial.println(sensor.sensor_id);
  Serial.print  (F("Max Value:   ")); Serial.print(sensor.max_value); Serial.println(F("°C"));
  Serial.print  (F("Min Value:   ")); Serial.print(sensor.min_value); Serial.println(F("°C"));
  Serial.print  (F("Resolution:  ")); Serial.print(sensor.resolution); Serial.println(F("°C"));
  Serial.println(F("------------------------------------"));
  // Print humidity sensor details.
  dht.humidity().getSensor(&sensor);
  Serial.println(F("Humidity Sensor"));
  Serial.print  (F("Sensor Type: ")); Serial.println(sensor.name);
  Serial.print  (F("Driver Ver:  ")); Serial.println(sensor.version);
  Serial.print  (F("Unique ID:   ")); Serial.println(sensor.sensor_id);
  Serial.print  (F("Max Value:   ")); Serial.print(sensor.max_value); Serial.println(F("%"));
  Serial.print  (F("Min Value:   ")); Serial.print(sensor.min_value); Serial.println(F("%"));
  Serial.print  (F("Resolution:  ")); Serial.print(sensor.resolution); Serial.println(F("%"));
  Serial.println(F("------------------------------------"));
  // Set delay between sensor readings based on sensor details.
  delayMS = sensor.min_delay / 1000;
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
 
  lcd.createChar(0, customChar);
  pinMode(PBpin,INPUT_PULLUP);
}

void loop() {
   
  // Delay between measurements.
  delay(delayMS);
  // Get temperature event and print its value.
  sensors_event_t event;
  dht.temperature().getEvent(&event);
  if (isnan(event.temperature)) {
    Serial.println(F("Error reading temperature!"));
  }
  else {
    Serial.print(F("Temperature: "));
     
    Serial.print(event.temperature);
    
    Serial.println(F("°C"));
     
  }
  // Get humidity event and print its value.
  dht.humidity().getEvent(&event);
  if (isnan(event.relative_humidity)) {
    Serial.println(F("Error reading humidity!"));
  }
  else {
     // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
    Serial.print(F("Humidity: "));
     
    Serial.print(event.relative_humidity);
     
    Serial.println(F("%"));
   
  }
int  buttonState = digitalRead(PBpin);
 float  x = (event.temperature*9/5)+32.0;
 // using the denounce function;
 if (buttonState == LOW && lastButtonState == HIGH) {
   delay(50);
 } 
 if (buttonState == LOW) {
   counter++; 
 }
  if (counter > 3)
  {
   counter = 1;
 }
   switch (counter) {
     case 1:
     lcd.setCursor(0,0);
     lcd.print(F("Hum:"));
     lcd.print(event.relative_humidity);
     lcd.print(F("%"));
     lcd.print("  ");
     break ; 
     case 2:
     lcd.setCursor(0,0);
     lcd.print(F("Temp:"));
     lcd.print(event.temperature);
     lcd.write((byte)0);
     lcd.print(F("C"));
     break ;
     case 3:
     lcd.setCursor(0,0);
     lcd.print(F("Far:"));
     lcd.print(x);
     lcd.print(F("F"));
   }
}