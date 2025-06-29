#include <AFMotor.h>


AF_DCMotor avro(3);




void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

 for(int i = 255; i < 256; i++)
 {
  Serial.println(i);
  
  avro.setSpeed(i);

  avro.run(FORWARD);

  delay(1000);

 }
 for(int i = 255; i < 256; i++)
 {
  Serial.println(i);
  
  avro.setSpeed(i);

  avro.run(BACKWARD);

  delay(1000);

 }

}
