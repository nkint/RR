const int sendPin = 3; // send a signal through pin 3

void setup() {
  // for sending out a signal
  // set the pin as output pin
  pinMode(sendPin, OUTPUT);
  
  // serial for debug
  Serial.begin(9600);
}

void loop() {
  Serial.println("Begin of the signal");
  digitalWrite(sendPin, HIGH);
  delay(1000);

  Serial.println("End of the signal");  
  digitalWrite(sendPin, LOW);
  delay(1000);
}

/*

NOTES:
based on Blink example.
each 2 seconds send a signal for 1 second.

remember that the 2 arduinos must share the ground!

*/
