

// NAME : Gaurish Bhatia
// Student ID: 2110994762.
//task : M1_T4D
//Remarks : in this task, we are required to use three sensors with interrupt driven approach.




// declaring global constants for the pins for LED, motion sensor and Ir sensor.
const int Led = 12;
const int motion_sensor_pin = 2;
const int ir_sensor_pin = 3;



void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);//declaring the Builtin LED as output.
  pinMode(Led, OUTPUT);//declaring the LED as output.
  pinMode(motion_sensor_pin, INPUT);//declaring the sensoro as input.
  attachInterrupt(digitalPinToInterrupt(motion_sensor_pin), motion, CHANGE);// attaching an interrupt taht will run the motion function on the change of state of the sensor.
  attachInterrupt(digitalPinToInterrupt(ir_sensor_pin), infrared, CHANGE);//attahing an interrupt for the change in value of the IR sensor.
  Serial.begin(9600);// beginning the serial communication at a baudrate of 9600.

  PCICR |= B00000100; //using the port group
  PCMSK2 |= B00100000;//using the D5 pin for the second IR sensor.

  //pausing all the interrupts.

  noInterrupts();

  //initialising the resisters as 0.
  TCCR1A = 0;
  TCCR1B = 0;
  TCNT1 = 0;

  OCR1A = 31429;//blinking built in Led every 2 seconds.

  TCCR1B |= (1 << CS12) | (1 << CS10);

  TIMSK1 |= (1 << OCIE1A);

  TCCR1B |= (1 << WGM12);

  interrupts();

}

void loop()// keeping the loop function empty
{

}


//function for chekcing the motion.
void motion()
{
  //reading the state of the sensor.
  int motion_state = digitalRead(motion_sensor_pin);

  //checking if the state is high.
  if (motion_state == HIGH)
  {
    Serial.println("Motion Present");//printing that motion is present.
    digitalWrite(Led, motion_state);// turning the LED on.
  }

  else if (motion_state == LOW)//checking if the motion ended.
  {
    Serial.println("Motion Ended");//printing that motion ended.
    digitalWrite(Led, motion_state);// turning the LED off.

  }




}


//function for checking if the IR sensor is active or inactive.
void infrared()
{
  //getting the value of the IR sensor.
  int ir_value = digitalRead(ir_sensor_pin);

  //checking if the sensor value is HIGH.
  if (ir_value == HIGH)
  {
    Serial.println("Ir sensor Active, turning the LED on");//printing that the IR sensor is active.
    digitalWrite(Led, ir_value);
  }
  //checking if the sensor value is low.
  else if (ir_value == LOW)
  {
    Serial.println("Ir sensor inactive,turning the LED off");//printing that the IR sensor is inactive.
    digitalWrite(Led, ir_value);
  }
}


//function for timer interrupt for blinking the built in LED.
ISR(TIMER1_COMPA_vect) {
  digitalWrite(LED_BUILTIN, digitalRead(LED_BUILTIN) ^ 1);//turning the LED on/off.
}


//function for pin change interrupt for IR sensor2.
ISR (PCINT2_vect) {

  Serial.println("IR sensor2 present");



}
