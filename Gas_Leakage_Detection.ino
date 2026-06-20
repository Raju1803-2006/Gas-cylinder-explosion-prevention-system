#include <Servo.h>

// Pin Definitions
#define GAS_SENSOR A0
#define RELAY_PIN 7
#define BUZZER_PIN 8
#define SERVO_PIN 9

const int GAS_THRESHOLD = 800;

Servo gasValveServo;
bool valveClosed = false;

void setup() {
  Serial.begin(9600);

  pinMode(RELAY_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  digitalWrite(RELAY_PIN, LOW);
  digitalWrite(BUZZER_PIN, LOW);

  gasValveServo.attach(SERVO_PIN);
  gasValveServo.write(0);

  Serial.println("Gas Leakage Detection System Started");
}

void loop() {
  int gasValue = analogRead(GAS_SENSOR);

  Serial.print("Gas Sensor Value: ");
  Serial.println(gasValue);

  if (gasValue > GAS_THRESHOLD) {

    Serial.println("WARNING! GAS LEAK DETECTED");

    digitalWrite(RELAY_PIN, HIGH);
    digitalWrite(BUZZER_PIN, HIGH);

    if (!valveClosed) {
      gasValveServo.write(90);
      delay(1000);
      valveClosed = true;

      Serial.println("Cylinder Valve Closed");
    }

  } else {

    digitalWrite(RELAY_PIN, LOW);
    digitalWrite(BUZZER_PIN, LOW);

    Serial.println("Gas Level Normal");
  }

  delay(500);
}
