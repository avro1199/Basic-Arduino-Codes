#include <DHT.h>

DHT avro(8, DHT22);

float tmp, hum;

void setup() {

  avro.begin();
  Serial.begin(9600);

}

void loop() {

  tmp = avro.readTemperature();
  hum = avro.readHumidity();

  Serial.print("Temperature = ");
  Serial.print(tmp);
  Serial.print(" °C\n Humidity = ");
  Serial.print(hum);
  Serial.print("%\n\n");

  delay(2000);

}
