#include <ESP32Servo.h>


Servo myservo;

int pos = 0;
int i;

int servoPin = 23;

void setup() {
  // put your setup code here, to run once:
  ESP32PWM :: allocateTimer(0);
  ESP32PWM :: allocateTimer(1);
  ESP32PWM :: allocateTimer(2);
  ESP32PWM :: allocateTimer(3);
  myservo.setPeriodHertz(50);
  myservo.attach(servoPin, 400,2400);

}

void loop() {
  // put your main code here, to run repeatedly:

  for (i = 0 ; i <= 3; i += 1){
    myservo.write(180);
    delay(3000);
    myservo.write(0);
    delay(3000);

  }
 

}
