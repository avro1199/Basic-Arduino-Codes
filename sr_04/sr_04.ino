int trig = 3;
int echo = 7;

long t;

void setup() {
  // put your setup code here, to run once:

  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);

  Serial.begin(115200);

}

void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite(trig, LOW);
  delayMicroseconds(2);

  digitalWrite(trig, HIGH);
  delayMicroseconds(20);

  digitalWrite(trig, LOW);

  t = pulseIn(echo, HIGH);

  Serial.print("Meter : ");
  Serial.println(t*0.000332/2);

  delay(500);

  
}
