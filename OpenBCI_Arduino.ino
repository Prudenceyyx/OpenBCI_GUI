/* This program is part of the project Ferrofluid x Neural Architecture.
 * It is intended to realize the mind wave's control over 
 * physical objects with OpenBCI's Ganglion equipment and GUI 
 * in Processing.
 * It receives the EEG data of alpha wave sent from OpenBCI_GUI, 
 * and then sends the data mapped in range of 255 to a solenoid 
 * in order to make it move vertically. The value represents the
 * solenoid's altitude.

 *This program is developed based on the codes Conor Russomanno provided to the Class Spr17.
 */



//use the servo library because solenoid works in the same way
#include <Servo.h> 
Servo myservo;

int pos = 0; //inital altitude of the solenoid


int dist = 0;
int time = 50;


void setup() { 
  Serial.begin(115200);
  myservo.attach(9); //set pin9 to the solenoid
  myservo.write(pos); //set the inital altitude as 0
} 


void loop() {
  while (Serial.available()) {
    int newData = Serial.read();
    int dist=(int)map(newData,5,255,0,255);
    time=(int)map(newData,5,255,5,1);//the more it moves, the more time it needs.
    myservo.write(dist); 
    delay(time);// wait until the solenoid moves to the position 
  } 
  

  }




