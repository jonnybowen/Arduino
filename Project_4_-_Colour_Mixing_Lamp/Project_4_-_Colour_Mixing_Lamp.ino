//A project to create a colour-changing light that responds to external lighting conditions.
//JB

//Declare LED Pins
const int greenLEDPin = 9;
const int redLEDPin = 10;
const int blueLEDPin = 11;

//Declare Phototransistor Pins
const int redSensorPin = A0;
const int greenSensorPin = A1;
const int blueSensorPin = A2;

//Declare Vars
int redValue = 0; // processed sensor input value
int greenValue = 0;
int blueValue = 0;

int redSensorValue = 0; //raw sensor input value
int greenSensorValue = 0;
int blueSensorValue = 0;


void setup() {
  Serial.begin(9600);

  pinMode(greenLEDPin, OUTPUT);
  pinMode(redLEDPin, OUTPUT);
  pinMode(blueLEDPin, OUTPUT);
}

void loop() {
  redSensorValue = analogRead(redSensorPin);
  delay(5);
  blueSensorValue = analogRead(blueSensorPin);
  delay(5);
  greenSensorValue = analogRead(greenSensorPin);
  delay(5);



  //values for PWM analogWrite() - range 0-255
  //divide raw values by 4 to get PWM value.

  redValue = redSensorValue/4;
  blueValue = blueSensorValue/4;
  greenValue = greenSensorValue/4;


  Serial.print("Mapped Sensor Values \t red: ");
  Serial.print(redValue);
  Serial.print("\t green: ");
  Serial.print(greenValue);
  Serial.print("\t blue: ");
  Serial.println(blueValue);

  analogWrite(redLEDPin, redValue);
  analogWrite(greenLEDPin, greenValue);
  analogWrite(blueLEDPin, blueValue);
}
