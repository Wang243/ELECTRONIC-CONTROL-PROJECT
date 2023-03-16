 /*
Connect LCD  
and display bitvalue and voltage on the same screen
Be familiar with library.
Using the hello word as reference.
*/
// include the library code:
#include <LiquidCrystal.h>
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);
int AI=A3; //define analog input pin number
float x;// variable data type
void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  Serial.begin(9600);
  // Print a message to the LCD.  
}
void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(1, 0);
  AI = analogRead(A3); //read the analog value
  lcd.print("BitValue= "); //print the text Bitvalue
  lcd.print(AI); //print the value
    delay(100);
  lcd.setCursor(1, 1); // set the cursor to column 1, line 1
  lcd.print("voltage= ");//print the text voltage
  lcd.print(x);//print the value
    delay(100);
  lcd.print("           "); //make a space
  delay(100);
 //below code is familir, it was used many times.
  x=(AI/1023.0)*5.0; 
  Serial.print("voltage = ");
  Serial.print(x);
  delay(100);
  Serial.print("\t");//make a space
  Serial.print("AI BitValue value= ");
  Serial.println(AI);  
}

