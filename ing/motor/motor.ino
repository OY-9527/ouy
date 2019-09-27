int IN01=A1,IN02=A2,IN03=A3,IN04=A4;                //控制后面的两个电机
int IN11=A5,IN12=A6,IN13=A7,IN14=A8;                //控制前面的两个电机
double D1=A0,D2=A9,D3=A10,D4=A11;
double D5=A12,D6=A13,D7=A14,D8=A15;
int IR=0;
double a,b,c,d,e,f,g,h;

void setup()
{
    Serial.begin(9600);                             //初始化波特率
    //电机控制输出
    pinMode(IN01,OUTPUT);
    pinMode(IN02,OUTPUT);
    pinMode(IN03,OUTPUT);
    pinMode(IN04,OUTPUT);
    pinMode(IN11,OUTPUT);
    pinMode(IN12,OUTPUT);
    pinMode(IN13,OUTPUT);
    pinMode(IN14,OUTPUT);
    //红外传感器输入
    digitalWrite(IR,HIGH);
    pinMode(D1,INPUT);
    pinMode(D2,INPUT);
    pinMode(D3,INPUT);
    pinMode(D4,INPUT);
    pinMode(D5,INPUT);
    pinMode(D6,INPUT);
    pinMode(D7,INPUT);
    pinMode(D8,INPUT);
}

void tracking()
{
    a=analogRead(D1);
    b=analogRead(D2);
    c=analogRead(D3);
    d=analogRead(D4);
    e=analogRead(D5);
    f=analogRead(D6);
    g=analogRead(D7);
    h=analogRead(D8);
    Serial.print("D1=");
    Serial.print(a);
    Serial.print("   ");
    Serial.print("D2=");
    Serial.print(b);
    Serial.print("   ");
    Serial.print("D3=");
    Serial.print(c);
    Serial.print("   ");
    Serial.print("D4=");
    Serial.print(d);
    Serial.print("   ");
    Serial.print("D5=");
    Serial.print(e);
    Serial.print("   ");
    Serial.print("D6=");
    Serial.print(f);
    Serial.print("   ");
    Serial.print("D7=");
    Serial.print(g);
    Serial.print("   ");
    Serial.print("D8=");
    Serial.println(h);
}

void forward()
{
    //IN01，IN02控制后左电机
    analogWrite(IN01,130);
    analogWrite(IN02,0);
    //IN03,IN04控制后右电机
    analogWrite(IN03,0);
    analogWrite(IN04,130);
    //IN11,IN12控制前右电机
    analogWrite(IN11,0);
    analogWrite(IN12,130);
    //IN13，IN14控制前左电机
    analogWrite(IN13,130);
    analogWrite(IN14,0);
}

void back()
{
    //IN01，IN02控制后左电机
    analogWrite(IN01,0);
    analogWrite(IN02,130);
    //IN03,IN04控制后右电机
    analogWrite(IN03,130);
    analogWrite(IN04,0);
    //IN11,IN12控制前右电机
    analogWrite(IN11,130);
    analogWrite(IN12,0);
    //IN13，IN14控制前左电机
    analogWrite(IN13,0);
    analogWrite(IN14,130);
}

void left()
{
    //IN01，IN02控制后左电机
    analogWrite(IN01,0);
    analogWrite(IN02,130);
    //IN03,IN04控制后右电机
    analogWrite(IN03,0);
    analogWrite(IN04,130);
    //IN11,IN12控制前右电机
    analogWrite(IN11,0);
    analogWrite(IN12,130);
    //IN13，IN14控制前左电机
    analogWrite(IN13,0);
    analogWrite(IN14,130);
}

void right()
{
    //IN01，IN02控制后左电机
    analogWrite(IN01,130);
    analogWrite(IN02,0);
    //IN03,IN04控制后右电机
    analogWrite(IN03,130);
    analogWrite(IN04,0);
    //IN11,IN12控制前右电机
    analogWrite(IN11,130);
    analogWrite(IN12,0);
    //IN13，IN14控制前左电机
    analogWrite(IN13,130);
    analogWrite(IN14,0);
}

void stop()
{
    //IN01，IN02控制后左电机
    analogWrite(IN01,0);
    analogWrite(IN02,0);
    //IN03,IN04控制后右电机
    analogWrite(IN03,0);
    analogWrite(IN04,0);
    //IN11,IN12控制前右电机
    analogWrite(IN11,0);
    analogWrite(IN12,0);
    //IN13，IN14控制前左电机
    analogWrite(IN13,0);
    analogWrite(IN14,0);
}

void loop()
{
    for (size_t i = 0; i < 30; i++)
    {
        forward();
    }
    for (size_t i = 0; i < 5; i++)
    {
        stop();
    }
    delay(1500);
    for (size_t i = 0; i < 30; i++)
    {
        back();
    }
    for (size_t i = 0; i < 5; i++)
    {
        stop();
    }
    delay(1500);
    for (size_t i = 0; i < 30; i++)
    {
        left();
    }
    for (size_t i = 0; i < 5; i++)
    {
        stop();
    }
    delay(1500);
    for (size_t i = 0; i < 30; i++)
    {
        right();
    }
    for (size_t i = 0; i < 5; i++)
    {
        stop();
    }    
    delay(1500);
}