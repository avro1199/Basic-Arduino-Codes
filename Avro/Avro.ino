int G =7;
int W =8;
int X = 3;
boolean stateG = 1,stateW = 1, stateX = 0;

void setup()
{
  pinMode(G,OUTPUT);
  pinMode(W,OUTPUT);
  pinMode(X,OUTPUT);
  
  
}
void loop()
{
    digitalWrite(G,stateG);
    delay(100);
    stateG = !stateG;

    digitalWrite(W,stateW);
    delay(50);
    stateW = !stateW;

    digitalWrite(X,stateX);
    delay(10);
    stateX = !stateX;
}
