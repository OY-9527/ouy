#define echo_pin 10
#define trig_pin 11
float t, distance;
int IN01 = 2, IN02 = 3, IN03 = 4, IN04 = 5;           //控制后面的两个电机
int IN11 = 6, IN12 = 7, IN13 = 8, IN14 = 9;           //控制前面的两个电机
int D01 = 22, D02 = 24, D03 = 26, D04 = 28, D05 = 30; //车身前部红外循线传感器
int D11 = 23, D12 = 25, D13 = 27, D14 = 29, D15 = 31; //车身后部红外循线传感器
bool a1, a2, a3, a4, a5;                              //前红外变量
bool b1, b2, b3, b4, b5;                              //后红外寄存变量

void setup()
{
    Serial.begin(9600); //初始化波特率
    //电机控制输出
    pinMode(IN01, OUTPUT);
    pinMode(IN02, OUTPUT);
    pinMode(IN03, OUTPUT);
    pinMode(IN04, OUTPUT);
    pinMode(IN11, OUTPUT);
    pinMode(IN12, OUTPUT);
    pinMode(IN13, OUTPUT);
    pinMode(IN14, OUTPUT);
    //前红外传感器输入
    pinMode(D01, INPUT);
    pinMode(D02, INPUT);
    pinMode(D03, INPUT);
    pinMode(D04, INPUT);
    pinMode(D05, INPUT);
    //后红外传感器输入
    pinMode(D11, INPUT);
    pinMode(D12, INPUT);
    pinMode(D13, INPUT);
    pinMode(D14, INPUT);
    pinMode(D15, INPUT);
    //超声波传感器输入
    pinMode(trig_pin, OUTPUT);
    pinMode(echo_pin, INPUT);
}

void infrared_tracking()
{
    //前红外输出
    a1 = digitalRead(D01);
    a2 = digitalRead(D02);
    a3 = digitalRead(D03);
    a4 = digitalRead(D04);
    a5 = digitalRead(D05);
    Serial.print("D01=");
    Serial.print(a1);
    Serial.print("   ");
    Serial.print("D02=");
    Serial.print(a2);
    Serial.print("   ");
    Serial.print("D03=");
    Serial.print(a3);
    Serial.print("   ");
    Serial.print("D04=");
    Serial.print(a4);
    Serial.print("   ");
    Serial.print("D05=");
    Serial.println(a5);
    //后红外输出
    b1 = digitalRead(D11);
    b2 = digitalRead(D12);
    b3 = digitalRead(D13);
    b4 = digitalRead(D14);
    b5 = digitalRead(D15);
    Serial.print("D11=");
    Serial.print(b1);
    Serial.print("   ");
    Serial.print("D12=");
    Serial.print(b2);
    Serial.print("   ");
    Serial.print("D13=");
    Serial.print(b3);
    Serial.print("   ");
    Serial.print("D14=");
    Serial.print(b4);
    Serial.print("   ");
    Serial.print("D15=");
    Serial.println(b5);
}

void speed_up()
{
    for (size_t i = 0; i < 255; i++)
    {
        //IN01，IN02控制后左电机
        analogWrite(IN01, i);
        analogWrite(IN02, 0);
        //IN03,IN04控制后右电机
        analogWrite(IN03, 0);
        analogWrite(IN04, i);
        //IN11,IN12控制前左电机
        analogWrite(IN11, i);
        analogWrite(IN12, 0);
        //IN13，IN14控制前右电机
        analogWrite(IN13, 0);
        analogWrite(IN14, i);
        delay(500);
    }
}

float chaoshengbo()
{
    digitalWrite(trig_pin, LOW);
    digitalWrite(trig_pin, HIGH);
    delayMicroseconds(20);
    digitalWrite(trig_pin, LOW);
    t = pulseIn(echo_pin, HIGH);
    distance = t * 340 / 2000000;
    Serial.println(distance);
    return distance;
    delay(80);
}

void forward() //前进
{
    //IN01，IN02控制后左电机
    analogWrite(IN01, 80);
    analogWrite(IN02, 0);
    //IN03,IN04控制后右电机
    analogWrite(IN03, 0);
    analogWrite(IN04, 90);
    //IN11,IN12控制前左电机
    analogWrite(IN11, 80);
    analogWrite(IN12, 0);
    //IN13，IN14控制前右电机
    analogWrite(IN13, 0);
    analogWrite(IN14, 90);
}

