/*
 * Eric Luo
 * Robotic Follower
*/
#include <Arduino.h>
#include <Servo.h>
Servo servo;

#define sv1 3

#define trig 5
#define echo 4
float distance;
float prevDistance;

#define EnableA 6
#define InA1 7
#define InA2 8
#define InB1 9
#define InB2 10
#define EnableB 11

bool targetLostBool;

void setup() {
  Serial.begin(9600);

  servo.attach(sv1);

  pinMode(trig, OUTPUT); 
  pinMode(echo, INPUT);

  // Left Wheel
  pinMode(EnableA, OUTPUT);
  pinMode(InA1, OUTPUT);
  pinMode(InA2, OUTPUT);
  // Right Wheel
  pinMode(InB1, OUTPUT);
  pinMode(InB2, OUTPUT);
  pinMode(EnableB, OUTPUT);

}

void drive(float speed){
  speed = speed / 100.0 * 255.0; 

  digitalWrite(InA1, HIGH);
  digitalWrite(InA2, LOW);
  analogWrite(EnableA, speed);

  digitalWrite(InB1, HIGH);
  digitalWrite(InB2, LOW);
  analogWrite(EnableB, speed);
}

void length(){
  /*
   * Finds the distance from ultrasonic sensor.
   * Stores result in distance variable in CM.
  */
  digitalWrite(trig, LOW);
  delayMicroseconds(5);
  
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  distance = pulseIn(echo, HIGH);
  distance = distance/58.0;
  prevDistance = distance;
  Serial.println(prevDistance);
  Serial.println(distance);
}

void sweep(){
  servo.write(0);
  for (int pos = 0; pos <= 180; pos++){
    servo.write(pos);
    delay(15);
    if ()
  }

}
void find(){
  /*
   * Finds the target to follow.
  */
  if (targetLostBool){
    sweep();
  }
}

void targetLost(){
  /*
   * Checks if the target object 
  */

  // If target moves faster than x cm/s, target is declared as lost
  if (abs(prevDistance - distance) > 10){
    targetLostBool = true;
  }
}

void loop(){
  length(); 
  drive(distance);

}

void Right(int deg){

}

void Left(int deg){

}

// Function for 

// Function for object not found

// Function for finding object

// Function for servo locking onto object

// Function for turning robot straight keeping servo locked onto object

