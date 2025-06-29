int sValues[6];
int thresholds[6] = {400, 400, 400, 400, 400, 400};

void readSensor()
{

  sValues[0] = (analogRead(A0) < thresholds[0]) ? 1 : 0;
  sValues[1] = (analogRead(A1) < thresholds[1]) ? 1 : 0;
  sValues[2] = (analogRead(A2) < thresholds[2]) ? 1 : 0;
  sValues[3] = (analogRead(A3) < thresholds[3]) ? 1 : 0;
  sValues[4] = (analogRead(A6) < thresholds[4]) ? 1 : 0;
  sValues[5] = (analogRead(A7) < thresholds[5]) ? 1 : 0;
}

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);

}
void loop() {
  // put your main code here, to run repeatedly:

  readSensor();

  for(int i = 0; i < 6; i++)
  {
    Serial.print(sValues[i]);
    Serial.print("  ");
  }
  Serial.println();

  delay(500);

}
