#include <Servo.h>

Servo myservo1;
Servo myservo2;
Servo myservo3;
Servo myservo4;
Servo myservo5;
Servo myservo6;

int pos = 0;

void setup()
{
    myservo1.attach(2);
    myservo2.attach(3);
    myservo3.attach(4);
    myservo4.attach(5);
    myservo5.attach(6);
    myservo6.attach(7);
}

void loop()

{
    for (pos = 0; pos <= 180; pos += 1)
    {
        myservo1.write(pos);
        myservo2.write(pos);
        /*
        myservo3.write(pos);
        myservo4.write(pos);
        myservo5.write(pos);
        myservo5.write(pos);
        */
        delay(15);
    }
    for (pos = 180; pos >= 0; pos -= 1)
    {
        myservo1.write(pos);
        myservo2.write(pos);
        /*
        myservo3.write(pos);
        myservo4.write(pos);
        myservo5.write(pos);
        myservo6.write(pos);
        */
        delay(15);
    }
}