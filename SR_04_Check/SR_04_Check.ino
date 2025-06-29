void setup()
{
Serial.begin(9600); // Starting Serial Terminal
pinMode(3, OUTPUT);
pinMode(7, INPUT);
}

void loop()
{
long duration, inches, cm;

digitalWrite(3, LOW);
delayMicroseconds(2);
digitalWrite(3, HIGH);
delayMicroseconds(10);
digitalWrite(3, LOW);


duration = pulseIn(7, HIGH);
inches = microsecondsToInches(duration);
cm = microsecondsToCentimeters(duration);

Serial.print(inches);
Serial.print("in, ");
Serial.print(cm);
Serial.print("cm");
Serial.print("\tDuration =  ");
Serial.print(duration);
Serial.println();

delay(100);
}

long microsecondsToInches(long microseconds)
{
return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds)
{
return microseconds / 29 / 2;
}
