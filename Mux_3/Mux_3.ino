void setup()
{
  Serial.begin(115200);
  DDRD = DDRD | 0B00111100;
}

void loop()
{
  for(byte i = 0; i < 16; i++){
    PORTD = (PORTD & 0B11000011) | ((i & 15) << 2); // rj hack for multiplexing (_._)

    Serial.print("Channel ");
    Serial.print(i);
    Serial.print(": ");
    Serial.println(analogRead(A0));
    delay(10);
  }
}