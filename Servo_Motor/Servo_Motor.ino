#include <Servo.h>

int i = 0, j = 1;

Servo avro;

void setup() {

  Serial.begin(115200);

  avro.attach(13);
}

void loop() {

  if (touchRead(T0) <= 40) {
    i += j;
    delay(300);
    if(i == 180){
      j = -5;
    }
    else if(i == 0){
      j = 5;
    }
  }

  avro.write(i);
  Serial.println(i);

}
