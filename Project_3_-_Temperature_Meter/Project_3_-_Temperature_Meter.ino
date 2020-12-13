// Love-o-Meter (Temp Sensor) project.

//VARS AND CONSTS
  const int sensorPin = A0;
  const float ambientTemp = 22;

void setup() {

  Serial.begin(9600); //Open searial port at 9600 bits/s

  for(int pinNumber = 2; pinNumber<5; pinNumber++){
    pinMode(pinNumber, OUTPUT);
    digitalWrite(pinNumber, LOW);
  }
  
}

void loop() {
  // put your main code here, to run repeatedly:
  int sensorVal = analogRead(sensorPin);

  Serial.print("Sensor Value: ");
  Serial.println(sensorVal);

  //convert ADC reading to voltage
  float voltage = (sensorVal/1024.0) * 5.0;
  Serial.print("Volts: ");
  Serial.println(voltage);

  float temperature = (voltage -0.5) * 100;
  Serial.print("Degrees C: ");
  Serial.println(temperature);
  
  
  //Light Logic

  if (temperature < ambientTemp+2){ // No-result
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  } else if(temperature >= ambientTemp+2 && temperature < ambientTemp+4) { // Lowest Result
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  } else if(temperature >= ambientTemp+4 && temperature < ambientTemp+6) { // Middle Result
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
  } else if(temperature >= ambientTemp+6) { // Top Result
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
  }

  delay(1);
  
}
