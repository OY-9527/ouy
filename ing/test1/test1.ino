int IN01=2,IN02=3,IN03=4,IN04=5;                //控制后面的两个电机
int IN11=6,IN12=7,IN13=8,IN14=9;                //控制前面的两个电机
int D01=22,D02=24,D03=26,D04=28,D05=30;         //车身前部红外循线传感器
int D11=23,D12=25,D13=27,D14=29,D15=31;         //车身后部红外循线传感器
bool a1,a2,a3,a4,a5;                            //前红外变量
bool b1,b2,b3,b4,b5;                            //后红外寄存变量

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
    //前红外传感器输入
    pinMode(D01,INPUT);
    pinMode(D02,INPUT);
    pinMode(D03,INPUT);
    pinMode(D04,INPUT);
    pinMode(D05,INPUT);
    //后红外传感器输入
    pinMode(D11,INPUT);
    pinMode(D12,INPUT);
    pinMode(D13,INPUT);
    pinMode(D14,INPUT);
    pinMode(D15,INPUT);
}

void infrared_tracking()
{
    //前红外输出
    a1=digitalRead(D01);
    a2=digitalRead(D02);
    a3=digitalRead(D03);
    a4=digitalRead(D04);
    a5=digitalRead(D05);
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
    b1=digitalRead(D11);
    b2=digitalRead(D12);
    b3=digitalRead(D13);
    b4=digitalRead(D14);
    b5=digitalRead(D15);
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
        analogWrite(IN01,i);
        analogWrite(IN02,0);
        //IN03,IN04控制后右电机
        analogWrite(IN03,0);
        analogWrite(IN04,i);
        //IN11,IN12控制前左电机
        analogWrite(IN11,0);
        analogWrite(IN12,0);
        //IN13，IN14控制前右电机
        analogWrite(IN13,0);
        analogWrite(IN14,0);
        delay(500);
    }
    
}

void forward()
{
    //IN01，IN02控制后左电机
    analogWrite(IN01,100);
    analogWrite(IN02,0);
    //IN03,IN04控制后右电机
    analogWrite(IN03,0);
    analogWrite(IN04,100);
    //IN11,IN12控制前左电机
    analogWrite(IN11,100);
    analogWrite(IN12,0);
    //IN13，IN14控制前右电机
    analogWrite(IN13,0);
    analogWrite(IN14,100);
}

void back()
{
    //IN01，IN02控制后左电机
    analogWrite(IN01,0);
    analogWrite(IN02,150);
    //IN03,IN04控制后右电机
    analogWrite(IN03,150);
    analogWrite(IN04,0);
    //IN11,IN12控制前左电机
    analogWrite(IN11,150);
    analogWrite(IN12,0);
    //IN13，IN14控制前右电机
    analogWrite(IN13,0);
    analogWrite(IN14,150);
}

void left()
{
    //IN01，IN02控制后左电机
    analogWrite(IN01,0);
    analogWrite(IN02,255);
    //IN03,IN04控制后右电机
    analogWrite(IN03,0);
    analogWrite(IN04,255);
    //IN11,IN12控制前左电机
    analogWrite(IN11,0);
    analogWrite(IN12,255);
    //IN13，IN14控制前右电机
    analogWrite(IN13,0);
    analogWrite(IN14,255);
}

void right()
{
    //IN01，IN02控制后左电机
    analogWrite(IN01,150);
    analogWrite(IN02,0);
    //IN03,IN04控制后右电机
    analogWrite(IN03,150);
    analogWrite(IN04,0);
    //IN11,IN12控制前左电机
    analogWrite(IN11,150);
    analogWrite(IN12,0);
    //IN13，IN14控制前右电机
    analogWrite(IN13,150);
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
    //IN11,IN12控制前左电机
    analogWrite(IN11,0);
    analogWrite(IN12,0);
    //IN13，IN14控制前右电机
    analogWrite(IN13,0);
    analogWrite(IN14,0);
}

void loop()
{
    infrared_tracking();
    for (size_t i = 0; i < 50; i++)
    {
        /* code */
        forward();
    }
    stop();
}




sfhasdhfasiupdfhasduhfusadifasduifhsipuadhdsauifhdsa
fasiudfhuasdfhpasduifhadfsfuasdf
safhuisdhf