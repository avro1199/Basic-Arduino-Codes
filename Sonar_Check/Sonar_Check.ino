long t;

int s_pin = 2;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);


}

void loop() {
  // put your main code here, to run repeatedly:

  pinMode(s_pin, OUTPUT);

  digitalWrite(s_pin, LOW);
  delayMicroseconds(2);

  digitalWrite(s_pin, HIGH);
  delayMicroseconds(10);

  digitalWrite(s_pin, LOW);

  pinMode(s_pin, INPUT);

  t = pulseIn(s_pin, HIGH);

  Serial.println(t * 0.034 / 2);

  delay(300);

}
