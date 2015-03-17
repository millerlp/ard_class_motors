/*

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
