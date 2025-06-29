long t;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);


}

void loop() {
  // put your main code here, to run repeatedly:

  pinMode(6, OUTPUT);

  digitalWrite(6, HIGH);

  delayMicroseconds(10);

  digitalWrite(6, LOW);

  //delayMicroseconds(2);

  pinMode(6, INPUT);

  t = pulseIn(6, HIGH);

  Serial.println(t);

  delay(500);

  

}
