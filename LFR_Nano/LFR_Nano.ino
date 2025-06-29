/* LFR Code Written by Rj Avro */

#define L_Motor_En 3
#define L_Motor_F 4
#define L_Motor_B 5
#define R_Motor_En 10
#define R_Motor_F 9
#define R_Motor_B 8

#define NUM_SENSORS 6


int thresholds[NUM_SENSORS + 2] = {780, 780, 780, 780, 780, 780, 780, 780};
int sValues[NUM_SENSORS + 2] = {0}, lastSensor;

int leftBaseSpeed = 180;
int rightBaseSpeed = 180;
int maxSpeed = 240;

float Kp = .5;
float Ki = 0.0;
float Kd =0.1;

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

  pinMode(L_Motor_F, OUTPUT);
  pinMode(L_Motor_B, OUTPUT);
  pinMode(R_Motor_F, OUTPUT);
  pinMode(R_Motor_B, OUTPUT);
  
  // No need if using Motor Driver Shield
  // initial motor speed = 0

  lastSensor = 0;
  prevError = 0;
  cumError = 0;

  // Serial.begin(9780);    // optional
  // Serial.println("Inatializing .........");    // optional
}

int readSensor()
{
  for (int i = 0; i < NUM_SENSORS + 2 ; i++)
  {
    if(i == 4 || i == 5)
    {
      continue;
    }
    // reading sensor values and converting into digital values
    if (analogRead(A0 + i) < thresholds[i])
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

  sumS = sValues[0] + sValues[1] + sValues[2] + sValues[3] + sValues[6] + sValues[7];

  if (sumS == 0) // no sensor are on the line & need to check for wall by ultrasonic sensor
  {
    return 420;
  }

  sumWS = (sValues[0] * 10) + (sValues[1] * 20) + (sValues[2] * 30) + (sValues[3] * 40) + (sValues[6] * 50) + (sValues[7] * 60);

  linepos = (sumWS / sumS); // weighted position

  erroR = linepos - 35;

  if (sValues[0] == 1)
  {
    lastSensor = 1;
  }
  else if (sValues[7] == 1)
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

  analogWrite(L_Motor_En, abs(leftSpeed));
  analogWrite(R_Motor_En, abs(rightSpeed));

  if (leftSpeed > 0)
  {
    // forward
    digitalWrite(L_Motor_F, HIGH);
    digitalWrite(L_Motor_B, LOW);
  }
  else if (leftSpeed < 0)
  {
    //backward
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
      drive(-50, 80);
    }
    else if(lastSensor == 2)
    {
      drive(80, -50);
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
