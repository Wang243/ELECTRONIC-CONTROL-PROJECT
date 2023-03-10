/*
Input pull up program
the main propose is understand the digital input
using input pullup function  
it shows 1 when press the button, otherwise 0
*/
int ledPin = 13;    //define the pin number, led pin connection
int onDelay = 500; //delay time
int offDelay = 1000;//delay time
int var = ledPin;
void setup() {
  // put your setup code here, to run once:
 pinMode(13, INPUT_PULLUP); //define the pin output 
 Serial.begin(9600); //serial baudrate 9600
}

void loop() {
  // put your main code here, to run repeatedly:
 var = digitalRead(ledPin); //variable to store input value
 Serial.print("PB Value = "); //show the text"PB value"
 Serial.println(var);     //Serial print variable, next line
 delay(offDelay);    //time delay
}