void rolling() //原地旋转
{
    //IN01，IN02控制后左电机
    analogWrite(IN01, 51);
    analogWrite(IN02, 0);
    //IN03,IN04控制后右电机
    analogWrite(IN03, 70);
    analogWrite(IN04, 0);
    //IN11,IN12控制前左电机
    analogWrite(IN11, 90);
    analogWrite(IN12, 0);
    //IN13，IN14控制前右电机
    analogWrite(IN13, 75);
    analogWrite(IN14, 0);
}

void right45() //向左旋转45度
{
    rolling();
    delay(745);
    stop();
    delay(3000);
}

void back() //后退
{
    //IN01，IN02控制后左电机
    analogWrite(IN01, 0);
    analogWrite(IN02, 80);
    //IN03,IN04控制后右电机
    analogWrite(IN03, 80);
    analogWrite(IN04, 0);
    //IN11,IN12控制前左电机
    analogWrite(IN11, 0);
    analogWrite(IN12, 80);
    //IN13，IN14控制前右电机
    analogWrite(IN13, 80);
    analogWrite(IN14, 0);
}

void left() //左转
{
    //IN01，IN02控制后左电机
    analogWrite(IN01, 0);
    analogWrite(IN02, 80);
    //IN03,IN04控制后右电机
    analogWrite(IN03, 0);
    analogWrite(IN04, 80);
    //IN11,IN12控制前左电机
    analogWrite(IN11, 0);
    analogWrite(IN12, 90);
    //IN13，IN14控制前右电机
    analogWrite(IN13, 0);
    analogWrite(IN14, 88);
}

void right() //右转
{
    //IN01，IN02控制后左电机
    analogWrite(IN01, 60);
    analogWrite(IN02, 0);
    //IN03,IN04控制后右电机
    analogWrite(IN03, 68);
    analogWrite(IN04, 0);
    //IN11,IN12控制前左电机
    analogWrite(IN11, 66);
    analogWrite(IN12, 0);
    //IN13，IN14控制前右电机
    analogWrite(IN13, 74);
    analogWrite(IN14, 0);
}

void stop() //停止
{
    //IN01，IN02控制后左电机
    analogWrite(IN01, 0);
    analogWrite(IN02, 0);
    //IN03,IN04控制后右电机
    analogWrite(IN03, 0);
    analogWrite(IN04, 0);
    //IN11,IN12控制前左电机
    analogWrite(IN11, 0);
    analogWrite(IN12, 0);
    //IN13，IN14控制前右电机
    analogWrite(IN13, 0);
    analogWrite(IN14, 0);
}

void left_advance() //左前
{
    //IN01，IN02控制后左电机
    analogWrite(IN01, 100);
    analogWrite(IN02, 0);
    //IN03,IN04控制后右电机
    analogWrite(IN03, 0);
    analogWrite(IN04, 0);
    //IN11,IN12控制前左电机
    analogWrite(IN11, 0);
    analogWrite(IN12, 0);
    //IN13，IN14控制前右电机
    analogWrite(IN13, 0);
    analogWrite(IN14, 100);
}

void xunji()
{
    if (digitalRead(D04) == 1 && digitalRead(D03) == 0 && digitalRead(D02) == 1)
    {
        forward();
    }
    else if (digitalRead(D04) == 1 && digitalRead(D03) == 1 && digitalRead(D02) == 1)
    {
        while(1)
        {
            right();
            if(digitalRead(D04) == 1 && digitalRead(D03) == 0 && digitalRead(D02) == 1) 
            { 
                stop();
                delay(100);
                break;
            }
            else if(digitalRead(D04) == 0 && digitalRead(D03) == 1 && digitalRead(D02) == 1)
            {
                left();
                if(digitalRead(D04) == 1 && digitalRead(D03) == 0 && digitalRead(D02) == 1)
                {
                    stop();
                    delay(100);
                    break;
                }
            }
            break;
        }
    }
    else if(digitalRead(D04) == 0 && digitalRead(D02) == 1)
    {
        left();
        if(digitalRead(D04) == 1 && digitalRead(D03) == 0 && digitalRead(D02) == 1)
        {
            delay(50);
            stop();
            delay(100);
        }
    }
    else if(digitalRead(D04) == 1  && digitalRead(D02) == 0)
    {
        right();
        if(digitalRead(D04) == 1 && digitalRead(D03) == 0 && digitalRead(D02) == 1)
        {
            stop();
            delay(100);
        }
    }
    else forward();
}

void loop()
{
    //infrared_tracking();
    //delay(1000);
    //chaoshengbo();
        left();
        delay(5000);
        stop();
        delay(500);
        right();
        delay(5000);
        stop();
        delay(500);

}