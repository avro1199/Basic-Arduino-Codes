void setup() {
  // put your setup code here, to run once:

  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);

  Serial.begin(9600);


}

void loop() {
  // put your main code here, to run repeatedly:

  for (int i = 150; i < 255; i += 5) {
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    analogWrite(3, i);

    digitalWrite(9, HIGH);
    digitalWrite(8, LOW);
    analogWrite(10, i);

    Serial.println(i);

    delay(500);
  }

}
