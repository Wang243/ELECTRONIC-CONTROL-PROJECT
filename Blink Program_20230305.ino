/*
  The Arduino blink program
  BlinkTurns an LED on for one second, then off for one second, repeatedly.
*/
int ledBlink = 13;
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(ledBlink, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(ledBlink, HIGH);  // turn the LED on
  delay(1000);                      // wait for a second
  digitalWrite(ledBlink, LOW);   // turn the LED off  
  delay(1000);                      // wait for a second
}
