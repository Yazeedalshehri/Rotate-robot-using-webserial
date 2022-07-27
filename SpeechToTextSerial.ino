#include <Servo.h>
Servo servo1;

String Left = "Left";
String Right = "Right";
String command = " ";
const byte servoPin = 2;
const byte LeftPosition = 0;
const byte CenterPosition = 90;
const byte RightPosition = 180;


void setup() {
  // Initialise the serial port
  Serial.begin(9600);
  servo1.attach(servoPin);
  servo1.write(CenterPosition);
}

void loop() {
  
  // If there is incoming data
  if (Serial.available() > 0) {
   
    command = Serial.readString();
    if(command.compareTo(Left)){
       servo1.write(LeftPosition);
       delay(100);  // Give it time to arrive
     }
      if(command.compareTo(Right)){
       servo1.write(RightPosition);
       delay(100);  // Give it time to arrive
     }
     
     

    // Write the data to the serial port
    Serial.println("I received: " + Serial.readString());
    
  }
  }