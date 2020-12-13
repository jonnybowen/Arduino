//Learning how to control a servo with a potentiometer (dial).
//Rotating the potentiometer will move the servo through a range of 180 degrees.


#include <Servo.h> // Servo Library

Servo myServo; //instantiate servo object

//vars
int const potPin = A0;   // The potentiometer pin
int potVal; // the analogue input value
int angle;  // the angle to set the servo


void setup() {
myServo.attach(9); // the pin to which the servo is attached

Serial.begin(9600); // open a serial stream @ 9600 b/s
}

void loop() {

potVal = analogRead(potPin); // Read the analog potentiometer value from its pin

Serial.print("potVal: "); //Print Serial Monitor Values
Serial.print(potVal);

angle = map(potVal, 0, 1023, 0, 179); // map potentiometer value (0-1023) to the angle (0-179 degrees)

Serial.print(", angle: "); //Print Serial Monitor Values
Serial.println(angle);

myServo.write(angle); // 
delay(15); // 15ms delay until next reading

}
