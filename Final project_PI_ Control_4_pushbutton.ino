/*
Final Project PI Mode;
using LCD and 4 Pushbutton; first pushbutton is make the value up; second pushbutton is make the value down;
The third and the fourth pushbutton is select the SP or HYS;
*/
int Sensor=A1;  //LDR sensor input
int inputPin=5;//the pin for the Pushbutton, make the set point count up
int inputPin_down=6;//the pin for the Pushbutton,make the set point count down
int inputPin_left=3;//the pin for the Pushbutton, this is left;select SP;
int inputPin_right=4;//the pin for the Pushbutton, this is right;select HYS;
bool left;
bool right;
int select_di=0;// for the logic select;
int actuator=11;// led connect pin13
int pv=0; //Process variable which is also the LDR value
int inputvalue=0;// this is setpoint value
int co=0;//control output value; 0 or 255;
int error=0;// pv-inputvalue;
int HYS=30;//Hysteresis Value
float pGain=2.0; //declaire the P gain Variable;
float iGain=1.1;
int setpoint;
int intergralaction;
unsigned long previousMillis=0;
const long interval=100;
unsigned long currentMillis;
bool buttonState;            // the current reading from the input pin
bool buttonState_down;   //pushbutton funcation
bool buttonState_left;   ////pushbutton funcation
bool buttonState_right;   //pushbutton funcation
int lastButtonState = LOW;  // the previous reading from the input pin
unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
unsigned long debounceDelay = 50;    // the debounce time; increase if the output flickers

#include <LiquidCrystal.h>
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(7, 8, 9, 10, 13, 12);

void setup() {
  // put your setup code here, to run once:
pinMode(actuator, OUTPUT); //declare the actuator pin as an output;
pinMode(inputPin, INPUT_PULLUP); //declare the pushbutton pin as an input;
pinMode(inputPin_down, INPUT_PULLUP); //declare the pushbutton pin as an input;
pinMode(inputPin_left, INPUT_PULLUP); //declare the pushbutton pin as an input;
pinMode(inputPin_right, INPUT_PULLUP); //declare the pushbutton pin as an input;
Serial.begin(9600);//speed of communication
// set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
}
void loop() { 
  //delay(100);
  // put your main code here, to run repeatedly:
 pv=analogRead(Sensor); //read the sensor value;
 inputvalue=analogRead(inputPin); //  value;it should be input value.
 currentMillis=millis();

  left=digitalRead(inputPin_left);
  right=digitalRead(inputPin_right);
  //when the left =0;then make the select_di=0; this is for the logic swith case;
  if(left==0){
    select_di=select_di+1;
  }
  if(right==0){
    select_di=select_di-1;
  }
  if(select_di >=2){//condition for when select is bigger than the number
  //this is important to set the number of the parameteres being controlled
  select_di = 2;//= the number if it passes it
}
if(select_di <=0){
  //the same goes for the other way around, the number for the pages is limited to 0

  select_di = 0;//= the number if it goes below it
}
  buttonState=digitalRead(inputPin);
  /*if (buttonState != lastButtonState) {
    // reset the debouncing timer
    lastDebounceTime = millis();
  }*/ 
  if(currentMillis - previousMillis>=interval ) {
    previousMillis=currentMillis;
    error=(setpoint-pv);
    intergralaction = (intergralaction + error);
    co= ((pGain * error)+ (iGain*intergralaction ))/500;
    if(co>255){
   co=255;
 }
 if(co<0){
   co=0;
 }
  }
analogWrite(actuator,co);//writing the co to the actuator

lcd.clear();
//delay(30);
// set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 0); // set the cursor to column 1, line 1
  lcd.print("pv= ");//print the text voltage
  lcd.print(pv);//print the value
   //delay(10);
  lcd.print("           "); //make a space
  lcd.setCursor(8, 0);
   
  lcd.print("err="); //print the text co;
  lcd.print(error); //print the value
  // delay(10);
  switch(select_di){
    case 0:
    if (buttonState==LOW && millis()-lastDebounceTime>50){
    //when press the button, the Sp plus 50;
     //delay(50);
    setpoint=setpoint+50;
  
  }
  buttonState_down=digitalRead(inputPin_down);
  if (buttonState_down != lastButtonState) {
    // reset the debouncing timer
    lastDebounceTime = millis();
  }
 
  if (buttonState_down==LOW){
    
    setpoint=setpoint-50;
 
  }
 inputvalue=setpoint;
 //the input shuld be 0-1024;so make a reasonable range.
 if(setpoint>=1024){
   setpoint=1024;
 }
if(setpoint<=0){
   setpoint=0;
 }
//lcd.clear();
//delay(2000);
    lcd.setCursor(0, 1); 
  lcd.print("SP= "); //print the text co;
  lcd.print(inputvalue); //print the value
  break;
  case 1:
  if (buttonState==LOW && millis()-lastDebounceTime>50){
    
    //setpoint=setpoint+50;
    pGain=pGain+0.1;
  
  }
  if(pGain<=0){
   pGain=0;
 }
  buttonState_down=digitalRead(inputPin_down);
  if (buttonState_down != lastButtonState) {
    // reset the debouncing timer
    lastDebounceTime = millis();
  }
 
  if (buttonState_down==LOW){
    
    //setpoint=setpoint-50;
    pGain=pGain-0.1;
  }
 inputvalue=setpoint;
  lcd.setCursor(0, 1); 
  lcd.print("pGain= "); //print the text co;
  lcd.print(pGain); //print the value
  break;

case 2:
  if (buttonState==LOW && millis()-lastDebounceTime>50){
    
    //setpoint=setpoint+50;
    iGain=iGain+0.1;
  
  }
  if(iGain<=0){
   iGain=0;
  }
  buttonState_down=digitalRead(inputPin_down);
  if (buttonState_down != lastButtonState) {
    // reset the debouncing timer
    lastDebounceTime = millis();
  }
 
  if (buttonState_down==LOW){
    
    //setpoint=setpoint-50;
    iGain=iGain-0.1;
  }
 inputvalue=setpoint;
  lcd.setCursor(0, 1); 
  lcd.print("iGain= "); //print the text co;
  lcd.print(iGain); //print the value
delay(10);
}
//Serial.print, to show on the serial monitor;

Serial.print(inputvalue);
Serial.print(",");
Serial.print(pv);
Serial.print(",");
Serial.print(error);
Serial.print(",");
Serial.print(pGain);
Serial.print(",");
Serial.print(iGain);
 Serial.print("setpoint = ");
Serial.print(inputvalue);
// delay(10);
//Serial.print("\t co =  ");
//Serial.print(co);
Serial.print("\t PV =  ");
Serial.print(pv);

Serial.print("\t error =  ");
Serial.print(error);
Serial.print("\t pGain =  ");
Serial.print(pGain);
Serial.print("\t iGain =  ");
Serial.print(iGain);
Serial.println();
}