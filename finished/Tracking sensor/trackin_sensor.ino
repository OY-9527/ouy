int r1=2,r2=3,r3=4,r4=5;
int l1=9,l2=8,l3=7,l4=6;
int a,b,c,d,e,f,g,h;

void setup()
{
    Serial.begin(9600);
    pinMode(r1,INPUT);
    pinMode(r2,INPUT);
    pinMode(r3,INPUT);
    pinMode(r4,INPUT);
    pinMode(l1,INPUT);
    pinMode(l2,INPUT);
    pinMode(l3,INPUT);
    pinMode(l4,INPUT);
    pinMode(IR,OUTPUT);
}

void tracking()
{
    a=digitalRead(r1);
    b=digitalRead(r2);
    c=digitalRead(r3);
    d=digitalRead(r4);
    e=digitalRead(l1);
    f=digitalRead(l2);
    g=digitalRead(l3);
    h=digitalRead(l4);
    Serial.print("l1=");
    Serial.print(e);
    Serial.print("    ");
    Serial.print("l2=");
    Serial.print(f);
    Serial.print("    ");
    Serial.print("l3=");
    Serial.print(g);
    Serial.print("    ");
    Serial.print("l4=");
    Serial.print(h);
    Serial.print("    ");
    Serial.print("r4=");
    Serial.print(d);
    Serial.print("    ");
    Serial.print("r3=");
    Serial.print(c);
    Serial.print("    ");
    Serial.print("r2=");
    Serial.print(b);
    Serial.print("    ");
    Serial.print("r1=");
    Serial.println(a);
    delay(1000);
}