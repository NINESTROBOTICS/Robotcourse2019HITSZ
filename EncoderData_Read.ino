// Visual Micro is in vMicro>General>Tutorial Mode
// 
/*
    Name:       EncoderData_Read.ino
    Created:	2019/11/19 20:12:57
    Author:     FWB
*/

#define ENCODER_A 2
#define ENCODER_B 3

long encoderVal;

void getEncoder(void)
{
	if (digitalRead(ENCODER_A) == LOW)
	{
		if (digitalRead(ENCODER_B == LOW))
		{
			encoderVal--;
		}
		else
		{
			encoderVal++;
		}
	}
	else
	{
		if (digitalRead(ENCODER_B == LOW))
		{
			encoderVal++;
		}
		else
		{
			encoderVal--;
		}
	}
}

// The setup() function runs once each time the micro-controller starts
void setup()
{
	pinMode(ENCODER_A, INPUT);
	pinMode(ENCODER_B, INPUT);

	attachInterrupt(0, getEncoder, CHANGE);

	Serial.begin(9600);

}

// Add the main program code into the continuous loop() function
void loop()
{
	delay(100);
	Serial.print("encoder Val = ");
	Serial.print(encoderVal);
	Serial.print("\r\n");

}
