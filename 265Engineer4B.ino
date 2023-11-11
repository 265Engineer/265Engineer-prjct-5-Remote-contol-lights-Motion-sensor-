#include <IRremote.h>
int motionSensor = 5;
int Lights =6;
IRrecv IR (4);
void setup(){
  Serial.begin(9600);
  IR.enableIRIn();
  pinMode(motionSensor , INPUT);
  pinMode(Lights , OUTPUT);
}

void loop(){

  if (IR.decode()){
  
   // if(String(IR.decodedIRData.decodedRawData, HEX))
    //Serial.println(IR.decodedIRData.decodedRawData, HEX);
    while(IR.decodedIRData.decodedRawData == 0xFF089F20)
    {

         if  (digitalRead(motionSensor)== HIGH)
         {
            digitalWrite(Lights , HIGH);
            //delay(5000);
         }else 
         {
          digitalWrite(Lights , LOW);
          //delay(5000);
         }
         if (IR.decodedIRData.decodedRawData ==0xF4079F20)
         {
          break;
         }
      
    }
    while(IR.decodedIRData.decodedRawData ==0xF4079F20)
    { 
         if  (digitalRead(motionSensor)== HIGH)
         {
            digitalWrite(Lights , LOW);
            delay(5000);
         }else 
         {
          digitalWrite(Lights , LOW);
          delay(5000);
         }
              if(IR.decodedIRData.decodedRawData == 0xFF089F20)
      {
        break;
      }
    }

   IR.resume();

  }
}
