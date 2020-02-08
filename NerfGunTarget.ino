#include <Servo.h>;
 
 // pushbutton pin
 const int buttonPin = 8;
 // servo pin
 const int servoPin = 3;
 Servo servo;
//create a variable to store a counter and set it to 0
int counter = 0;
int led = 13; // the pin the LED is connected to

void setup()
{
  servo.attach (servoPin);
  
  // Set up the pushbutton pins to be an input:
  pinMode(buttonPin, INPUT);
  pinMode(led, OUTPUT); // Declare the LED as an output
}
void loop()
{
  digitalWrite(led, HIGH); // Turn the LED on
 // local variable to hold the pushbutton states
  int buttonState;  
  //read the digital state of buttonPin with digitalRead() function and store the           //value in buttonState variable
  buttonState = digitalRead(buttonPin);
  //if the button is pressed increment counter and wait a tiny bit to give us some          //time to release the button
  if (buttonState == LOW) // light the LED
  {
    counter++;
    delay(900);
  }
  if(counter == 0)
    servo.write (10);  // zero degrees
  else if(counter == 1)
    servo.write(120);
    delay(700);
if (buttonState == HIGH)
servo.write (10);
  //else reset the counter to 0 which resets thr servo to 0 degrees
  else 
   counter = 0;
   
}
