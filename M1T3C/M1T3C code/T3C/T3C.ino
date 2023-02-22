// NAME : Gaurish Bhatia
// Student ID: 2110994762.
//task : M1_T3C
//Remarks : in this task, we are required to use two sensors with interrupt driven approach.

// declaring global constants for the pins for LED, motion sensor and Ir sensor.
const int Led = 12;
const int motion_sensor_pin = 2;
const int ir_sensor_pin = 3;


void setup()
{
  pinMode(Led, OUTPUT);//declaring the LED as output.
  pinMode(motion_sensor_pin, INPUT);//declaring the sensoro as input.
  attachInterrupt(digitalPinToInterrupt(motion_sensor_pin), motion, CHANGE);// attaching an interrupt taht will run the motion function on the change of state of the sensor.
  attachInterrupt(digitalPinToInterrupt(ir_sensor_pin), infrared, CHANGE);//attahing an interrupt for the change in value of the IR sensor.
  Serial.begin(9600);// beginning the serial communication at a baudrate of 9600.
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
    Serial.println("Motion Present, turning the LED on.");//printing that motion is present.
    digitalWrite(Led, motion_state);// turning the LED on.
  }

  else if (motion_state == LOW)//checking if the motion ended.
  {
    Serial.println("Motion Ended, turning the LED off.");//printing that motion ended.
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
