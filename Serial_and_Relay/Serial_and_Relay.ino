boolean state1 = 1, state2 = 1;
char in;
// Rj Avro
void setup() {
  // put your setup code here, to run once:

  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()){
    in = Serial.read();
    
    if(in == '1'){
      digitalWrite(A0, state1);
      Serial.print(" Relay 1 stsus changed to : ");
      state1 = !state1;
      Serial.println(state1);
    }
      if(in == '2'){
      digitalWrite(A1, state2);
      Serial.print(" Relay 2 stsus changed to : ");
      state2 = !state2;
      Serial.println(state2);
    }
  }

  delay(20);

}
