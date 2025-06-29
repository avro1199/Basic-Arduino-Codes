void setup() {
  // put your setup code here, to run once:

  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  for(int i = 0; i <= 255; i += 5)
  {
    digitalWrite(9, HIGH);
    digitalWrite(8, LOW);

    analogWrite(10, i);

    delay(300);
  }

  for(int i = 0; i <= 255; i += 5)
  {
    digitalWrite(9, LOW);
    digitalWrite(8, HIGH);

    analogWrite(10, i);

    delay(300);
  }

 

}
