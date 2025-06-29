void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

  for(int i = 5; i >=0; i--)
  {
    if(analogRead(A0+i) >100)
    {
      Serial.print("1  ");
    }
    else
    {
      Serial.print("0  ");
    }

  }
  Serial.println();

  delay(100);
}
