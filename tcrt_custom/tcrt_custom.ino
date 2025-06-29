void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

   for (int i = 0; i < 6 + 2 ; i++)
  {
    if(i == 4 || i == 5)
    {
      continue;
    }
    // reading sensor values and converting into digital values
    if (analogRead(A0 + i) < 800)
    {
      Serial.print("1  ");
    }
    else
    {
      Serial.print("0  ");
    }

  }

    Serial.println();

    delay(500);

}
