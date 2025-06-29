#include <Servo.h>
Servo Imrul;
void setup() {
  // put your setup code here, to run once:

  Imrul.attach(6);

}

void loop() {
  // put your main code here, to run repeatedly:

  Imrul.write(0);

  delay(2000);

  Imrul.write(90);

  delay(2000);

  Imrul.write(30);

  delay(2000);

}
