#include <SoftwareSerial.h>

SoftwareSerial BT(D5, D6); // RX, TX

// Motor Driver Pins
int IN1 = D1;
int IN2 = D2;
int IN3 = D3;
int IN4 = D4;

// Speaker/Buzzer Pin
int speaker = D7;

void setup() {
  Serial.begin(9600);
  BT.begin(9600);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  pinMode(speaker, OUTPUT);
}

void loop() {
  if (BT.available()) {
    char cmd = BT.read();

    switch (cmd) {
      case 'F': // Forward
        forward();
        break;

      case 'B': // Backward
        backward();
        break;

      case 'L': // Left
        left();
        break;

      case 'R': // Right
        right();
        break;

      case 'S': // Stop
        stopRobot();
        break;

      case 'T': // Talk
        tone(speaker, 1000, 500);
        break;
    }
  }
}

void forward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void backward() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void left() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void right() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void stopRobot() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
