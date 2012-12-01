// include the I2C library.
#include <Wire.h>

const int slaveID = 1;

void setup() {
  Wire.begin(); // Wire.begin() without argument means: the master
  Serial.begin(9600);
}

byte x = 0;

void loop() {

  for(byte i=0; i<255; i++) { // one byte is 2^8 = 256

    Serial.print("Send one byte: ");
    Serial.print(i);
    sendByte(i);
    delay(300);

    byte echo = requestByte();
    Serial.print("echo back: ");
    Serial.println(echo);
    delay(300);
  }
}

void sendByte(byte n) {
  Wire.beginTransmission(slaveID); // transmit to device #4
  Wire.write(x);              // sends one byte  
  Wire.endTransmission();    // stop transmitting
}

byte requestByte() { 
  byte c;

  Wire.requestFrom(slaveID, 1); // request 1 byte from the slave

  // slave may send less than requested
  if(Wire.available()==1) {
    c = Wire.read();
  }

  return c;
}

/*

NOTES:

based on master_reader and master_writer examples.

send one byte and ask it back.
http://en.wikipedia.org/wiki/Echo_(computing)

one byte is a series of 8 bit (0 or 1), 
so it can contains a number between 0 and 255.

important note:
the communication (in both 2 ways) is beginned by the master.
I2C is a synchronous protocol.

it is important
to avoid that sending and receiving messages in the same time

that means avoid situations like:
begin to send                         (master --> slave)
request data from slave               (master <-- slave)
continue to send data or stop to send (master --> slave)

but it has to be:
begin to send                         (master --> slave)
continue to send data or stop to send (master --> slave)
request data from slave               (master <-- slave)

for this a good point could be add some delay
after send or request calls.

*/

