/*
PB value displayed on serial monitor;
PB=9;
blink(without using Delay)
Delay time 2S;
*/
 const int ledR=13; //the number of the LED pin
 int  PB=9; //the number of PB pin
 const long flashing=2000; //blink time(flashing)
 int ledState=LOW; //set LED state
 unsigned long previousMillis = 0;  // will store last time LED was updated
 int x; //variable to store pb state
void setup() {
  // put your setup code here, to run once:
 pinMode(ledR,OUTPUT); //set Pin mode
 pinMode(PB,INPUT_PULLUP);//set Pin mode
 Serial.begin(9600); //baud rate

}

void loop() {
  // put your main code here, to run repeatedly:
 delay(1000); // set delay to do the trobleshooting 

 x = digitalRead(PB); //store PB state
 Serial.print("PB state="); 
Serial.print(x);  //show to PB state,Serial Monitor;
 
// check to see if it's time to blink the LED; that is, if the difference
  // between the current time and last time you blinked the LED is bigger than
  // the interval at which you want to blink the LED.
  unsigned long currentMillis = millis(); //current time
//compare the current time and the previous time;if difference value is bigger than
//the flashing time,then store current time to previous time.otherwaise do next step
 if (currentMillis - previousMillis >= flashing){
   previousMillis = currentMillis;
   //flashing the led
   if (ledState == LOW){
     ledState  = HIGH;
   }
   else{
     ledState =LOW;
   }
   // Write the led state;
   digitalWrite(ledR,ledState);
 }
 Serial.print("\t");
 Serial.print("LED state="); 
 Serial.println(ledState); 

}
