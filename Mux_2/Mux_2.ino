#define s0 2
#define s1 3
#define s2 4
#define s3 5


void setup()
{
  Serial.begin(115200);

  pinMode(s0, OUTPUT);
  pinMode(s1, OUTPUT);
  pinMode(s2, OUTPUT);
  pinMode(s3, OUTPUT);
}

void loop()
{
  for(int i = 0; i < 16; i++){
    digitalWrite(s0, (i & 1));
    digitalWrite(s1, (i & 2));
    digitalWrite(s2, (i & 4));
    digitalWrite(s3, (i & 8));

    Serial.print("Channel ");
    Serial.print(i);
    Serial.print(": ");
    Serial.println(analogRead(A0));
    delay(20);
  }
}