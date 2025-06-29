#include<AFMotor.h>

AF_DCMotor mot1(1);
AF_DCMotor mot2(2);
AF_DCMotor mot3(3);
AF_DCMotor mot4(4);


void setup() {
  // put your setup code here, to run once:

  mot1.setSpeed(255);
  mot2.setSpeed(255);
  mot4.setSpeed(255);
  mot4.setSpeed(255);

}

void loop() {
  // put your main code here, to run repeatedly:

  mot1.run(FORWARD);
  mot2.run(FORWARD);
  mot3.run(FORWARD);
  mot4.run(FORWARD);

}
