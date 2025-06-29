int in_1= 4;
int in_2 = 5;
int in_3 = 9;
int in_4 = 8;

void setup() {
  // put your setup code here, to run once:

  pinMode(in_1, OUTPUT);
  pinMode(in_2, OUTPUT);
  pinMode(in_3, OUTPUT);
  pinMode(in_4, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite(in_1, HIGH);
  digitalWrite(in_2, LOW);
  analogWrite(3, 200);

  digitalWrite(in_3, HIGH);
  digitalWrite(in_4, LOW);
  analogWrite(10, 200);

  delay(5000);

  digitalWrite(in_1, LOW);
  digitalWrite(in_2, LOW);

  digitalWrite(in_3, LOW);
  digitalWrite(in_4, LOW);

   delay(2000);

   digitalWrite(in_1, LOW);
  digitalWrite(in_2, HIGH);

   digitalWrite(in_3, LOW);
  digitalWrite(in_4, HIGH);

  delay(2000);
}
