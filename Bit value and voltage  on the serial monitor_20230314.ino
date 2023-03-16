 /*
 Connect potentimeter and display Bit value and voltage value on serial monitor.
 using analog input
 input:10bit;output:8bit
 */

float AI = A3;//Data type
float x; //variable for calculate;
// the setup routine runs once when you press reset:
void setup() { 
  Serial.begin(9600);// communcation baud rate
}

// the loop routine runs over and over again forever:
void loop() {
  AI = analogRead(A3); //Read the analog value and store in AI
  delay(50); //delay,for monitor
  x=(AI/1023)*5; //calcuiation
  Serial.print("AI voltage = "); //print the text:AI voltage
  Serial.print(x); //print the voltage
  delay(500);//delay,for monitor
  Serial.print("\t");// space for between print
  Serial.print("AI Analog value= ");//print the text:AI analog value
  Serial.println(AI);//print the bit value
}
