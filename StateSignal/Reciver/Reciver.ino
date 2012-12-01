const int receivePin = 4;  // recive a signal through pin 4.
const int ledPin = 13;

int signal = LOW;
int pre_signal = LOW;

void setup() {
  // for reciving a signal
  // set the pin as input pin
  pinMode(receivePin, INPUT);

  pinMode(ledPin, OUTPUT);

  // Serial for debug
  Serial.begin(9600);
}

void loop() {
  signal = digitalRead(receivePin);

  if (signal==HIGH && pre_signal==LOW) {
    Serial.println("Begin of the signal"); 
    digitalWrite(ledPin, HIGH);
  }
  else if(signal==LOW && pre_signal==HIGH) {
    Serial.println("End of the signal");
    digitalWrite(ledPin, LOW);
  }

  // DON'T FORGET THIS!
  pre_signal = signal;

}


/*

NOTES:
based on StateChangeDetection example.
read a signal from another arduino
and detect when it begins and ends.

the detection is based on continuously look 
at previous value of the signal.

remember that the 2 arduinos must share the ground!

*/









