#include <Servo.h>                                    //舵机对象库
#define echo_pin 10                                   //超声波echo
#define trig_pin 11                                   //超声波trig
Servo bihe1;                                          //机械爪舵机对象1
Servo bihe2;                                          //机械爪舵机对象2
int arm1_status, arm2_status;                         //机械爪角度输出值
int last_arm1_status = 50, last_arm2_status = 130;    //机械爪角度输出旧值
int pos = 0;                                          //机械爪对象实时输出值
float t, distance;                                    //超声波测距时间变量、实时距离变量
int IN01 = 2, IN02 = 3, IN03 = 4, IN04 = 5;           //控制后面的两个电机
int IN11 = 6, IN12 = 7, IN13 = 8, IN14 = 9;           //控制前面的两个电机
int D01 = 22, D02 = 24, D03 = 26, D04 = 28, D05 = 30; //车身前部红外循线传感器引脚
int D11 = 23, D12 = 25, D13 = 27, D14 = 29, D15 = 31; //车身后部红外循线传感器引脚
bool a1, a2, a3, a4, a5;                              //前红外寄存变量
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
    //閉合舵機引脚初始化
    bihe1.attach(12);
    bihe2.attach(13);
}

void infrared_tracking() //红外信号读取及串口打印
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

void speed_up() //驱动电机加速函数
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

float chaoshengbo() //超声波测距函数
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
    analogWrite(IN01, 130);
    analogWrite(IN02, 0);
    //IN03,IN04控制后右电机
    analogWrite(IN03, 0);
    analogWrite(IN04, 135);
    //IN11,IN12控制前左电机
    analogWrite(IN11, 130);
    analogWrite(IN12, 0);
    //IN13，IN14控制前右电机
    analogWrite(IN13, 0);
    analogWrite(IN14, 135);
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
    analogWrite(IN02, 130);
    //IN03,IN04控制后右电机
    analogWrite(IN03, 0);
    analogWrite(IN04, 130);
    //IN11,IN12控制前左电机
    analogWrite(IN11, 0);
    analogWrite(IN12, 135);
    //IN13，IN14控制前右电机
    analogWrite(IN13, 0);
    analogWrite(IN14, 135);
}

void right() //右转
{
    //IN01，IN02控制后左电机
    analogWrite(IN01, 130);
    analogWrite(IN02, 0);
    //IN03,IN04控制后右电机
    analogWrite(IN03, 135);
    analogWrite(IN04, 0);
    //IN11,IN12控制前左电机
    analogWrite(IN11, 130);
    analogWrite(IN12, 0);
    //IN13，IN14控制前右电机
    analogWrite(IN13, 135);
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

void xunji() //循迹功能
{
    if (digitalRead(D04) == 1 && digitalRead(D03) == 0 && digitalRead(D02) == 1)
    {
        forward();
    }
    else if (digitalRead(D04) == 1 && digitalRead(D03) == 1 && digitalRead(D02) == 1)
    {
        while (1)
        {
            right();
            if (digitalRead(D04) == 1 && digitalRead(D03) == 0 && digitalRead(D02) == 1)
            {
                stop();
                delay(100);
                break;
            }
            else if (digitalRead(D04) == 0 && digitalRead(D03) == 1 && digitalRead(D02) == 1)
            {
                left();
                if (digitalRead(D04) == 1 && digitalRead(D03) == 0 && digitalRead(D02) == 1)
                {
                    stop();
                    delay(100);
                    break;
                }
            }
            break;
        }
    }
    else if (digitalRead(D04) == 0 && digitalRead(D02) == 1)
    {
        left();
        if (digitalRead(D04) == 1 && digitalRead(D03) == 0 && digitalRead(D02) == 1)
        {
            delay(50);
            stop();
            delay(100);
        }
    }
    else if (digitalRead(D04) == 1 && digitalRead(D02) == 0)
    {
        right();
        if (digitalRead(D04) == 1 && digitalRead(D03) == 0 && digitalRead(D02) == 1)
        {
            stop();
            delay(100);
        }
    }
    else
        forward();
}

void pull_status1() //前端机械爪抱合物块状态1
{
    arm1_status = 170;
    arm2_status = 0;
    for (pos = last_arm1_status; pos <= arm1_status; pos += 1)
    {
        bihe1.write(pos);
        delay(10);
    }
    for (pos = last_arm2_status; pos >= arm2_status; pos -= 1)
    {
        bihe2.write(pos);
        delay(10);
    }
}

void arm_init() //前端机械爪状态初始化函数
{
    bihe1.write(last_arm1_status);
    bihe2.write(last_arm2_status);
}

void loop()
{
    //infrared_tracking();
    arm_init();
    chaoshengbo();
    bihe1.write(15);
    bihe2.write(180);
    if (distance > 0.05)
    {
        // code
        xunji();
    }
    else
    {
        stop();
        pull_status1();
    }
}