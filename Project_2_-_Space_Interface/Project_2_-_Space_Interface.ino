//Spaceship Interface Code

int switchState = 0;

//setup() configures digital pins to be inputs or outputs
void setup() {
  pinMode(3, OUTPUT); // green LED
  pinMode(4, OUTPUT); // red LED
  pinMode(5, OUTPUT); //red LED
  pinMode(2, INPUT); //button

}

void loop() {

  switchState = digitalRead(2);

  //button is not pressed
  if(switchState == LOW){

  digitalWrite(3, HIGH); //green LED
  digitalWrite(4, LOW); //red LED
  digitalWrite(5, LOW); //red LED
    
  } else { // button is pressed
    
  digitalWrite(3, LOW); //green LED
  digitalWrite(4, LOW); //red LED
  digitalWrite(5, HIGH); //red LED

  delay(500); //wait 0.25 seconds

 //toggle the LEDS
  digitalWrite(4, HIGH); //red LED
  digitalWrite(5, LOW); //red LED

  delay(500); //wait 0.25 seconds

  digitalWrite(4, HIGH); //red LED
  digitalWrite(5, HIGH); //red LED

  delay(500); //wait 0.25 seconds
  } // end if

} //end loop
