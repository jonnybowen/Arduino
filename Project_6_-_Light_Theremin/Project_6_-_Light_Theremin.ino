// Use a phototransistor to control a piezo speaker.
// Calibrates current lighting conditions then works like a simple theremin but with light.

//Vars
int sensorValue;
int sensorHigh = 1023;
int sensorLow = 0;

//Constants
const int ledPin = 13; // Indicator that sensor has finished calibrating. Use onboard LED (Pin 13)

void setup() {
  // Change pinmode and turn the light on
  pinMode(ledPin,OUTPUT);
  digitalWrite(ledPin, HIGH);
  
  //Calibrate sensor's maximum ranges for 5 seconds.
  while(millis() < 5000){
    sensorValue = analogRead(A0);
    if (sensorValue > sensorHigh){
      sensorHigh = sensorValue;
    }
    if (sensorValue < sensorLow){
      sensorLow = sensorValue;
    }
  }
  digitalWrite(ledPin, LOW); // Turn off light when calibration finished.
 // Serial.begin(9600);
}



void loop() {
  // put your main code here, to run repeatedly:

sensorValue = analogRead(A0);
int pitch = map(sensorValue, sensorLow, sensorHigh, 50, 6000);
tone(8, pitch, 20);

//Serial.print("sensor value: ");
//Serial.print(sensorValue);
//Serial.print(", pitch: ");
//Serial.println(pitch);
delay(5);
}
