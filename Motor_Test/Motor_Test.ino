#include <AFMotor.h>

AF_DCMotor left(4);
AF_DCMotor right(3);


void setup() {
  // put your setup code here, to run once:

  left.setSpeed(160);
  right.setSpeed(150);

}

void loop() {
  // put your main code here, to run repeatedly:

  left.run(FORWARD);
  right.run(FORWARD);

}
