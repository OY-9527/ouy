//传感器pcb板子距离物块表面最高点10mm为最佳状态
int s0=3,s1=4,s2=5,s3=6;
int flag=0;
int counter=0;
int countR=0,countG=0,countB=0;
float H=0;
void setup()
{
    Serial.begin(9600);
    pinMode(s0,OUTPUT);
    pinMode(s1,OUTPUT); 
    pinMode(s2,OUTPUT);
    pinMode(s3,OUTPUT);
}

void TCS()
{
    digitalWrite(s1,HIGH);
    digitalWrite(s0,LOW);
    flag=0;
    attachInterrupt(0, ISR_INTO, CHANGE);
    timer2_init();
 }

void ISR_INTO()
{
    counter++;
}

void timer2_init(void)
{
    TCCR2A=0x00;
    TCCR2B=0x07; //the clock frequency source 1024 points
    TCNT2= 100;    //10 ms overflow again
    TIMSK2 = 0x01; //allow interrupt
}

int i=0;
ISR(TIMER2_OVF_vect)//the timer 2, 10ms interrupt overflow again. Internal overflow interrupt executive function
{
    TCNT2=100;
    flag++;
    if(flag==1)
    {
        counter=0;
    }
    else if(flag==2)
    {
        digitalWrite(s2,LOW);
        digitalWrite(s3,LOW); 
        countR=counter*1.9;
        Serial.print("red=");
        Serial.println(counter,DEC);
        digitalWrite(s2,HIGH);
        digitalWrite(s3,HIGH);   
    }
    else if(flag==3)
    {
        countG=counter*2.2;
        Serial.print("green=");
        Serial.println(counter,DEC);
        digitalWrite(s2,LOW);
        digitalWrite(s3,HIGH); 
    }
    else if(flag==4)
    {
        countB=counter*1.64;
        Serial.print("blue=");
        Serial.println(counter,DEC);
        digitalWrite(s2,LOW);
        digitalWrite(s3,LOW);
    }
    else
    {
        flag=0; 
        TIMSK2 = 0x00;
    }
    counter=0;
    delay(2);
}
void huidu()
{
  if((countR>countB)&&(countR>countG))
  {
     if(countB>countG)
      {
        H=(countR+countG)/5.10;
      }
    else
      {
        H=(countR+countB)/5.10;
      } 
  }
  else if((countG>countB)&&(countG>countR))
  {
     if(countB>countR)
     {
     H=(countR+countG)/5.10;
      }
       else
     {
       H=(countG+countB)/5.10;
     } 
  }
   else
{
  if((countB>countR)&&(countB>countG))
  {
    if(countR>countG)
    {
      H=(countB+countG)/5.10;
    }
    else
    {
    H=(countR+countB)/5.10;
    } 
  }
}
  }
void loop()
{
    delay(10);
    TCS();
    huidu();
    if((countR<10) && (countG<10) && (countB<10))
    {
        Serial.print("balck!");
        Serial.print("\n");
        Serial.print("\n");
        delay(1000);
    }
    else if((countR>40) && (countG>40) && (countB>40))
    {
        Serial.print("white!");
        Serial.print("\n");
        Serial.print("\n");
        delay(1000);
    }
    else
    {
        if((countR>countG)&&(countR>countB))
        {
            Serial.print("red!");
            Serial.print("\n");
            Serial.print("\n");
            delay(1000);
        }
        else if((countG>=countR)&&(countG>countB))
        {
            Serial.print("green!");
            Serial.print("\n");
            Serial.print("\n");
            delay(1000);
        } 
        else if((countB>countG)&&(countB>countR))
        {
            Serial.print("blue!");
            Serial.print("\n");
            Serial.print("\n");
            delay(1000);
        }
    }
            Serial.print("灰度：");
          Serial.print(H);
              Serial.print("%");
            Serial.print("\n");
            Serial.print("\n");
}

