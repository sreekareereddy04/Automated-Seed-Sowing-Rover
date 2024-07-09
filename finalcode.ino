#include <MotorDriver.h>
#include <Servo.h>

// Define the pins
const int trig = A0; // Analog pin for trigger
const int echo = A1; // Analog pin for echo

// Variables for duration and distance

int max = 30;
int pos = 0;    // variable to store the servo position

MotorDriver m;
Servo myservo;  

bool start = 0;

void setup()
{
  // put your setup code here, to run once:
 // Serial.begin(9600);
  myservo.attach(9); 
  
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
}


void loop()
{
  //m.motor(3,FORWARD,255);
  //m.motor(4,FORWARD,255);  
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  long duration = pulseIn(echo, HIGH);
  //Serial.println(duration);
  int distance = duration * 0.034/2;
  //Serial.println("Distance: ");
  //Serial.print(distance);

  

  if(distance < max) {
    m.motor(1,BRAKE,0);
    m.motor(4,BRAKE,0);

  }
  else {
    m.motor(1,FORWARD,250);
    m.motor(4,FORWARD,250);
    if(start == 0){
      delay(2000);
      for (pos = 0; pos <= 70; pos += 1) { // goes from 0 degrees to 180 degrees
      // in steps of 1 degree
        myservo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(5);                       // waits 15 ms for the servo to reach the position
      }
      for (pos = 70; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
        myservo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(5);      
                    // waits 15 ms for the servo to reach the position
    }
    start = 1; 
    } else{
      for (pos = 0; pos <= 70; pos += 1) { // goes from 0 degrees to 180 degrees
      // in steps of 1 degree
        myservo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(5);                       // waits 15 ms for the servo to reach the position
      }
      for (pos = 70; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
        myservo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(5); 
      }
    }
    
  }
  delay(5);
  

}