//Receiver

#include <Servo.h>
#include <Wire.h>

//RC Channels
int ch1;
int ch2;
int ch3;

int chan1Pin = 3;
int chan2Pin = 4;
int chan3Pin = 5;

Servo motorLeft;
Servo motorRight;

int motorLeftPin = 11;
int motorRightPin =  10;

//Motor Control
int motorReverse = 0;
int motorStop = 90;
int motorForward = 180;
int motorForwardSlow = 110;
int motorForwardTurnSlow = 103;
int motorReverseSlow = 55;

int oldPotLeftState = 0;
int oldPotRightState = 0;

int potLeftPin = 3;
int potRightPin = 4;

int lightLeftLimit = 500;
int lightMiddleLimit = 100;
int lightRightLimit = 500;

//LEDs
int ledRightPin = 2;
int ledMiddlePin = 12;
int ledLeftPin = 13;

//Analog
int lightLeftPin = 2;
int lightMiddlePin = 1;
int lightRightPin = 0;

bool L = false;
bool M = false;
bool R = false;

void setup() {
  Wire.begin(8); //join 12c bus with address #8
  //Wire.onReceive(receiveEvent);
  Serial.begin(9600);
  Serial.print("Ay b0ss");

  motorLeft.attach(motorLeftPin, 1000, 2000);
  motorRight.attach(motorRightPin, 1000, 2000);

  motorLeft.write(motorStop);
  delay(500);
  motorLeft.write(motorStop);
  delay(500);

  motorRight.write(motorStop);
  delay(500);
  motorRight.write(motorStop);
  delay(500);

  pinMode(ledRightPin, OUTPUT);
  pinMode(ledMiddlePin, OUTPUT);
  pinMode(ledLeftPin, OUTPUT);

  pinMode(chan1Pin, INPUT);
  pinMode(chan2Pin, INPUT);
  pinMode(chan3Pin, INPUT);
}

void loop() {
  Wire.onReceive(receiveEvent);
  // Radio Teleop Stuff (WIP) --------------------------
  /*int ch1Reading = pulseIn(chan1Pin, HIGH, 25000);
  int ch2Reading = pulseIn(chan2Pin, HIGH, 25000);
  int ch3Reading = pulseIn(chan3Pin, HIGH, 25000);

  int ch1Scaled = map(ch1Reading, 870, 1720, 0, 180);
  int ch3Scaled = map(ch3Reading, 14240, 15000, 0, 180);*/
  //Left Joy Y-Axis
  //Serial.print("Channel 1:");
  //Serial.println(ch1Reading);

  //Serial.print("Channel 2:");
  //Serial.println(ch2Reading);

  //Right Y-Axis Joystick
  //Serial.print("Channel 3:");
  //Serial.println(ch3Reading);

  /*motorLeft.write(ch1Scaled);
  delay(10);
  motorRight.write(ch3Scaled);
  delay(10);*/


  // ---------Arduino Teleop Stuff----------------------------

  /*int potLeftReading = analogRead(potLeftPin);
  
  int potRightReading = analogRead(potRightPin);
  //Serial.println(potRightReading);
  
  int leftReading = analogRead(lightLeftPin); //L and R are equal +-30 units
  //Serial.println("L");
  int leftScaled = map(leftReading, 200, 600, 0, 1023);
  //Serial.println(leftScaled);
  
  int middleReading = analogRead(lightMiddlePin);
  int middleScaled = map(middleReading, 200, 600, 0, 1023);
  //Serial.println(middleReading);
  
  int rightReading = analogRead(lightRightPin);
  //Serial.println("R");
 // Serial.println(rightReading);
  int rightScaled = map(rightReading, 200, 600, 0, 1023);

  if(leftScaled >= potLeftReading){
    digitalWrite(ledLeftPin, HIGH);
    L = true;
  } else{
    digitalWrite(ledLeftPin, LOW);
    L = false;
    }

  if(middleScaled >= potRightReading + 30 || middleScaled >= potRightReading - 30){
    digitalWrite(ledMiddlePin, HIGH);
    M = true;  
  } else{
    digitalWrite(ledMiddlePin, LOW);
    M = false;
    }
  
  if(rightScaled >= potRightReading){
    digitalWrite(ledRightPin, HIGH);
    R = true;
  } else{
    digitalWrite(ledRightPin, LOW);
    R = false;
    }

  //Straight Path || No Fire
  if((!L && M && !R) || (!L && !M && !R)){
      motorLeft.write(motorForwardSlow);
      motorRight.write(motorForwardSlow);
    }

  //Left Fire
  else if((L && M && !R) || (L && !M && !R)){
      motorLeft.write(motorStop);
      delay(20);
      motorRight.write(motorForwardTurnSlow);
      //Serial.print("Left Fire");
    }
    
  //Right Fire
  else if((!L && M && R) || (!L && !M && R)){
      motorLeft.write(motorForwardTurnSlow);
      delay(20);
      motorRight.write(motorStop);
      //Serial.print("Right Fire");
    }

  //No Fire
  else if(L && M && R){
      motorLeft.write(motorStop);
      motorRight.write(motorStop);
      //Serial.print("No fire");
      delay(300);
      motorLeft.write(motorForwardSlow);
      motorRight.write(motorForwardSlow);
      delay(500);
      motorLeft.write(motorStop);
      motorRight.write(motorStop);
      delay(20);
      motorLeft.write(motorReverse);
      motorRight.write(motorReverse);
      delay(2500);
      motorLeft.write(motorStop);
      motorRight.write(motorForward);
      delay(5000);
      motorRight.write(motorStop);
      motorLeft.write(motorForward);
      delay(100);
    }
    
  delay(1);*/
}


//executes when data is received from master
int receiveEvent(){
  while(1 < Wire.available()){
      char c = Wire.read();
      Serial.print(c);
    }
   int x = Wire.read();
   Serial.println(x);
   return x;
  }
