// Define pins for motor control
int enFL = 10; // Front Left motor enable pin
int in1FL = 7; // Front Left motor input pin 1
int in2FL = 6; // Front Left motor input pin 2

int enFR = 9;  // Front Right motor enable pin
int in1FR = 5; // Front Right motor input pin 1
int in2FR = 4; // Front Right motor input pin 2

int enBL = 3;  // Back Left motor enable pin
int in1BL = 2; // Back Left motor input pin 1
int in2BL = 8; // Back Left motor input pin 2

int enBR = 11; // Back Right motor enable pin
int in1BR = 13;// Back Right motor input pin 1
int in2BR = 12;// Back Right motor input pin 2

// Define variables to store motor speeds
int motorSpeedFL = 0;
int motorSpeedFR = 0;
int motorSpeedBL = 0;
int motorSpeedBR = 0;

// Define function to stop all motors
void stopMotors() {
  motorSpeedFL = 0;
  motorSpeedFR = 0;
  motorSpeedBL = 0;
  motorSpeedBR = 0;
}

void setup() {
  // Initialize pins for motor control
  pinMode(enFL, OUTPUT);
  pinMode(in1FL, OUTPUT);
  pinMode(in2FL, OUTPUT);
  pinMode(enFR, OUTPUT);
  pinMode(in1FR, OUTPUT);
  pinMode(in2FR, OUTPUT);
  pinMode(enBL, OUTPUT);
  pinMode(in1BL, OUTPUT);
  pinMode(in2BL, OUTPUT);
  pinMode(enBR, OUTPUT);
  pinMode(in1BR, OUTPUT);
  pinMode(in2BR, OUTPUT);

  // Start serial communication
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    char command = Serial.read();
    // Move forward
    if (command == 'w') {
      motorSpeedFL = 255;
      motorSpeedFR = 255;
      motorSpeedBL = 255;
      motorSpeedBR = 255;
    }
    // Move backward
    else if (command == 's') {
      motorSpeedFL = -255;
      motorSpeedFR = -255;
      motorSpeedBL = -255;
      motorSpeedBR = -255;
    }
    // Move left
    else if (command == 'a') {
      motorSpeedFL = -255;
      motorSpeedFR = 255;
      motorSpeedBL = -255;
      motorSpeedBR = 255;
    }
    // Move right
    else if (command == 'd') {
      motorSpeedFL = 255;
      motorSpeedFR = -255;
      motorSpeedBL = 255;
      motorSpeedBR = -255;
    }
    // Stop
    else if (command == 'x') {
      stopMotors();
    }
  }
  // Update motor speeds
  analogWrite(enFL, abs(motorSpeedFL));
  analogWrite(enFR, abs(motorSpeedFR));
  analogWrite(enBL, abs(motorSpeedBL));
  analogWrite(enBR, abs(motorSpeedBR));

  // Set motor directions
  digitalWrite(in1FL, motorSpeedFL > 0 ? HIGH : LOW);
  digitalWrite(in2FL, motorSpeedFL > 0 ? LOW : HIGH);
  digitalWrite(in1FR, motorSpeedFR > 0 ? HIGH : LOW);
  digitalWrite(in2FR, motorSpeedFR > 0 ? LOW : HIGH);
  digitalWrite(in1BL, motorSpeedBL > 0 ? HIGH : LOW);
  digitalWrite(in2BL, motorSpeedBL > 0 ? LOW : HIGH);
  digitalWrite(in1BR, motorSpeedBR > 0 ? HIGH : LOW);
  digitalWrite(in2BR, motorSpeedBR > 0 ? LOW : HIGH);
}
