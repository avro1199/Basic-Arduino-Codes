/* LFR Code Written by Rj Avro */

#include <AFMotor.h>

#define NUM_SENSORS 6

AF_DCMotor left_motor(3);
AF_DCMotor right_motor(4);

int thresholds[NUM_SENSORS] = {650, 650, 650, 650, 650, 650};
int sValues[NUM_SENSORS], lastSensor;

int leftBaseSpeed = 160;
int rightBaseSpeed = 160;
int maxSpeed = 250;

float Kp = 4;
float Ki = 0.0;
float Kd =0.7;

int prevError, cumError;

void initialize();
void lineFollow();
int readSensor();
void drive(int, int);

void setup()
{
  initialize();
}

void loop()
{
  lineFollow();
}

void initialize()
{
  // pinMode for Motor Driver
  // No need if using Motor Driver Shield
  // initial motor speed = 0

  lastSensor = 0;
  prevError = 0;
  cumError = 0;

  // Serial.begin(9600);    // optional
  // Serial.println("Inatializing .........");    // optional
}

int readSensor()
{
  for (int i = 0; i < NUM_SENSORS; i++)
  {
    // reading sensor values and converting into digital values
    if (analogRead(A0 + i) > thresholds[i])
    {
      sValues[i] = 1;
    }
    else
    {
      sValues[i] = 0;
    }

    // Serial.print(sValues[i]); // Serial.print(analogRead(i));
    // Serial.print(' ');
  }

  int erroR, sumS, sumWS, linepos;

  sumS = sValues[0] + sValues[1] + sValues[2] + sValues[3] + sValues[4] + sValues[5];

  if (sumS == 0) // no sensor are on the line & need to check for wall by ultrasonic sensor
  {
    return 420;
  }

  sumWS = (sValues[0] * 10) + (sValues[1] * 20) + (sValues[2] * 30) + (sValues[3] * 40) + (sValues[4] * 50) + (sValues[5] * 60);

  linepos = (sumWS / sumS); // weighted position

  erroR = linepos - 35;

  if (sValues[0] == 1)
  {
    lastSensor = 1;
  }
  else if (sValues[5] == 1)
  {
    lastSensor = 2;
  }

  return erroR;
}

void drive(int leftSpeed, int rightSpeed)
{
  //Serial.print(leftSpeed);
 // Serial.print(' ');
  //Serial.print(rightSpeed);

  left_motor.setSpeed(abs(leftSpeed));
  right_motor.setSpeed(abs(rightSpeed));

  if (leftSpeed > 0)
  {
    left_motor.run(FORWARD);
  }
  else if (leftSpeed < 0)
  {
    left_motor.run(BACKWARD);
  }

  if (rightSpeed > 0)
  {
    right_motor.run(FORWARD);
  }
  else if (rightSpeed < 0)
  {
    right_motor.run(BACKWARD);
  }
}

void lineFollow()
{
  int erroR, delSpeed;
  float P, I, D;

  erroR = readSensor();

  if (erroR == 420)
  {
    // no sensor is on the line
    // so we have to check for other options i.e Wall, Line Gaps etc.

    //returnung back to the line
    if (lastSensor == 1)
    {
      drive(-180, 180);
    }
    else if(lastSensor == 2)
    {
      drive(180, -180);
    }
  }
  else 
  {
    // calculating PID Values for wheel Drive
    P = Kp * erroR;
    I = Ki * (erroR + cumError);
    D = Kd * (erroR - prevError);

    // calculating the difference of speed between two wheels 
    delSpeed = P + I + D;

    // driving the wheel
    drive(constrain((leftBaseSpeed + delSpeed), 0, maxSpeed), constrain((rightBaseSpeed - delSpeed), 0, maxSpeed));

    prevError = erroR;
    cumError += erroR;

  }
}
