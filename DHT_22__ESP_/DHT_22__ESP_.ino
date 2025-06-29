#include <DHT.h>

DHT avro(15, DHT22);

void setup() {
  avro.begin();
  Serial.begin(115200);
  pinMode(2, OUTPUT);

}

void loop() {

  digitalWrite(2, HIGH);
  Serial.print("Temprature = ");
  Serial.print( avro.readTemperature());
  Serial.print(" C\n  Humidity = ");
  Serial.print(avro.readHumidity());
  Serial.print("%\n\n");
  digitalWrite(2, LOW);

  delay(2000);
}
