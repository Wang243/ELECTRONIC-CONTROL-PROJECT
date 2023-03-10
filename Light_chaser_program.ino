/*
Light chaser program
the main propose is understand the digital output
using 5 colour LED:red green blue yellow and white
it shows LED light ON one by one
*/
int ledRed = 13;    //define the pin number, led pin connection
int ledGreen = 12;  //define the pin number, led pin connection
int ledBlue = 11;   //define the pin number, led pin connection
int ledYellow = 10; //define the pin number, led pin connection
int ledWhite = 9;   //define the pin number, led pin connection
int onDelay = 100; //delay time
int offDelay = 100;//delay time
void setup() {
  // put your setup code here, to run once:
 pinMode(13, OUTPUT); //define the pin output
 pinMode(12, OUTPUT);//define the pin output
 pinMode(11, OUTPUT);//define the pin output
 pinMode(10, OUTPUT);//define the pin output
 pinMode(9, OUTPUT);//define the pin output

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
digitalWrite(10, HIGH); //ledYellow ON
delay(onDelay);         // ondelay
digitalWrite(10, LOW);  //ledYellow Off
delay(offDelay);        // offdelay
digitalWrite(9, HIGH); //ledWhite ON
delay(onDelay);         // ondelay
digitalWrite(9, LOW);  //ledWhite Off
delay(offDelay);        // offdelay
digitalWrite(10, HIGH); //ledYellow ON
delay(onDelay);         // ondelay
digitalWrite(10, LOW);  //ledYellow Off
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
