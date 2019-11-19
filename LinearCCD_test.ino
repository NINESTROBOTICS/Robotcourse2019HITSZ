// Visual Micro is in vMicro>General>Tutorial Mode
// 
/*
	Name:       LinearCCD_test.ino
	Created:	2019/11/19 20:21:26
	Author:     FWB
*/

#define A0_PIN 14
#define CLK_PIN 15
#define SI_PIN 16

uint8_t _adVal[128];
uint8_t _ccdThreshold;

void ccdinit(void)
{
	pinMode(CLK_PIN, OUTPUT);
	pinMode(SI_PIN, OUTPUT);
	pinMode(A0_PIN, INPUT);
	digitalWrite(CLK_PIN, LOW);
	digitalWrite(SI_PIN, LOW);
}

void readTsl1401(void)
{
	uint8_t i = 0;

	digitalWrite(SI_PIN, HIGH);
	digitalWrite(CLK_PIN, HIGH);
	delayMicroseconds(1);
	digitalWrite(SI_PIN, LOW);
	digitalWrite(CLK_PIN, LOW);

	for (i = 0; i < 129; i++)
	{
		digitalWrite(SI_PIN, HIGH);
		digitalWrite(CLK_PIN, LOW);
	}
	delay(30);
	digitalWrite(SI_PIN, HIGH);
	digitalWrite(SI_PIN, HIGH);
	digitalWrite(CLK_PIN, LOW);
	delayMicroseconds(1);

	for (i = 0; i < 128; i++)
	{
		_adVal[i] = analogRead(A0_PIN) >> 2;
		digitalWrite(SI_PIN, HIGH);
		digitalWrite(CLK_PIN, LOW);
		delayMicroseconds(2);
	}
	digitalWrite(CLK_PIN, HIGH);
	digitalWrite(CLK_PIN, LOW);

}

uint8_t ccdFindMidVal(void)
{
	uint8_t i, j, left, right, _ccdMidVal;
	float maxVal, minVal;
	maxVal = _adVal[0];
	for (i = 5; i < 123; i++)
	{
		if (maxVal <= _adVal[i])
		{
			maxVal = _adVal[i];
		}
	}
	minVal = _adVal[0];
	for (i = 5; i < 123; i++)
	{
		if (minVal >= _adVal[i])
		{
			minVal = _adVal[i];
		}
	}
	_ccdThreshold = (maxVal + minVal) / 2.0;
	left = 0;
	for (i = 5; i < 118; i++)
	{
		if (_adVal[i] > _ccdThreshold &&
			_adVal[i + 1] > _ccdThreshold &&
			_adVal[i + 2] > _ccdThreshold &&
			_adVal[i + 3] > _ccdThreshold&&
			_adVal[i + 4] > _ccdThreshold&&
			_adVal[i + 5] > _ccdThreshold)
			{
				left = i;
				break;
			}
	}
	right = 0;
	for (j = 128; j > 5; j--)
	{
		if (_adVal[j] > _ccdThreshold &&
				_adVal[j + 1] > _ccdThreshold &&
				_adVal[j + 2] > _ccdThreshold &&
				_adVal[j + 3] > _ccdThreshold&&
				_adVal[j + 4] > _ccdThreshold&&
				_adVal[j + 5] > _ccdThreshold)
			{
			left = j;
			break;
			}
	}
	if (left == 0 || right == 128)
	{
		_ccdMidVal = 255;
	}
	else
	{
		_ccdMidVal = (uint8_t)((right + left) / 2);
	}

// The setup() function runs once each time the micro-controller starts
void setup()
{
	ccdinit();
	Serial.begin(9600);

}

// Add the main program code into the continuous loop() function
void loop()
{
	uint8_t midVal = ccdFindMidVal();
	for (int i = 5; i < 123; i++)
	{
		Serial.println(_adVal[i]);
	}
	delay(100);

}
