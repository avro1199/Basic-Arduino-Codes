int greenled = 10;
int redled = 11;
int i;

void setup() {
  // put your setup code here, to run once:

  pinMode(greenled, OUTPUT);
  pinMode(redled, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  for(i = 0; i <= 255; i++){

    analogWrite(redled, i);
    analogWrite(greenled, 255-i);

    Serial.println(i);

    delay(10);
    
    }

    for(i = 255; i >= 0; i--){

    analogWrite(redled, i);
    analogWrite(greenled, 255-i);

    Serial.println(i);

    delay(10);
    
    }
  
}
