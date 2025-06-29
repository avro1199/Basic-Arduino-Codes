void print_digital()
{
  while (1)
  {

    Serial.print((analogRead(A0) < 900) ? "1  " : "0  ");
    Serial.print("   ");
    Serial.print((analogRead(A1) < 900) ? "1" : "0");
    Serial.print("   ");
    Serial.print((analogRead(A2) < 900) ? "1  " : "0  ");
    Serial.print("   ");
    Serial.print((analogRead(A3) < 900) ? "1  " : "0  ");
    Serial.print("   ");
    Serial.print((analogRead(A6) < 900) ? "1  " : "0  ");
    Serial.print("   ");
    Serial.print((analogRead(A7) < 900) ? "1  " : "0  ");
    Serial.println();
    delay(300);
  }
}

void print_analog()
{
  while(1)
  {
    
  Serial.print(analogRead(A0));
  Serial.print("   ");
  Serial.print(analogRead(A1));
  Serial.print("   ");
  Serial.print(analogRead(A2));
  Serial.print("   ");
  Serial.print(analogRead(A3));
  Serial.print("   ");
  Serial.print(analogRead(A6));
  Serial.print("   ");
  Serial.print(analogRead(A7));
  Serial.println();
  delay(300);
  }
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

  print_analog();
  print_digital();



}
