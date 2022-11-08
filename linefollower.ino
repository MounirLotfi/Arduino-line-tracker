#include <LiquidCrystal.h> // libary for the lcd

const int rs = 31, en = 30, d4 = 33, d5 = 22, d6 = 24, d7 = 26;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

#define motorRight1 50
#define motorRight2 51
#define motorLeft1 52
#define motorLeft2 53
#define speedRight A15
#define speedLeft A14

//motorRight1 = LOW && motorRight2 = HIGH --> forward 
//motorRight1 = HIGH && motorRight2 = LOW --> backward
//motorLeft1 = LOW && motorLeft2 = HIGH --> forward 
//motorLeft1 = HIGH && motorLeft2 = LOW --> backward
  // line tracker sensors
  int sensor1;
  int sensor2;
  int sensor3;
  int sensor4;
  int sensor5;
  // ultrasonic duration and distance 
  long durationRight;
  int distanceRight;
  long durationMiddle;
  int distanceMiddle;
  long durationLeft;
  int distanceLeft;
  
void setup() {

  Serial.begin(9600);

  lcd.begin(16, 4);

  lcd.println("Mounir Lotfi    ");
  lcd.setCursor(0,1);
  lcd.println("18101938        ");
  lcd.setCursor(0,2);
  lcd.println("Ghada Aslan     ");
  lcd.setCursor(0,3);
  lcd.println("18100651        ");
  
  //3 ultrasonic sensors.
  pinMode(6, INPUT); // echoPin left
  pinMode(7, OUTPUT); // trigPin left
  pinMode(8, INPUT); // echoPin middle
  pinMode(9, OUTPUT); // trigPin middle
  pinMode(10, INPUT); // echoPin right
  pinMode(11, OUTPUT); // trigPin right


  // Line Tracker 5 Channels.
  pinMode(17,INPUT); // S1 Extrem Left
  pinMode(18,INPUT); // S2 Left
  pinMode(19,INPUT); // S3 Middle
  pinMode(20,INPUT); // S4 Right
  pinMode(21,INPUT); // S5 Extrem Right

  //motors
  pinMode(50, OUTPUT); //right motor 1
  pinMode(51, OUTPUT); //right motor 2
  pinMode(A15, OUTPUT); //pwm right
  pinMode(52, OUTPUT); //left motor 1
  pinMode(53, OUTPUT); //left motor 2
  pinMode(A14, OUTPUT); //pwm left
}

void loop() {
  
  sensor1 = digitalRead(17); //sensor1
  sensor2 = digitalRead(18); //sensor2
  sensor3 = digitalRead(19); //sensor3
  sensor4 = digitalRead(20); //sensor4
  sensor5 = digitalRead(21); //sensor5

  //Ulttasonic
  digitalWrite(11, LOW);
  delayMicroseconds(2);
  digitalWrite(11, HIGH);
  delayMicroseconds(10);
  digitalWrite(11, LOW);
  durationRight = pulseIn(10, HIGH);
  distanceRight = durationRight*0.034/2;

  digitalWrite(9, LOW);
  delayMicroseconds(2);
  digitalWrite(9, HIGH);
  delayMicroseconds(10);
  digitalWrite(9, LOW);
  durationMiddle = pulseIn(8, HIGH);
  distanceMiddle = durationMiddle*0.034/2;

  digitalWrite(7, LOW);
  delayMicroseconds(2);
  digitalWrite(7, HIGH);
  delayMicroseconds(10);
  digitalWrite(7, LOW);
  durationLeft = pulseIn(6, HIGH);
  distanceLeft = durationLeft*0.034/2;
  //moving according to line tracking sensor
  if((sensor3 == HIGH) && (sensor4 == LOW) && (sensor5 == LOW) && (sensor1 == LOW)&& (sensor2 == LOW))
  {
    Serial.println(0);
    digitalWrite(50, LOW);
    digitalWrite(51, HIGH);
    digitalWrite(52, LOW);
    digitalWrite(53, HIGH);

    analogWrite(A15, 255);
    analogWrite(A14, 255);
  }
  else if((sensor3 == HIGH) && (sensor4 == HIGH) && (sensor5 == HIGH) && (sensor1 == HIGH)&& (sensor2 == HIGH))
  {
    Serial.println(9);
    

    analogWrite(A14, 0);
    analogWrite(A15, 0);
    }
    else if((sensor3 == HIGH) && (sensor1 == HIGH) && (sensor4 == LOW) && (sensor5 == LOW)&& (sensor2 == HIGH))
    {
      Serial.println(18);
      digitalWrite(50, LOW);
      digitalWrite(51, HIGH);
      digitalWrite(52, HIGH);
      digitalWrite(53, LOW);

      analogWrite(A15, 255);
      analogWrite(A14, 255);
      }
      else if((sensor3 == HIGH) && (sensor4 == HIGH) && (sensor5 == HIGH) && (sensor1 == LOW)&& (sensor2 == LOW))
      {
        Serial.println(27);
        digitalWrite(50, HIGH);
        digitalWrite(51, LOW);
        digitalWrite(52, LOW);
        digitalWrite(53, HIGH);

        analogWrite(A15, 255);
        analogWrite(A14, 255);
        }
        else if((sensor3 == LOW) && (sensor4 == LOW) && (sensor5 == LOW) && (sensor1 == LOW)&& (sensor2 == LOW))
        {
          Serial.println(36);
          digitalWrite(50, LOW);
          digitalWrite(51, HIGH);
          digitalWrite(52, LOW);
          digitalWrite(53, HIGH);

          analogWrite(A15, 255);
          analogWrite(A14, 255);
          }


//ultraasonic sensor

if(distanceMiddle <= 7)
  {
    Serial.println(7);
    
    analogWrite(A15, 0);
    analogWrite(A14, 0);
    
    
    if(distanceRight >= 7)
    {
      Serial.println(7);

      digitalWrite(50, HIGH);
      digitalWrite(51, LOW);
      digitalWrite(52, LOW);
      digitalWrite(53, HIGH);

      analogWrite(A15, 255);
      analogWrite(A14, 255);
      }
      else if(distanceLeft >= 7)
      {
        Serial.println(14);

        digitalWrite(50, LOW);
        digitalWrite(51, HIGH);
        digitalWrite(52, HIGH);
        digitalWrite(53, LOW);

        analogWrite(A15, 100);
        analogWrite(A14, 100);
        }
    }
    else
    {
      Serial.println(21);
      
      digitalWrite(50, LOW);
      digitalWrite(51, HIGH);
      digitalWrite(52, LOW);
      digitalWrite(53, HIGH);

      analogWrite(A15, 100);
      analogWrite(A14, 100);
      }

      

}
