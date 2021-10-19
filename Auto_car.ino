#include <Ultrasonic.h>
#include <Servo.h>

Ultrasonic u = Ultrasonic(3, 4); //trig,eco
Servo s = Servo();

int ENA = 11;
int IN1 = 10;
int IN2 = 9;

int IN3 = 7;
int IN4 = 6;
int ENB = 5;


void setup() {
  // put your setup code here, to run once:

  s.attach(2); //servo

  // Mortor A
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);


  // Mortor B
  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);





}

void loop() {
  // put your main code here, to run repeatedly:

  s.write(90); //morter ek kohe thiibunath 90 deg ennona
  delay(300);
  int d = u.read(); // distanceRead

  if (d > 15) {
    analogWrite(ENA, 150);
    analogWrite(ENB, 150);

    digitalWrite(IN1, LOW);//Mortor A Forword
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, LOW);//Mortor B Forword
    digitalWrite(IN4, HIGH);
    delay(100);
    digitalWrite(IN1, LOW);//Mortor Stop
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
    delay(100);
  }

  else {

    s.write(60); //mortor turn right
    delay(1000);
    int d = u.read(); // distanceRead

    if (d > 15) {
      analogWrite(ENA, 200);
      analogWrite(ENB, 200);

      digitalWrite(IN1, LOW);//Mortor A Forword
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, HIGH);//Mortor B Reverse
      digitalWrite(IN4, LOW);
      delay(200);
      digitalWrite(IN1, LOW);//Mortor Stop
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, LOW);

      s.write(90); //mortor 90deg
      delay(300);
    }

    else {

      s.write(120); //mortor turn left
      delay(1000);
      int d = u.read(); // distanceRead

      if (d > 15) {
        analogWrite(ENA, 200);
        analogWrite(ENB, 200);

        digitalWrite(IN1, HIGH);//Mortor A Reverse
        digitalWrite(IN2, LOW);
        digitalWrite(IN3, LOW);//Mortor B Forword
        digitalWrite(IN4, HIGH);
        delay(200);
        digitalWrite(IN1, LOW);//Mortor Stop
        digitalWrite(IN2, LOW);
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, LOW);

        s.write(90); //mortor 90deg
        delay(300);
      }


      else {
        analogWrite(ENA, 200);
        analogWrite(ENB, 200);

        digitalWrite(IN1, HIGH);//Mortor A REVERSE
        digitalWrite(IN2, LOW);
        digitalWrite(IN3, LOW);//Mortor B REVERSE
        digitalWrite(IN4, HIGH);
        delay(300);
        digitalWrite(IN1, LOW);//Mortor Stop
        digitalWrite(IN2, LOW);
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, LOW);
        delay(300);
        digitalWrite(IN1, HIGH);//Mortor A Reverse
        digitalWrite(IN2, LOW);
        digitalWrite(IN3, LOW);//Mortor B Forword
        digitalWrite(IN4, HIGH);
        delay(200);
        digitalWrite(IN1, LOW);//Mortor Stop
        digitalWrite(IN2, LOW);
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, LOW);

      }
    }

  }
}
