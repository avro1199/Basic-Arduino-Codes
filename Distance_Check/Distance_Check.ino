#include <NewPing.h>

#define t_pin 6
#define e_pin 7
#define max_dist 50

NewPing rj(t_pin, e_pin, max_dist);


void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

  Serial.println(getDistance());

  delay(300);

}

int getDistance() {
  delayMicroseconds(20);
  int cm = rj.ping_cm();
  if (cm == 0) {
    cm = 100;
  }
  return cm;
}
