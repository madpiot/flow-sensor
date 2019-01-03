#include <Arduino.h>

const int  flowPin1 = D2; 
const int  flowPin2 = D1;

int flow_value1 = 0, flow_value2=0;   
int flow_liters1 = 0, flow_liters2=0;
  
void pin1_ISR()
{   
 flow_value1++;
}

void pin2_ISR()
{
  flow_value2++;
}

void setup()
{
   Serial.begin(9600);
   pinMode(flowPin1, INPUT);
   pinMode(flowPin2, INPUT);
   attachInterrupt(digitalPinToInterrupt(flowPin1), pin1_ISR, RISING);
   attachInterrupt(digitalPinToInterrupt(flowPin2), pin2_ISR, RISING);
}


void loop() 
{
 //Serial.println(contagem);
 if(flow_value1 > 440 )
 {
      flow_liters1++;
      Serial.println();
      Serial.print("Liters1: ");
      Serial.print(flow_liters1);
      flow_value1 = 0;
      delay(1000);
 }
 if(flow_value2 > 440 )
 {
      flow_liters2++;
      Serial.println();
      Serial.print("Liters2: ");
      Serial.print(flow_liters2);
      flow_value2 = 0;
      delay(1000);
 }  
}
