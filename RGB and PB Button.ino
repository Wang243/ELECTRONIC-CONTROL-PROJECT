/*
RGB Light and the PB button program
the main propose is understand the digital input and output(combine)
no press, RGB shows White and when press the PB, RGB off 
*/
int ledRed = 13;    //define the pin number, led pin connection
int ledGreen = 12;  //define the pin number, led pin connection
int ledBlue = 11;   //define the pin number, led pin connection
int onDelay = 1000; //delay time
int offDelay = 1000;//delay time
int pin3 = 9;  //define the pin number, led pin connection
int var = pin3;  //variable
void setup() {
  // put your setup code here, to run once:
 pinMode(13, OUTPUT); //define the pin output
 pinMode(12, OUTPUT);//define the pin output
 pinMode(11, OUTPUT);//define the pin output
 pinMode(9, INPUT_PULLUP);//define the pin output 
 Serial.begin(9600);
}
void loop() {
  // put your main code here, to run repeatedly:
 var = digitalRead(pin3); //variable store the value
 if (var==1){
digitalWrite(13, HIGH); //ledWhite ON
digitalWrite(12, HIGH); //ledWhite ON
digitalWrite(11, HIGH); //ledWhite ON
delay(onDelay);         // ondelay
}
else {
digitalWrite(13, LOW);  //ledWhite Off
digitalWrite(12, LOW);  //ledWhite Off
digitalWrite(11, LOW);  //ledWhite Off
delay(offDelay);        // offdelay
}
 
  Serial.println(var); //check the var value ;troubleshooting 

}