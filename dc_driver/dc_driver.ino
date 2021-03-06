/*
	Run a DC motor with a N-channel MOSFET
	
	Arduino pin D9 to gate pin of MOSFET
	Drain pin of MOSFET to DC motor lead
	Source pin of MOSFET to GND
	Supply +12V to one lead of motor
	Place 1N4001 diode between +12V and GND lead of motor
	
	http://bildr.org/2012/03/rfp30n06le-arduino/
*/


#define M1PWM 9 // Motor 1 pulse width modulation pin 9

void setup()
{
	pinMode(M1PWM, OUTPUT); // Motor1 PWM
	
}

void loop()
{
	for (byte i = 1; i <= 255; i++){
		analogWrite(M1PWM,i);
		delay(100);
	}
	analogWrite(M1PWM,0); // turn motor off
	delay(1000);
}
