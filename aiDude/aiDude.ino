// V 0.3
// START DATE: 6/17/24
// END DATE : X/X/X
// BY: Axuko / AXG Software
#include <LedControl.h>
#include "SR04.h" 
#include <Servo.h> 

 int DIN = 12;  
 int CS = 11;  
 int CLK = 10; 
 int trig_pin = 9;
 int echo_pin = 8;
 int servoMax = 180;
 int servoMin = 0; 

 LedControl lc=LedControl(DIN,CLK,CS,0);
 SR04 sensor = SR04(echo_pin,trig_pin);
 Servo myServo; 

 long distance; 

 void setup(){
  myServo.attach(13);
  Serial.begin(9600);
  delay(1000);  
  lc.shutdown(0,false);      
  lc.setIntensity(0,7);   //Adjust the brightness maximum is 15  
  lc.clearDisplay(0);    
 }  
 void loop(){   
   distance = sensor.Distance();
   Serial.println(distance);
   delay(1);
   //Facial Expression  
   byte smile[8]=  {0x3C,0x42,0xA5,0x81,0xA5,0x99,0x42,0x3C};  
   byte neutral[8]= {0x3C,0x42,0xA5,0x81,0xBD,0x81,0x42,0x3C};  
   byte sad[8]=  {0x3C,0x42,0xA5,0x81,0x99,0xA5,0x42,0x3C}; 

  //Facial Expression
   if (distance <= 15) {
      printByte(smile);
      myServo.write(servoMax);
      delay(1000);
      myServo.write(servoMin);
      delay(1000);
   }
   else if (distance <= 25) {
      printByte(neutral); 
   }
   else {
      printByte(sad); 
   }    
 }  

 void printByte(byte character [])  
 {  
  int i = 0;  
  for(i=0;i<8;i++)  
  {  
   lc.setRow(0,i,character[i]);  
  }  
 }  
