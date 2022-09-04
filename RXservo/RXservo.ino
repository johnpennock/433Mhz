/*
joystick.ino
  Program to test ability to control 2 servos remotely
  using a joystick on the transmitter

  2022 Aug 30 - Initial write
    create code to read joystick, and write values
    to 1602 LCD display
    
*/
//=============== libraries ===============

#include <Servo.h>                               // servo
#include <RCSwitch.h>                            // 433 Mhz tranmitter

//=============== variables ===============

int ledPin = 13;                                 // select the pin for the LED
//int rxPin = 10;                                  // RX pin
int panServoPin = 9;                             // pan servo pin

//=============== objects ===============

  //=============== servo  ===============
  Servo panServo;                                // create the pan servo object

  //=============== receiver ===============
  RCSwitch panRX = RCSwitch();

void setup() {  // code runs once

//=============== serial port ===============

  Serial.begin(9600);                            // enable serial port for debugging

  //=============== servo  ===============
  panServo.attach(panServoPin);                  // attach pan servo to pin
  
  //=============== receiver  ===============
  panRX.enableReceive(0);                        // attach transmitter to pin 2 (interrupt 0)

  Serial.print("RXservo.ino");                   // print out filename

}

void loop() {  // code runs repeatedly

  if (panRX.available()) {
    Serial.println(panRX.getReceivedValue());
    panServo.write(panRX.getReceivedValue());
    panRX.resetAvailable();
  }
//  delay(500);

}


