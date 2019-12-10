#include <Keyboard.h>

int led = 5;
String serialStr = "";
String serialStr_log = "";

int poseIndex = -1;
float poseAmount =  0;

void setup() {
  pinMode(led, OUTPUT);   

  Serial.begin(9600);
  digitalWrite(led, LOW);

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

  if (poseIndex == 1)
  {
    digitalWrite(led, HIGH);
  }
  else
  {
    digitalWrite(led, LOW);
  }
}
