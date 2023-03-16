 /*
 RGB color selector
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
if(AI<= 100){  
  digitalWrite(ledR, 0);// RGB off
  digitalWrite(ledB, 0);// RGB off
  digitalWrite(ledG, 0);// RGB off

}
//when the value bigger than the 950;RGB will be white
else if (AI>100&&AI<=400){
  digitalWrite(ledR, 1);//RGB fully ON ; white
  digitalWrite(ledB, 0);//RGB fully ON ; white
  digitalWrite(ledG, 0); //RGB fully ON ; white
}
//when the value bigger than 50 and less than 950;
// it will show the different color
else if(AI>400&&AI<=600){
  digitalWrite(ledR, 0); //RGB selector color;
  digitalWrite(ledB, 1); //RGB selector color;
  digitalWrite(ledG, 0); //RGB selector color; 
}
else if(AI>600&&AI<=800){
  digitalWrite(ledR, 0); //RGB selector color;
  digitalWrite(ledB, 0); //RGB selector color;
  digitalWrite(ledG, 1); //RGB selector color; 
}
else if(AI>800){
  digitalWrite(ledR, 1); //RGB selector color;
  digitalWrite(ledB, 1); //RGB selector color;
  digitalWrite(ledG, 1); //RGB selector color; 

}
}
