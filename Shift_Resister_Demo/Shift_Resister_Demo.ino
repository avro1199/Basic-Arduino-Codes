int dataPin = 6;
int clockPin = 7;
int latchPin = 5;

byte first, secnd, third;

byte pattern[12][3] = {{B00000000,B00011000, B00000000},
{B00000000,B00100100, B00000000},
{B00000000,B01000010, B00000000},
{B00010000,B10000001, B00001000},
{B00100001,B00000000, B10000100},
{B01000010,B00000000, B01000010},
{B10000100,B00000000, B00100001},
{B00001000,B00000000, B00010000},
{B00010000,B00000000, B00001000},
{B00100000,B00000000, B00000100},
{B01000000,B00000000, B00000010},
{B10000000,B00000000, B00000001}};

long i;

int del = 20, del_pattern = 20;

void setup() {
  // put your setup code here, to run once:
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(latchPin, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  
  for(long j = 1; j <= 16777216; j *= 2)
  {
    digitalWrite(latchPin, LOW);

    i = j - 1;

    first = i & 255;
    secnd = (i >> 8) & 255;
    third = (i >> 16) & 255;

    shiftOut(dataPin, clockPin, MSBFIRST, third);
    shiftOut(dataPin, clockPin, MSBFIRST, secnd);
    shiftOut(dataPin, clockPin, MSBFIRST, first);

    digitalWrite(latchPin, HIGH);

    delay(del);
  }
   for(long j = 16777216; j > 0; j /= 2)
  {
    digitalWrite(latchPin, LOW);

    i = j - 1;

    first = i & 255;
    secnd = (i >> 8) & 255;
    third = (i >> 16) & 255;

    shiftOut(dataPin, clockPin, MSBFIRST, third);
    shiftOut(dataPin, clockPin, MSBFIRST, secnd);
    shiftOut(dataPin, clockPin, MSBFIRST, first);

    digitalWrite(latchPin, HIGH);

    delay(del);
  }

  x:

  for(int row = 0; row < 12; row++)
  {
    digitalWrite(latchPin, LOW);
    
    for(int col = 0; col < 3; col++)
    {
      shiftOut(dataPin, clockPin, MSBFIRST, pattern[row][col]);
    }

    digitalWrite(latchPin, HIGH);

    delay(del_pattern);
  }
  for(int row = 11; row >= 0; row--)
  {
    digitalWrite(latchPin, LOW);
    
    for(int col = 0; col < 3; col++)
    {
      shiftOut(dataPin, clockPin, MSBFIRST, pattern[row][col]);
    }

    digitalWrite(latchPin, HIGH);

    delay(del_pattern);
  }

  goto x;

}
