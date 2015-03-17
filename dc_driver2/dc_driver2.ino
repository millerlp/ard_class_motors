/*
	Run a DC motor with a N-channel MOSFET
	
	Arduino pin D9 to gate pin of MOSFET
	Drain pin of MOSFET to DC motor lead
	Source pin of MOSFET to GND
	Supply +12V to one lead of motor
	Place 1N4001 diode between +12V and GND lead of motor
	
*/


#define M1PWM 9 // Motor 1 pulse width modulation pin 9

void setup()
{
     Serial.begin(9600);
     Serial.print("Enter value from 0 to 255");
     Serial.println("to adjust motor speed.");
	pinMode(M1PWM, OUTPUT); // Motor1 PWM
	
}

void loop()
{
    if (Serial.available() > 0) {
      byte speed = Serial.read(); 
      Serial.print("New speed: ");
      Serial.println(speed);
    }
    analogWrite(M1PWM, speed);
    delay(100);

}
