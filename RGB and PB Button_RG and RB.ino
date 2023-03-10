/*
RGB Light and the PB button program
the main propose is understand the digital input and output(combine)
PB no press, RG ON and when press the PB, RB ON 
*/
int ledRed = 13;    //define the pin number, led pin connection
int ledGreen = 12;  //define the pin number, led pin connection
int ledBlue = 11;   //define the pin number, led pin connection
int onDelay = 1000; //delay time
int offDelay = 1000;//delay time
int pin9 = 9;  //define the pin number, led pin connection
int var =0;  //variable
void setup() {
  // put your setup code here, to run once:
 pinMode(13, OUTPUT); //define the pin output
 pinMode(12, OUTPUT);//define the pin output
 pinMode(11, OUTPUT);//define the pin output
 pinMode(9, INPUT_PULLUP);//define the pin input 
 Serial.begin(9600);
}
void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(13,HIGH);

 var = digitalRead(pin9); //variable store the value
  digitalWrite(12,var); //var equal 1  
  digitalWrite(11,!var);  //var not equal 1
 
  Serial.println(var); //check the var value ;troubleshooting 

}