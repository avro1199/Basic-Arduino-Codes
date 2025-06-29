void setup() {
  // put your setup code here, to run once:

  pinMode(3, INPUT);
  pinMode(13, OUTPUT);

  Serial.begin(115200);

}

void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite(13, digitalRead(3));

  Serial.println(digitalRead(3));

  delay(500);

}
