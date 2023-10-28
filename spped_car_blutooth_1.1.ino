#include <Servo.h>
Servo servo;

#define IN1 2
#define IN2 3 

#define ENA A0

char value;
int Speed=0;
int h=80;//angle
void setup() {
  Serial.begin(9600);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  pinMode(ENA, OUTPUT);

  servo.attach(6);
}

void loop() {
  if(!Serial.available()){
    for(int i=0;i<600;i++){
      if(Serial.available()) break;
      delay(10);
      if(i==599)Stop();
    }
  }
  
  
  if (Serial.available() > 0) {
    value = Serial.read();
    Serial.println(value);
    Serial.println(Speed);

    if (value == 'F') {
      Forward();
    }
    else if (value == 'B') {
      Backward();
    } 
    else if (value == 'S') {
      Stop();
    } 
    else if (value == 'L') {
      Left();
    } 
    else if (value == 'R' ) {
      Right();
    } 
    else if(value== 'A'){
      Speed=150;
    }
    else if(value== 'C'){
      Speed=200;
    }
    else if(value== 'D'){
      Speed=250;
    }
    else if(value=='E'){
      Speed=255;
    }
    else if(value== 'Z'){
      //party1();
    }
    else if(value== 'Y'){
      //party2();
    }
    else if(value== 'X'){
      //party3();
    }
    else if(value== 'W'){
      //party4();
    }
  }
}

void Forward() {
  h=70;
  servo.write(h);
  analogWrite(ENA, Speed);

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

}
void Backward() {
  h=70;
  servo.write(h);
  analogWrite(ENA, Speed);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
}
void Stop() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
}
void Left() {
  h+=10;
  servo.write(h);
  
}
void Right() {
  h-=10;
  servo.write(h);
}
void party1(){
    Speed=200;
    Forward();
    delay(2000);
    Left();
    delay(2000);
    Right();
    delay(2000);
    Forward();
    delay(2000);
    Left();
    delay(2000);
    Right();
    delay(2000);
    Backward();
    delay(10000);
    Stop();
  }

