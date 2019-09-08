
//CODE Written by RAJDEEP BARUAH
/*------------------------------------------------------------------------------------------------------------------------------------------*/

#include<LiquidCrystal.h>

LiquidCrystal lcd(A5,A4,A3,A2,A1,A0);
int val,distance,duration,sen1,sen2;

void setup() {
  Serial.begin(9600);
  
  lcd.begin(16,2);
  analogWrite(9,50);

  pinMode(2,INPUT);             // For Switch
  pinMode(4,OUTPUT);            // For RED LED
  pinMode(5,OUTPUT);            // For GREEN LED
  //pinMode(6,OUTPUT);            // For Buzzer
  pinMode(7,OUTPUT);            // For Trigger Pin
  pinMode(8,INPUT);             //  For Echo Pin
  pinMode(10,OUTPUT);           // For Motor
  pinMode(11,OUTPUT);     
  pinMode(12,INPUT);            // For IR Sensor 1
  pinMode(13,INPUT);            // For IR Sensor 2

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("      STOP      ");
  lcd.setCursor(0,1);
  lcd.print(" CROSSING AHEAD ");
} 

void loop() 
{     
      dist();
      val=digitalRead(2);
      sen1=digitalRead(12);
      sen2=digitalRead(13);
      Serial.println(val);
      //Serial.println(distance);
      //Serial.println(sen1);
      //Serial.println(sen2);

     
   
    if(val==0)
    {   
        analogWrite(3,20);
        if(sen2==1)
         {  
            digitalWrite(4,HIGH);
            digitalWrite(5,LOW);
            digitalWrite(6,HIGH);
            
            if(distance>5) 
            {
               digitalWrite(10,HIGH);
               digitalWrite(11,LOW);
            }
            else
            {
               digitalWrite(10,LOW);
               digitalWrite(11,LOW);
            }
         }
        else
         {  
            digitalWrite(4,LOW);
            digitalWrite(5,HIGH);
            digitalWrite(6,LOW);
            digitalWrite(10,LOW);
            digitalWrite(11,LOW);
         } 
    }
    else
    {  
        analogWrite(3,200);
        digitalWrite(4,HIGH);
        digitalWrite(5,LOW);
        digitalWrite(6,LOW);
      
        if(sen1==1)
         {
            digitalWrite(10,LOW);
            digitalWrite(11,HIGH);
         }
        else
         {
            digitalWrite(10,LOW);
            digitalWrite(11,LOW);
         } 
    }
}

void dist(){

  digitalWrite(7, LOW);
  delayMicroseconds(2);

  digitalWrite(7,HIGH);
  delayMicroseconds(10);
  digitalWrite(7, LOW);

  duration = pulseIn(8,HIGH);
  distance = duration*0.034/2;
  }

  

