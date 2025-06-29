char ch;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  pinMode(13, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available())
  {
    ch = Serial.read();
    
    Serial.print("Value : ");
    Serial.println(ch);
    if(ch == 'a')
    {
      digitalWrite(13, HIGH);
    }
    if(ch == 'b')
    {
      digitalWrite(13, LOW);
    }

    delay(700);
  }


}
