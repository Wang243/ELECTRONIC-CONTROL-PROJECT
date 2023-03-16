 /*
Potentionmeter change RGB color from black to White through different color variations.
 use the analog read to read the analog value;
 According to the value to write the output;
 */
int ledR = 13;  //define the pin number
int ledG = 12;  //define the pin number
int ledB = 11;  //define the pin number
float AI = A3;  //define the pin number
void setup() {
  
  pinMode(ledR, OUTPUT); //setup the pin function;
  pinMode(ledB, OUTPUT);//setup the pin function;
  pinMode(ledG, OUTPUT);//setup the pin function;
}

// the loop routine runs over and over again forever:
void loop() {
  AI = analogRead(A3);// read the analog value;
  // when the value less than the 50,RGB will be off;
if(AI<= 50){  
  analogWrite(ledR, 0);// RGB off
  analogWrite(ledB, 0);// RGB off
  analogWrite(ledG, 0);// RGB off

}
//when the value bigger than the 950;RGB will be white
else if (AI>=950){
  analogWrite(ledR, 255);//RGB fully ON ; white
  analogWrite(ledB, 255);//RGB fully ON ; white
  analogWrite(ledG, 255); //RGB fully ON ; white
}
//when the value bigger than 50 and less than 950;
// it will show the different color
else{
  analogWrite(ledR, AI/4); //RGB selector color;
  analogWrite(ledB, AI/8); //RGB selector color;
  analogWrite(ledG, AI/16); //RGB selector color; 
}

}

