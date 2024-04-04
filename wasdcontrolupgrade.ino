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

unsigned long movementStartTime = 0;

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
  
  Serial.begin(9600); // Start serial communication
}

void loop() {
  // Empty loop as we handle key presses in keyPressed() and keyReleased() functions
}

void keyPressed() {
  char key = key;
  
  if (key == 'w') {
    moveForward();
  } else if (key == 'a') {
    moveLeft();
  } else if (key == 's') {
    moveBackward();
  } else if (key == 'd') {
    moveRight();
  }
}

void keyReleased() {
  stopMotors();
}

void stopMotors() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  digitalWrite(in5, LOW);
  digitalWrite(in6, LOW);
  digitalWrite(in7, LOW);
  digitalWrite(in8, LOW);
}

void moveForward() {
  // Set motor speeds for forward movement
  analogWrite(enA, 0.2 * 255); // 20% speed
  analogWrite(enB, 0.2 * 255); // 20% speed
  analogWrite(enC, 0.2 * 255); // 20% speed
  analogWrite(enD, 0.2 * 255); // 20% speed
  
  // Set motor direction for forward movement
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  digitalWrite(in5, HIGH);
  digitalWrite(in6, LOW);
  digitalWrite(in7, HIGH);
  digitalWrite(in8, LOW);
}

void moveBackward() {
  // Set motor speeds for backward movement
  analogWrite(enA, 0.2 * 255); // 20% speed
  analogWrite(enB, 0.2 * 255); // 20% speed
  analogWrite(enC, 0.2 * 255); // 20% speed
  analogWrite(enD, 0.2 * 255); // 20% speed
  
  // Set motor direction for backward movement
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  digitalWrite(in5, LOW);
  digitalWrite(in6, HIGH);
  digitalWrite(in7, LOW);
  digitalWrite(in8, HIGH);
}

void moveLeft() {
  // Set motor speeds for leftward movement
  analogWrite(enA, 0.2 * 255); // 20% speed
  analogWrite(enB, 0.2 * 255); // 20% speed
  analogWrite(enC, 0.2 * 255); // 20% speed
  analogWrite(enD, 0.2 * 255); // 20% speed
  
  // Set motor direction for leftward movement
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  digitalWrite(in5, LOW);
  digitalWrite(in6, HIGH);
  digitalWrite(in7, HIGH);
  digitalWrite(in8, LOW);
}

void moveRight() {
  // Set motor speeds for rightward movement
  analogWrite(enA, 0.2 * 255); // 20% speed
  analogWrite(enB, 0.2 * 255); // 20% speed
  analogWrite(enC, 0.2 * 255); // 20% speed
  analogWrite(enD, 0.2 * 255); // 20% speed
  
  // Set motor direction for rightward movement
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  digitalWrite(in5, HIGH);
  digitalWrite(in6, LOW);
  digitalWrite(in7, LOW);
  digitalWrite(in8, HIGH);
}
