int getDistance(int S_Pin)
{
  long t;
  int distance;

  pinMode(S_Pin, OUTPUT);

  delayMicroseconds(2);
  digitalWrite(S_Pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(S_Pin, LOW);

  pinMode(S_Pin, INPUT);

  t = pulseIn(S_Pin, HIGH);

  if (t == 0)
  {
    distance = 100;
  }
  else
  {
    distance = (int)(t * 0.033 / 2);
  }

  return distance;
}