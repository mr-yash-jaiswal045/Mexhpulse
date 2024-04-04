int enA = 10;
int in1 = 7;
int in2 = 6;

int enB = 9;
int in3 = 5;
int in4 = 4;

int enC = 3;
int in5 = 2;
int in6 = 8;

int enD = 11;
int in7 = 13;
int in8 = 12;

void setup() {
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  
  pinMode(enB, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  
  pinMode(enC, OUTPUT);
  pinMode(in5, OUTPUT);
  pinMode(in6, OUTPUT);
  
  pinMode(enD, OUTPUT);
  pinMode(in7, OUTPUT);
  pinMode(in8, OUTPUT);
}

void loop() {
  //Stage 1 – 100% speed for all motors
  analogWrite(enA, 255);
  analogWrite(enB, 255);
  analogWrite(enC, 255);
  analogWrite(enD, 255);
  
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  digitalWrite(in5, HIGH);
  digitalWrite(in6, LOW);
  digitalWrite(in7, HIGH);
  digitalWrite(in8, LOW);
  
  delay(5000);
  
  //Stage 2 – 70% speed for all motors
  analogWrite(enA, 0.7 * 255);
  analogWrite(enB, 0.7 * 255);
  analogWrite(enC, 0.7 * 255);
  analogWrite(enD, 0.7 * 255);
  
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  digitalWrite(in5, HIGH);
  digitalWrite(in6, LOW);
  digitalWrite(in7, HIGH);
  digitalWrite(in8, LOW);
  
  delay(5000);
  
  //Stage 3 – 100% speed for all motors reversing the direction
  analogWrite(enA, 255);
  analogWrite(enB, 255);
  analogWrite(enC, 255);
  analogWrite(enD, 255);
  
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  digitalWrite(in5, LOW);
  digitalWrite(in6, HIGH);
  digitalWrite(in7, LOW);
  digitalWrite(in8, HIGH);
  
  delay(5000);
  
  //Stage 4 – 70% speed for all motors in reverse
  analogWrite(enA, 0.7 * 255);
  analogWrite(enB, 0.7 * 255);
  analogWrite(enC, 0.7 * 255);
  analogWrite(enD, 0.7 * 255);
  
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  digitalWrite(in5, LOW);
  digitalWrite(in6, HIGH);
  digitalWrite(in7, LOW);
  digitalWrite(in8, HIGH);
  
  delay(5000);
}
