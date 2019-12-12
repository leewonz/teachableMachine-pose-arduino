#include <Keyboard.h>
#include <Servo.h>

String serialStr = "";
String serialStr_log = "";

const int PIN_SERVO_1 = 3;
const int PIN_SERVO_2 = 5;
const int PIN_SERVO_3 = 6;
const int PIN_SERVO_4 = 9;
const int PIN_SERVO_5 = 10;
const int PIN_SERVO_6 = 11;

Servo servo_1;
Servo servo_2;
Servo servo_3;
Servo servo_4;
Servo servo_5;
Servo servo_6;

int poseIndex = -1;
float poseAmount =  0;

const int setAll = -1;
const int setPose = -1;

void setup() { 

  Serial.begin(9600);

  servo_1.attach(PIN_SERVO_1);
  servo_2.attach(PIN_SERVO_2);
  servo_3.attach(PIN_SERVO_3);
  servo_4.attach(PIN_SERVO_4);
  servo_5.attach(PIN_SERVO_5);
  servo_6.attach(PIN_SERVO_6);

}



void loop() {

  int letterCount = 0;
  

  while(Serial.available() > 0) {
    char currentChar = Serial.read();
    serialStr += currentChar;
    
    if (serialStr.indexOf("\n") != -1)
    {
      serialStr.replace("\n","");
    }
    letterCount ++;
    
    if (serialStr.indexOf("/") != -1)
    {
      serialStr.replace("/","");
      
      if (serialStr.indexOf("index:") != -1)
      {
        serialStr.replace("index:", "");
        poseIndex = serialStr.toInt();

        Serial.print("i : " + serialStr + " | ");
        serialStr_log += serialStr;
        serialStr = "";
      }
      
      else if (serialStr.indexOf("amount:") != -1)
      {
        serialStr.replace("amount:", "");
        poseAmount = serialStr.toFloat();

        Serial.print("a : " + serialStr + " | ");
        serialStr_log += serialStr;
        serialStr = "";
      }
    }
  }

  if (setAll != -1)
  {
    servo_1.write(setAll); 
    servo_3.write(setAll);
    servo_5.write(setAll);
    
    servo_2.write(setAll);
    servo_4.write(setAll);
    servo_6.write(setAll); 
  }
  else if (setPose != -1)
  {
    if (setPose == 0)
    {
      servo_1.write(180); 
      servo_3.write(90);
      servo_5.write(0);
      
      servo_2.write(0);
      servo_4.write(90);
      servo_6.write(0); 
    }
    if (setPose == 1)
    {
      servo_1.write(0); 
      servo_3.write(0);
      servo_5.write(90);
      
      servo_2.write(180);
      servo_4.write(180);
      servo_6.write(90);  
    }
    if (setPose == 2 )
    {
      servo_1.write(0); 
      servo_3.write(180);
      servo_5.write(90);
      
      servo_2.write(180);
      servo_4.write(0);
      servo_6.write(90);  
    }
    if (setPose == 3)
    {
      servo_1.write(180); 
      servo_3.write(90);
      servo_5.write(180);
      
      servo_2.write(0);
      servo_4.write(90);
      servo_6.write(180); 
    }
  }
  else
  {
    if (poseIndex == 0)
    {
      servo_1.write(0); 
      servo_3.write(90);
      servo_5.write(0);
      
      servo_2.write(0);
      servo_4.write(90);
      servo_6.write(0); 
    }
    if (poseIndex == 1)
    {
      servo_1.write(0); 
      servo_3.write(0);
      servo_5.write(90);
      
      servo_2.write(180);
      servo_4.write(180);
      servo_6.write(90);  
    }
    if (poseIndex == 2 )
    {
      servo_1.write(0); 
      servo_3.write(180);
      servo_5.write(90);
      
      servo_2.write(180);
      servo_4.write(0);
      servo_6.write(90);  
    }
    if (poseIndex == 3)
    {
      servo_1.write(0); 
      servo_3.write(90);
      servo_5.write(180);
      
      servo_2.write(0);
      servo_4.write(90);
      servo_6.write(180); 
    }
    if (poseIndex == -1 or poseAmount <= 0.5)
    {
      servo_1.write(180); 
      servo_3.write(90);
      servo_5.write(90);
      
      servo_2.write(0);
      servo_4.write(90);
      servo_6.write(90); 
    }
  }
}
