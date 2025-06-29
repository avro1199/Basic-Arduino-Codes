boolean state = 0;

void setup() {
  // put your setup code here, to run once:


  pinMode(12, INPUT_PULLUP);
  pinMode(11, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  if(digitalRead(12) == LOW)
  {
    digitalWrite(11, state);
    state = !state;

    delay(300);
  }

}
