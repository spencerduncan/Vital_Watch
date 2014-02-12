#define A    2
#define SCLK 4
#define LCLK 3
#define RST  5

#define MODE0 ~0x00
#define MODE1 ~0x01
#define MODE2 ~0x02
#define MODE3 ~0x04
#define ONE   ~0x30
#define TWO   ~0x6D
#define THREE ~0x79
#define FOUR  ~0x33
#define FIVE  ~0x5A
#define SIX   ~0x5F
#define SEVEN ~0x70
#define	EIGHT ~0x7F
#define	NINE  ~0x73
#define TEN   ~0x7E

/*
void setup() {
  pinMode(A,    OUTPUT);
  pinMode(SCLK, OUTPUT);
  pinMode(LCLK, OUTPUT);
  pinMode(RST,  OUTPUT);

	digitalWrite(RST, LOW);
	digitalWrite(RST, HIGH);
}
*/

void writeArray(unsigned short a)
{
	for (int i = 0; i < 16; ++i)
	{
		digitalWrite(A, (a>>(15-i))&0x01);
		digitalWrite(SCLK, LOW);
		digitalWrite(SCLK, HIGH);
	}
	digitalWrite(LCLK, LOW);
	digitalWrite(LCLK, HIGH);
}

void pushBit(unsigned char i)
{
	digitalWrite(A, i);
	digitalWrite(SCLK, LOW);
	digitalWrite(SCLK, HIGH);
}

void updateDisplay()
{
	digitalWrite(LCLK, LOW);
	digitalWrite(LCLK, HIGH);
}

void writeDisplay(unsigned char n1, unsigned char n2, unsigned char n3, unsigned char mode)
{
	char i = 0;
	for ( ; i < 3; ++i)
	{
		pushBit((mode>>(2-i))&0x01);
	}
	for ( i=6; i >= 0; --i)
	{
		pushBit((n3>>(i))&0x01);
	}
	for ( i=6; i >= 0; --i)
	{
		pushBit((n2>>(i))&0x01);
	}
	for ( i=6; i >= 0; --i)
	{
		pushBit((n1>>(i))&0x01);
	}
	updateDisplay();
}

