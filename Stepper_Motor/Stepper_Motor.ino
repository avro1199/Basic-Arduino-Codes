#include<AFMotor.h>

AF_Stepper avro(20, 2);

void setup() {
  // put your setup code here, to run once:

  avro.setSpeed(3000);

  avro.step(20, FORWARD, MICROSTEP);

  avro.release();
  delay(1000);

   avro.step(20, BACKWARD, MICROSTEP);

   avro.release();

}

void loop() {
  // put your main code here, to run repeatedly:



}
