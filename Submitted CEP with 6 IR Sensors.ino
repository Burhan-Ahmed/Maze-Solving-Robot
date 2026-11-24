//Motor one
#define ENA 6
#define IN1 7
#define IN2 8

//Motor two
#define IN3 9
#define IN4 10
#define ENB 11

#define Speed 160

void setup() {
  //setting Baud Rate
  Serial.begin(9600);
  //Sensor pins
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  pinMode(12, INPUT);
  pinMode(13, INPUT);
  //Motor one
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  //Motor two
  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

}
void loop() {
  int left_most = digitalRead(2); // Read analog sensor value
  int left = digitalRead(3);
  int center = digitalRead(12);
  int upper_center = digitalRead(13);
  int right = digitalRead(4);
  int right_most = digitalRead(5);
  Serial.print("Left Most = ");     // Print label
  Serial.print(left_most);          // Print sensor value
  Serial.print(", Left = ");        // Print label
  Serial.print(left);               // Print sensor value
  Serial.print(", Center = ");      // Print label
  Serial.print(center);             // Print sensor value
  Serial.print(", Upper Center = ");// Print label
  Serial.print(upper_center);       // Print sensor value
  Serial.print(", Right = ");       // Print label
  Serial.print(right);              // Print sensor value
  Serial.print(", Right Most = ");  // Print label
  Serial.println(right_most);

  bool SOne = digitalRead(2); //dis
  bool STwo = digitalRead(3);
  bool SThree = digitalRead(4);
  bool SFour = digitalRead(5); //dis
  bool SFive = digitalRead(12);
   bool Upper = digitalRead(13);

  if (SOne==HIGH && STwo == HIGH && SFive == LOW && SThree == HIGH && SFour==HIGH)//Straight path
    {
     forward();
    }

  if (SOne==HIGH && STwo == HIGH  && SFive == HIGH && SThree == LOW && (SThree == LOW || SFour==LOW))//Left turn
    {
     turnleft();
    }

  if ((SOne==LOW || STwo == LOW) && STwo == LOW && SFive == HIGH && SThree == HIGH && SFour==HIGH)//Right Turn
    {
      turnright();
    }

  if (SOne==LOW && STwo == LOW && SFive == LOW && SThree == LOW && SFour==LOW)//T or + Cross Intersection
    {
      turnleft(); // As left is possible
    }

  if (SOne == LOW && STwo == LOW && SFive == LOW && SThree == HIGH && SFour==HIGH)//Right T Tntersection
    {
     forward();//As Straight path is possible
    }
  if (SOne==HIGH && STwo == HIGH && SFive ==HIGH && SThree == HIGH  && SFour==HIGH)//Dead End
    {
      turnleft();
    // U_Turn(); //As no other direction is possible
    }

  if (SOne==LOW && STwo == LOW && SFive == LOW && SThree == LOW && SFour==LOW)//4 Lane intersection
    {
     turnleft(); //As no other direction is possible
      //Stop();
    }

   if (SOne==LOW && STwo == LOW && SFive == LOW && Upper==LOW && SThree == LOW && SFour==LOW)
    {
      Stop();
    }
}

void forward() {
  analogWrite(ENA, Speed);
  analogWrite(ENB, Speed);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}
void turnright() {
  analogWrite(ENA, Speed);
  analogWrite(ENB, Speed);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}
void turnleft() {
  analogWrite(ENA, Speed);
  analogWrite(ENB, Speed);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void Stop() {
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
