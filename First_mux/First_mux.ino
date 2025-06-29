#include <CD74HC4067.h>

CD74HC4067 rj(2, 3, 4, 5);  // create a new CD74HC4067 object with its four control pins

const int in = A0; // select a pin to share with the 16 channels of the CD74HC4067

void setup()
{
  Serial.begin(115200);
}

void loop()
{
  for(int i = 0; i < 16; i++){
    rj.channel(i);
    Serial.print("Channel ");
    Serial.print(i);
    Serial.print(": ");
    Serial.println(analogRead(in));
    delay(20);
  }
}