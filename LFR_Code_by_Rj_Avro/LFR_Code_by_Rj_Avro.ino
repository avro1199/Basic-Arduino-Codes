/* LFR Code Written by Rj Avro */

#include <AFMotor.h>
#include <NewPing.h>

#define NUM_SENSORS 6
#define t_pin 24
#define e_pin 26
#define max_dist 50

AF_DCMotor left_motor(3);
AF_DCMotor right_motor(4);

NewPing rj(t_pin, e_pin, max_dist);

int thresholds[NUM_SENSORS] = {400, 400, 400, 400, 400, 400};
int sValues[NUM_SENSORS], lastSensor;

int leftBaseSpeed = 110;
int rightBaseSpeed = 110;
int maxSpeed = 240;

float Kp = 2;
float Ki = 0.0;
float Kd = 0.75;

int prevError, cumError;

int distance;

int getDistance();
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
  distance = getDistance();

  if(distance > 8)
  {
    lineFollow();
  }
  else
  {
    left_motor.run(RELEASE);
    right_motor.run(RELEASE);

    drive(-110, -110);

    delay(100);

    drive(100, -80);               // going right (avoiding obs)
    delay(400);
    
    drive(100, 100);               // going straight (skipping obs)
    delay(600);
    
    drive(-80, 100);             // going left (back to the track)
    delay(500);
  }

  
}

void initialize()
{
  // pinMode for Motor Driver
  // No need if using Motor Driver Shield
  // initial motor speed = 0

  lastSensor = 0;
  prevError = 0;
  cumError = 0;

  //Serial.begin(9600);    // optional
  // Serial.println("Inatializing .........");    // optional
}

int getDistance() {
  delayMicroseconds(20);
  int cm = rj.ping_cm();
  if (cm == 0) {
    cm = 100;
  }
  return cm;
}


int readSensor()
{
  for (int i = 0; i < NUM_SENSORS; i++)
  {
    // reading sensor values and converting into digital values
    if (analogRead(A8 + i) > thresholds[i])
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

  sumWS = (sValues[0] * 20) + (sValues[1] * 25) + (sValues[2] * 30) + (sValues[3] * 40) + (sValues[4] * 45) + (sValues[5] * 50);

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
      drive(-100, 140);
    }
    else if (lastSensor == 2)
    {
      drive(140, -100);
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
