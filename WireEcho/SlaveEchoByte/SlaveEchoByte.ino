#include <Wire.h>

const int slaveID = 1;

byte receivedByte;

void setup()
{
  Wire.begin(slaveID); // join i2c bus with address slaveID
  Wire.onReceive(receiveEvent); // register event
  Wire.onRequest(requestEvent); // register event

  Serial.begin(9600);
}

void loop() {
  // nothing here. 
  // everything is handled by Wire.h interrupts
}

// function that executes whenever data is received from master
// in this example just save the data sent from the master
void receiveEvent(int howMany)
{
  if(Wire.available()==1) {
    receivedByte = Wire.read();
  }

  Serial.print("reveived one byte: ");
  Serial.println(receivedByte);
}

// request event means that master is asking data back.
// echo back the saved data.
void requestEvent() {
  Wire.write(receivedByte); 
}

/*

NOTES:

based on slave_reader and slave_writer examples.

receive one byte and echo back.
http://en.wikipedia.org/wiki/Echo_(computing)

note that everything is handled by interrupts called by Wire.h library.
remember that inside functions called by interrups
some timing utility are not available in the AVR michroprocessor
so don't use millis() micros() delay() or delayMicroseconds()
inside receiveEvent or requestEvent.

*/
