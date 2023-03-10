/*
pull down program
the main propose is understand the digital input
using resistor to pulldown the voltage
compare with the Pull up, it needs adjust the PB to the 5 volt and input to the GND
it shows 0 when press the button, otherwise 1
*/
int ledPin = 13;    //define the pin number, led pin connection
int onDelay = 500; //delay time
int offDelay = 1000;//delay time
int var = ledPin;
void setup() {
  // put your setup code here, to run once:
 pinMode(13, INPUT); //define the pin output 
 Serial.begin(9600); //serial baudrate 9600
}

void loop() {
  // put your main code here, to run repeatedly:
 var = digitalRead(ledPin); //variable to store input value
 Serial.println(var);     //Serial print variable
 delay(offDelay);    //time delay
}
