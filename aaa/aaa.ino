/* LFR Code Written by Rj Avro */


#define NUM_SENSORS 6

#define L_Motor_En 3
#define L_Motor_F 4
#define L_Motor_B 5
#define R_Motor_En 10
#define R_Motor_F 9
#define R_Motor_B 8


int thresholds[NUM_SENSORS] = {1020, 1020, 1020, 1020, 1020, 1020};
int sValues[NUM_SENSORS], lastSensor;
int sumS;

int leftBaseSpeed = 120;
int rightBaseSpeed = 120;
int maxSpeed = 240;

float Kp = 2.2;
float Ki = 0.0;
float Kd = 1.0;

int prevError, cumError;

void initialize();
void lineFollow();
int readSensor();
void drive(int, int);

void setup()
{

  //Serial.begin(9600);
  initialize();
}

void loop()
{
  lineFollow();
}

void initialize()
{
  // pinMode for Motor Driver

  pinMode(L_Motor_F, OUTPUT);
  pinMode(L_Motor_B, OUTPUT);
  pinMode(R_Motor_F, OUTPUT);
  pinMode(R_Motor_B, OUTPUT);

  // No need if using Motor Driver Shield

  // initial motor speed = 0
  analogWrite(L_Motor_En, 0);
  analogWrite(R_Motor_En, 0);

  lastSensor = 0;
  prevError = 0;
  cumError = 0;
}

int readSensor()
{

  sValues[0] = (analogRead(A7) < thresholds[0]) ? 1 : 0;
  sValues[1] = (analogRead(A6) < thresholds[1]) ? 1 : 0;
  sValues[2] = (analogRead(A3) < thresholds[2]) ? 1 : 0;
  sValues[3] = (analogRead(A2) < thresholds[3]) ? 1 : 0;
  sValues[4] = (analogRead(A1) < thresholds[4]) ? 1 : 0;
  sValues[5] = (analogRead(A0) < thresholds[5]) ? 1 : 0;

  int erroR, sumWS, linepos;

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

  analogWrite(L_Motor_En, leftSpeed);
  analogWrite(R_Motor_En, rightSpeed);

  if (leftSpeed > 0)
  {
    digitalWrite(L_Motor_F, HIGH);
    digitalWrite(L_Motor_B, LOW);
  }
  else if (leftSpeed < 0)
  {
    digitalWrite(L_Motor_F, LOW);
    digitalWrite(L_Motor_B, HIGH);
  }

  if (rightSpeed > 0)
  {
    digitalWrite(R_Motor_F, HIGH);
    digitalWrite(R_Motor_B, LOW);
  }
  else if (rightSpeed < 0)
  {
    digitalWrite(R_Motor_F, LOW);
    digitalWrite(R_Motor_B, HIGH);
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
      lastSensor = 0;
      while(sumS <= 0)
      {
        drive(-10, 60);

        readSensor();
      }
    }
    else if (lastSensor == 2)
    {
      lastSensor = 0;
      while(sumS <= 0)
      {
        drive(60, -10);

        readSensor();
      }
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

    Serial.println(delSpeed);

    // driving the wheel
    drive(constrain((leftBaseSpeed + delSpeed), 0, maxSpeed), constrain((rightBaseSpeed - delSpeed), 0, maxSpeed));

    prevError = erroR;
    cumError += erroR;

  }
}
