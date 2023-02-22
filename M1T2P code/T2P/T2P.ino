// NAME : Gaurish Bhatia
// Student ID: 2110994762.
//Remarks : in this task, we were required to use the sense think and act system with interrupt driven approach.

// declaring global constants for the pins for LED and motion sensor.
const int Led = 12;
const int sensor_pin = 2;


void setup()
{
  pinMode(Led, OUTPUT);//declaring the LED as output.
  pinMode(sensor_pin, INPUT);//declaring the sensoro as input.
  attachInterrupt(digitalPinToInterrupt(sensor_pin), motion, CHANGE);// attaching an interrupt taht will run the motion function on the change of state of the sensor.
  Serial.begin(9600);
}

void loop()// keeping the loop function empty
{
}


//function for chekcing the motion.
void motion()
{
  //reading the state of the sensor.
  int motion_state = digitalRead(sensor_pin);
  
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
