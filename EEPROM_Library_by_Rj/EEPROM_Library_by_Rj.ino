#include <EEPROM.h>

void intWrite(int addr, int value)
{
  EEPROM.write((2 * addr), (value >> 8) & 0xFF);
  EEPROM.write((2 * addr) + 1, value & 0xFF);
}

int intRead(int addr)
{
  return ((EEPROM.read(2 * addr) << 8) + EEPROM.read((2 * addr) + 1));
}

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);

  intWrite(10, 590);

}

void loop() {
  // put your main code here, to run repeatedly:

  Serial.println(intRead(10));

  delay(500);

}
