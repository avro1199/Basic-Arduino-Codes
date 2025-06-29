long unsigned int t;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  
  pinMode(11, OUTPUT);

  pinMode(6, OUTPUT);
  pinMode(5, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite(6, LOW);

  delay(2);

  digitalWrite(6, HIGH);

  pulseIn(5, t);
  Serial.println(t);

  digitalWrite(6, LOW);

  delay(50);
  

}
