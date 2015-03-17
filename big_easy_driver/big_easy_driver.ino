/*  Stepper motor example with Big Easy Driver
    Connect ground, pin 8 + 9 to BED

    Motor Red + Blue to A
    Motor Green + Black to B
*/

const byte stepperDir = 8;  // stepper direction pin
const byte stepperStep = 9; // stepper step pin
const byte stepperEnable = 10; // Big easy driver enable pin
const byte button1 = 2; // override button
byte dir = 0; // motor direction variable

const int stepDelay = 200; // delay for 1/16 step mode, microseconds
// A value around 200-250 seems to produce the best power.
unsigned int stepVal = 3200; // number of steps per button press


void setup() {

  pinMode(stepperDir, OUTPUT);
  pinMode(stepperStep, OUTPUT);
  pinMode(stepperEnable, OUTPUT);
  pinMode(button1, INPUT_PULLUP); // use internal pullup resistor for button1

  digitalWrite(stepperEnable, HIGH);  // disables stepper when high
  digitalWrite(stepperDir, LOW); // Set initial direction
  digitalWrite(stepperStep, LOW); // hold LOW when not moving
}


void loop() {
	// Use button to reverse direction
	dir = digitalRead(button1); // set value of dir using digital read
  
	digitalWrite(stepperEnable, LOW); // enable stepper motor controller
	digitalWrite(stepperDir, dir); // use dir to set direction
	// Use for loop to send out correct number of step commands
	// based on the number of steps specified in stepVal
	for (unsigned int steps = 0; steps < stepVal; steps++) {
		digitalWrite(stepperStep, HIGH); // initiate step
		delayMicroseconds(stepDelay); // pause to let motor move
		digitalWrite(stepperStep, LOW); // finish step
	}
	digitalWrite(stepperEnable, HIGH); // turn off motor controller
	delay(500); // pause between rotations
} // end main loop

