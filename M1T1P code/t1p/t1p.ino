//Name : Gaurish Bhatia
//Student ID : 2110994762
// Task M1.T1.P


//declaring the global constants for the LED pin, sensor pin, state and input.
int Led = 12;
int Sensor_pin = 4;
int sesor_state = LOW;
int input = 0;


//Setup function, this will run once.
void setup() {

  pinMode(Led, OUTPUT); // setting the Led as output
  pinMode(Sensor_pin, INPUT);  // setting the sensor pin as input.

  Serial.begin(9600);// beginning the serial communication at a baud rate of 9600.
}

//loop function, runs forever until program stopped.
void loop() {

  input = digitalRead(Sensor_pin);//checking the input value.

  // checking if the input value is high.
  if (input == HIGH) {

    digitalWrite(Led, HIGH);  // turning the LED on.

    // checking the state of the sensor.

    if (sesor_state == LOW) {

      Serial.println("Motion Present");

      sesor_state = HIGH;// changing the state to 1.
    }

  }

  // checking if the input value is low.
  else {
    digitalWrite(Led, LOW); // turning the LED off.

    // checking the state of the sensor.
    if (sesor_state == HIGH) {
      //printing on the serial monitor , that motion is not present.

      Serial.println("Motion ended");


      sesor_state = LOW;// changing the state to low.
    }
  }
}
