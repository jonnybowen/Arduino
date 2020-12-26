//Learning how to control a servo with a photo-transistor.
//Variation of Project 5 - Servo

#include <Servo.h> // Servo Library

Servo myServo; //instantiate servo object

//Pins
int const photoPin = A0;   // The photo-transistor pin

//vars
//int photoRaw; // the raw input value from the photo-transistor
int photoVal; // the processed input value from the photo-transisotr
int angle;  // the angle to set the servo


void setup() {
  
  myServo.attach(9); // the pin to which the servo is attached
  Serial.begin(9600); // open a serial stream @ 9600 b/s

}

void loop() {

  //Read the photo-transistor value; map value to angle; actuate servo.

  photoVal = analogRead(photoPin);
  delay(5); // 5ms delay to reduce serial-monitor spam

  Serial.print("Photo-Val: "); //Print Serial Monitor Values
  Serial.print(photoVal);

  angle = map(photoVal, 0, 1023, 0, 179); //map photo-transistor values to 0-180 degrees


  Serial.print(", angle: "); //Print Serial Monitor Values
  Serial.println(angle);

  myServo.write(angle); // 
  delay(15); // 15ms delay until next reading


  

}
