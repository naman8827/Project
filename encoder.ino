const int steppin1 =4;
const int steppin2 = 7;
const int dirpin1= 3;
const int dirpin2=6;
const int enpin1=2;
const int enpin2=5;
char charBuf[5];
int t=0;
String value;
void setup(){
   Serial.begin(9600);
   pinMode(steppin1,OUTPUT); 
   pinMode(steppin2,OUTPUT);
   pinMode(dirpin1,OUTPUT);
   pinMode(dirpin2,OUTPUT);
   pinMode(enpin1,OUTPUT);
   pinMode(enpin2,OUTPUT);
   digitalWrite(enpin1,LOW);
   digitalWrite(enpin2,LOW);
   
}
 void loop(){
  if(Serial.available()){
    value=Serial.readStringUntil('\n');
     value.toCharArray(charBuf, 5) ;
  int u = atoi(charBuf);
  digitalWrite(dirpin1,HIGH);
  digitalWrite(dirpin2,LOW);
  for(int x=0;x<800;x++)
  {
    digitalWrite(steppin1,HIGH);
    digitalWrite(steppin2,HIGH);
    delayMicroseconds(500);
    digitalWrite(steppin1,LOW);
    digitalWrite(steppin2,LOW);
    delayMicroseconds(500);
    }
  if(u>0)
   { for(int x=0;x<50*u;x++)
    {
      digitalWrite(steppin2,HIGH);
      delayMicroseconds(500);
      digitalWrite(steppin2,LOW);
      delayMicroseconds(500);
    }
   }
   if(u<0)
   {  t=(-1)*u;
     for(int x=0;x<50*t;x++)
    {
      digitalWrite(steppin1,HIGH);
      delayMicroseconds(500);
      digitalWrite(steppin1,LOW);
      delayMicroseconds(500);
    }
   }
  }
 }  
 
 
