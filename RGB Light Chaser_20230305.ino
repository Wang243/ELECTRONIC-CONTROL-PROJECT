/*
RGB Light chaser program
the main propose is understand the digital output
using RGB to show LED:red blue green and white
it shows RGB light ON red blue green and white,then back
*/
int ledRed = 13;    //define the pin number, led pin connection
int ledGreen = 12;  //define the pin number, led pin connection
int ledBlue = 11;   //define the pin number, led pin connection
int onDelay = 500; //delay time
int offDelay = 500;//delay time
void setup() {
  // put your setup code here, to run once:
 pinMode(13, OUTPUT); //define the pin output
 pinMode(12, OUTPUT);//define the pin output
 pinMode(11, OUTPUT);//define the pin output
  
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(13, HIGH); //ledred ON
delay(onDelay);         // ondelay
digitalWrite(13, LOW);  //ledred Off
delay(offDelay);        // offdelay
digitalWrite(12, HIGH); //ledGreen ON
delay(onDelay);         // ondelay
digitalWrite(12, LOW);  //ledGreen Off
delay(offDelay);        // offdelay
digitalWrite(11, HIGH); //ledBlue ON
delay(onDelay);         // ondelay
digitalWrite(11, LOW);  //ledBlue Off
delay(offDelay);        // offdelay
digitalWrite(13, HIGH); //ledWhite ON
digitalWrite(12, HIGH); //ledWhite ON
digitalWrite(11, HIGH); //ledWhite ON
delay(onDelay);         // ondelay
digitalWrite(13, LOW);  //ledWhite Off
digitalWrite(12, LOW);  //ledWhite Off
digitalWrite(11, LOW);  //ledWhite Off
delay(offDelay);        // offdelay
digitalWrite(11, HIGH); //ledBlue ON
delay(onDelay);         // ondelay
digitalWrite(11, LOW);  //ledBlue Off
delay(offDelay);        // offdelay
digitalWrite(12, HIGH); //ledGreen ON
delay(onDelay);         // ondelay
digitalWrite(12, LOW);  //ledGreen Off
delay(offDelay);        // offdelay
}