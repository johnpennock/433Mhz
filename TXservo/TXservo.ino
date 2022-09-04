/*
joystick.ino
  Program to test ability to control 2 servos remotely
  using a joystick on the transmitter

  2022 Aug 30 - Initial write
    create code to read joystick, and write values
    to 1602 LCD display
    
*/
//=============== libraries ===============
#include <RCSwitch.h>                            // 433 Mhz tranmitter

//=============== variables ===============
int panPin = A1;                                 // input pin for pan
int ledPin = 13;                                 // select the pin for the LED
int txPin = 10;                                  // TX pin

int panValue = 0;                                // pan value
int panMapValue = 0;

//=============== objects ===============
  //=============== transmitter  ===============
  RCSwitch panTX = RCSwitch();

void setup() {  // code runs once

//=============== serial port ===============
  Serial.begin(9600);                            // enable serial port for debugging

  //=============== transmitter  ===============
  panTX.enableTransmit(txPin);                   // attach transmitter to pin

  Serial.print("TXservo.ino");                  // print out filename
}  // end of setup

void loop() {  // code runs repeatedly

// read joystick and map values
  panValue = analogRead(panPin);                 // read the pan value
  panMapValue = map(panValue, 0, 1023, 1, 180);

// write to serial port

  Serial.print("Pan raw: ");
  Serial.print(panValue);
  Serial.print(" mapped:");
  Serial.print(panMapValue);
  Serial.println();

// transmit pan value
  panTX.send(panMapValue, 30);

}  // end of main loop
