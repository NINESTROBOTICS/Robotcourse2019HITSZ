// Visual Micro is in vMicro>General>Tutorial Mode
// 
/*
    Name:       PWMforDCmotor.ino
    Created:	2019/11/19 20:03:00
    Author:     FWB
*/


#define PIN_PWM 10
#define PIN_AIN2 11
#define PIN_AIN1 12



// The setup() function runs once each time the micro-controller starts
void setup()
{
	pinMode(PIN_PWM, OUTPUT);
	pinMode(PIN_AIN2, OUTPUT);
	pinMode(PIN_AIN1 OUTPUT);

}

// Add the main program code into the continuous loop() function
void loop()
{
	analogWrite(PIN_PWM, 100);
	digitalWrite(PIN_AIN2, HIGH);
	digitalWrite(PIN_AIN1, LOW);
	delay(3000);

	analogWrite(PIN_PWM, 100);
	digitalWrite(PIN_AIN2, LOW);
	digitalWrite(PIN_AIN1, HIGH);
	delay(3000);

	analogWrite(PIN_PWM, 200);
	digitalWrite(PIN_AIN2, HIGH);
	digitalWrite(PIN_AIN1, LOW);
	delay(3000);

	analogWrite(PIN_PWM, 200);
	digitalWrite(PIN_AIN2, LOW);
	digitalWrite(PIN_AIN1, HIGH);
	delay(3000);

}
