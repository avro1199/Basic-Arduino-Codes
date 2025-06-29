#define a 2
#define b 3
#define c 4
#define d 5
#define e 6
#define f 7
#define g 8

#define d1 12
#define d2 14
#define d3 15

#define d_delay 5
#define it_delay 2

void print_digit(int num)
{
    if (num == 0)
    {
        digitalWrite(a, LOW);
        digitalWrite(b, LOW);
        digitalWrite(c, LOW);
        digitalWrite(d, LOW);
        digitalWrite(e, LOW);
        digitalWrite(f, LOW);
        digitalWrite(g, HIGH);
    }
    else if (num == 1)
    {
        digitalWrite(a, HIGH);
        digitalWrite(b, LOW);
        digitalWrite(c, LOW);
        digitalWrite(d, HIGH);
        digitalWrite(e, HIGH);
        digitalWrite(f, HIGH);
        digitalWrite(g, HIGH);
    }
    else if (num == 2)
    {
        digitalWrite(a, LOW);
        digitalWrite(b, LOW);
        digitalWrite(c, HIGH);
        digitalWrite(d, LOW);
        digitalWrite(e, LOW);
        digitalWrite(f, HIGH);
        digitalWrite(g, LOW);
    }
    else if (num == 3)
    {
        digitalWrite(a, LOW);
        digitalWrite(b, LOW);
        digitalWrite(c, LOW);
        digitalWrite(d, LOW);
        digitalWrite(e, HIGH);
        digitalWrite(f, HIGH);
        digitalWrite(g, LOW);
    }
    else if (num == 4)
    {
        digitalWrite(a, HIGH);
        digitalWrite(b, LOW);
        digitalWrite(c, LOW);
        digitalWrite(d, HIGH);
        digitalWrite(e, HIGH);
        digitalWrite(f, LOW);
        digitalWrite(g, LOW);
    }
    else if (num == 5)
    {
        digitalWrite(a, LOW);
        digitalWrite(b, HIGH);
        digitalWrite(c, LOW);
        digitalWrite(d, LOW);
        digitalWrite(e, HIGH);
        digitalWrite(f, LOW);
        digitalWrite(g, LOW);
    }
    else if (num == 6)
    {
        digitalWrite(a, LOW);
        digitalWrite(b, HIGH);
        digitalWrite(c, LOW);
        digitalWrite(d, LOW);
        digitalWrite(e, LOW);
        digitalWrite(f, LOW);
        digitalWrite(g, LOW);
    }
    else if (num == 7)
    {
        digitalWrite(a, LOW);
        digitalWrite(b, LOW);
        digitalWrite(c, LOW);
        digitalWrite(d, HIGH);
        digitalWrite(e, HIGH);
        digitalWrite(f, LOW);
        digitalWrite(g, HIGH);
    }
    else if (num == 8)
    {
        digitalWrite(a, LOW);
        digitalWrite(b, LOW);
        digitalWrite(c, LOW);
        digitalWrite(d, LOW);
        digitalWrite(e, LOW);
        digitalWrite(f, LOW);
        digitalWrite(g, LOW);
    }
    else if (num == 9)
    {
        digitalWrite(a, LOW);
        digitalWrite(b, LOW);
        digitalWrite(c, LOW);
        digitalWrite(d, LOW);
        digitalWrite(e, HIGH);
        digitalWrite(f, LOW);
        digitalWrite(g, LOW);
    }
}

void setup()
{
    // put your setup code here, to run once:
    for (int i = 2; i <= 8; i++)
    {
        pinMode(i, OUTPUT);
    }
}

void loop()
{
    // put your main code here, to run repeatedly:
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            for (int k = 0; k < 10; k++)
            {
                for (int p = 0; p < it_delay; p++)
                {
                    digitalWrite(d1, HIGH);
                    print_digit(i);
                    delay(d_delay);
                    digitalWrite(d1, LOW);

                    digitalWrite(d2, HIGH);
                    print_digit(j);
                    delay(d_delay);
                    digitalWrite(d2, LOW);

                    digitalWrite(d3, HIGH);
                    print_digit(k);
                    delay(d_delay);
                    digitalWrite(d3, LOW);
                }
            }
        }
    }
}
