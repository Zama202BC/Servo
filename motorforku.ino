#include <Servo.h>

Servo myServo;

int buttPin = 2;
int buttSt = 0;
int const potPin = A0;
int potVal;
int angle;
int redl = 13;
int bluel = 12;
int greenl = 11;


void setup() {
  myServo.attach(9);
  Serial.begin(9600);
  pinMode(redl, OUTPUT);
  pinMode(bluel, OUTPUT);
  pinMode(greenl, OUTPUT);
  pinMode(buttPin, INPUT);
  pinMode(7,OUTPUT);
}

void loop() {
  printStuff();
  
 
  myServo.write(angle);
  buttSt =  digitalRead(buttPin);
 digitalWrite(7,HIGH);
  if (buttSt == HIGH){
    button();
  }

 if (buttSt == LOW){
    potVal = analogRead(potPin);
      angle = map(potVal, 0, 1023, 0, 179);
  }
  if (angle > 160) {
    digitalWrite(redl, HIGH);
  }

  else if (angle < 160) {
    digitalWrite(redl, LOW);
  }

  if (angle > 10) {
    digitalWrite(greenl, LOW);
  }

  else if (angle < 10) {
    digitalWrite(greenl, HIGH);
  }

  if (angle < 160 && angle > 10) {
    digitalWrite(bluel, HIGH);
  }
  else if (angle > 160) {
    digitalWrite(bluel, LOW);
  }
  
 else if (angle < 10) {
    digitalWrite(bluel, LOW);
 }


}

void button(){
 
if (potVal < 900){
  angle = 179;
}


else if (potVal > 900){
 
  angle = 0;
}
}



void printStuff(){
   Serial.print("potVal: ");
  Serial.print(potVal);

  Serial.print(", angle: ");
  Serial.println(angle);
}
