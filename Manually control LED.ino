/*
Final Project Manual Mode;
*/
int Sensor=A1;  //LDR sensor input
int inputPin=A5;//the pin for the potentiometer, this is set point
int actuator=11;// led connect pin11
int pv=0; //Process variable which is also the LDR value
int inputvalue=0;// this is poteniometer value
int co=0;//control output value
int error=0;
#include <LiquidCrystal.h>
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(7, 8, 9, 10, 13, 12);

void setup() {
  // put your setup code here, to run once:
pinMode(actuator, OUTPUT); //declare the actuator pin as an output;
Serial.begin(9600);//speed of communication
// set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
}

void loop() {
  // put your main code here, to run repeatedly:
 pv=analogRead(Sensor); //read the sensor value;
 inputvalue=analogRead(inputPin);//read the poteniometer value;it should be input value.
 co=map(inputvalue, 0,1023,0,255);//Maping the output to the input 
analogWrite(actuator,co);//writing the co to the actuator
error=pv-inputvalue;
// set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 0);
   
  lcd.print("co= "); //print the text co;
  lcd.print(co); //print the value
   // delay(100);
  lcd.setCursor(0, 1); // set the cursor to column 1, line 1
  lcd.print("pv= ");//print the text voltage
  lcd.print(pv);//print the value
   // delay(100);
  lcd.print("           "); //make a space
  //delay(100);
//Serial.print, to show on the serial monitor;
 
Serial.print(inputvalue);

Serial.print("，");
Serial.print(co);
Serial.print("，");
Serial.print(pv);
Serial.print("，");
Serial.print(error);
Serial.print("input = ");
Serial.print(inputvalue);
Serial.print("\t co =  ");
Serial.print(co);
Serial.print("\t PV =  ");
Serial.print(pv);
Serial.print("\t error =  ");
Serial.print(error);
Serial.println();
//delay(100);
}
