//Sender
#include <Wire.h>

int upLeftButtPin = 2;
int downLeftButtPin = 11;
int upRightButtPin = 6;
int downRightButtPin = 13;
int potPin = 0; //Analog

byte x = 0;

void setup() {
  Wire.begin(); //for 12c bus
  pinMode(upLeftButtPin, INPUT);
  pinMode(upRightButtPin, INPUT);
  pinMode(downRightButtPin, INPUT);
  pinMode(downLeftButtPin, INPUT);
  Serial.begin(9600);
  Serial.print("Test");
}

void loop() {
  Wire.beginTransmission(8);
  //Wire.write("x is");
  //Wire.endTransmission();


  int upLeftButtState = digitalRead(upLeftButtPin);
  int downLeftButtState = digitalRead(downLeftButtPin);
  int upRightButtState = digitalRead(upRightButtPin);
  int downRightButtState = digitalRead(downRightButtPin);
  
  if(upLeftButtState == HIGH && upRightButtState == HIGH){
      Wire.write("LeftForward");
      Wire.write("RightForward");
      Serial.println("L R Forward");
    }
 
  else if(upLeftButtState == HIGH && downRightButtState == HIGH){
      Serial.println("up L down R");
      Wire.write("LeftForward");
      Wire.write("RightBack");
    }
  else if(upRightButtState == HIGH && downLeftButtState == HIGH){
      Serial.println("down L up R");
      Wire.write("LeftBack");
      Wire.write("RightForward");
    }
  else if(downLeftButtState == HIGH && downRightButtState == HIGH){
      Serial.println("down L down R");
      Wire.write("LeftBack");
      Wire.write("RightBack");
    }
  else if(downRightButtState == HIGH){
      Serial.println("down Right");
      Wire.write("RightBack");
  } 
  else if(downLeftButtState == HIGH){
      Serial.println("down Left");
      Wire.write("LeftBack");
    } 
  else if(upRightButtState == HIGH){
      Serial.println("up Right");
      Wire.write("RightForward");
    }
  else if(upLeftButtState == HIGH){
      Serial.println("up Left");
      Wire.write("LeftForward");
    }
   delay(10);
   Wire.endTransmission();
}
