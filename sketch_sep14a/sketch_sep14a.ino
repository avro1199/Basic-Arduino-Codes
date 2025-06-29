int i;

void setup() {
  // put your setup code here, to run once:

  pinMode(9, OUTPUT);
  Serial.begin(115200);

  

}

void loop() {
  // put your main code here, to run repeatedly:

 for(i = 0; i < 256; i += 5){
    analogWrite(9, i);

    Serial.println(i);

    delay(100);
  }

}
