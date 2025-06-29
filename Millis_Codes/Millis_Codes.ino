int ledW = 11, ledG = 10, valueG, valueW;
unsigned long  prvtime = 0, crntime, prvtimeW = 0, prvtimeG = 0, crntimeW, crntimeG;
boolean stateW = 0, stateG = 1;
void setup() {

  Serial.begin(9600);

  pinMode(ledW, OUTPUT);
  pinMode(ledG, OUTPUT);

}

void loop() {


  
  crntimeG = millis();
  if (crntimeG - prvtimeG >= (700))
  {
    prvtimeG = crntimeG;
    if (stateG == 1)
    {
      valueG = 40;
    }
    else
    {
      valueG = 3;
    }
    analogWrite(ledG, valueG);
    stateG = !stateG;

  }

  crntimeW = millis();
  if (crntimeW - prvtimeW >= 300)
  {
    prvtimeW = crntimeW;
    if (stateW == 1)
    {
      valueW = 200;
    }
    else
    {
      valueW = 5;
    }
    analogWrite(ledW, valueW);
    stateW = !stateW;

  }



}
