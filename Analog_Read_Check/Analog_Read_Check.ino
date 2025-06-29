long t;
void setup() {
  // put your setup code here, to run once:
  pinMode(3,INPUT);
  pinMode(5,OUTPUT);
 Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
 digitalWrite(5,LOW);
 delayMicroseconds(2);
 digitalWrite(5,HIGH);
 delayMicroseconds(10);
 digitalWrite(5, LOW);
 t=pulseIn(3,HIGH);
 Serial.println(t);

}
