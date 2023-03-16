/*
LCD with Arduino to work as ohmmeter with display the OHM symbol
using LCD Custom Character Generator to create Ohm symbol

*/
// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);
// declare the data type
 float AI = A0; 
 int ondelay = 500;
 float measurevalue;
 int Ra=989;
 float Rb;
 float I;
 //create Ohm symbol,byte
 byte customChar[] = {
  B00000,
  B01110,
  B10001,
  B10001,
  B01010,
  B11011,
  B00000,
  B00000
};
void setup() {
  // put your setup code here, to run once:
pinMode(A0,INPUT); //
Serial.begin(9600);
// set up the LCD's number of columns and rows:
  lcd.begin(16, 2); //show LCD position
  lcd.createChar(0, customChar);//Ohm symbol create
}
 
void loop() {
  // put your main code here, to run repeatedly:
AI=analogRead(A0);//read the analog value
Serial.print("AI = ");//print text
Serial.print(AI);//print value

Serial.print("\t");//space
measurevalue = (AI/1023.0)*5.0;//calculation
Serial.print("  measurevoltagevalue = ");//print text
Serial.print(measurevalue);//print value
 
I = (5-measurevalue)/Ra; //calculate the current
Rb= measurevalue/I;//calculate the resistor
//print on the serial monitor,do troublshooting
Serial.print("    I_Current=");
Serial.print(I);
Serial.print("\t");
Serial.print("  RB_value= ");
Serial.println(Rb);

//delay(ondelay);
 // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 0);//LCD print position
  lcd.print("Rb = ");//LCD print text
  lcd.print(Rb);//LCD print the value
  lcd.write(byte(0));//LCD write the Ohm symbol
  delay(ondelay);

}
