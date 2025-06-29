float potX, potY;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);

}

float mapfloat(long x, long in_min, long in_max, long out_min, long out_max)
{
  return (float)(x - in_min) * (out_max - out_min) / (float)(in_max - in_min) + out_min;
}

void loop() {
  // put your main code here, to run repeatedly:

  potX = mapfloat(analogRead(A0), 0.0, 1023.0, 0.0, 5.0);
  potY = analogRead(A1);
  Serial.print(potX);
  Serial.print(" | ");
  Serial.print(potY);
  Serial.println();
  delay(200);

}
