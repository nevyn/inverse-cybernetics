#include <Wire.h>

/*******************Setup Loop***************************/
void setup() {
  // output mode on the 8 "bits"
  for(int i = 0+2; i < 8+2; i++) {
    pinMode(i, OUTPUT);
  }

  // Pin 13 is the status LED on both the EL Sequencer and Arduino for use with the EL Escudo Dos. 
  pinMode(13, OUTPUT);   
  
  Serial.begin(9600); 
  
  // join i2c bus with address #1337
  Wire.begin(1337);
  Wire.onRequest(i2c_event);
}

void actuateByte(byte x, int duration, int margin) {
  // Turn on the lamps with corresponding bit positions
  for(int i = 0; i < 8; i++) {
    bool state = (x & 1 << i) != 0;
    digitalWrite(i+2, state);
  }
  // indicate on status led that byte is being actuated
  digitalWrite(13, HIGH);
  // wait until actuation period has elapsed
  delay(duration);
  // All off
  for(int i = 0; i < 8; i++) {
    digitalWrite(i+2, LOW);
  }
  digitalWrite(13, LOW);
  // Add some margin to the actuation of the next byte
  delay(margin);
}

void processByteRequest(char x) {
    Serial.print("actuating ");
    Serial.print(x);
    Serial.println("");
    actuateByte(x, 5, 200);
}

/*******************Main Loop***************************/
void loop() 
{
  
}

// Wired
void serialEvent()
{
  while (Serial.available()) {
    char x = Serial.read();
    processByteRequest(x);
  }
}

// Wireless
void i2c_event() {
  while (Wire.available()) {
    char c = Wire.read();
    processByteRequest(c);
  }
}


