//Maanya Goenka
//01.23.2020
//Light_Following_3
//CS 232

#include <Servo.h>
Servo servo1;
Servo servo2;

void setup()
{
  servo1.attach(12); 
  servo2.attach(10);
  Serial.begin(9600);
}

void loop()
{
  int minValueSeen = 1500; //the maximum value appears to be 1023
  int minAngle = 0;
  for (int currentAngle=0; currentAngle<=180; currentAngle++) //rotates the servo arm through its path 
  {
    servo1.write(currentAngle); 
    delay(100);
    int valueSeen = analogRead(A0);  //reads the analog input on pin A0
    if(valueSeen < minValueSeen)     //compares each recorded light value to the minimum to find the brightest point 
    {   
      minValueSeen = valueSeen;
      minAngle = currentAngle;
    }
  }
  servo2.write(minAngle);      //servo2 arm points to brightest spot it had seen during the rotation
  delay(1200);                 //delay for a brief period before restarting
  Serial.print("Angle at which minimum value was seen: ");
  Serial.println(minAngle);
}
