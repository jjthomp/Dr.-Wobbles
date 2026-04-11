// Pin assignments
const int motorPin  = A1;  // DAC-capable true analog output
const int leftPin   = A2;  // Switch left position (LOW_SPEED)
const int rightPin  = A3;  // Switch right position (HIGH_SPEED)

// Motor settings
const int LOW_INTENSITY      = 120;
const int HIGH_INTENSITY     = 255;
const int KICKSTART_DURATION = 100;
const int DEBOUNCE_DELAY     = 200;

// State
enum MotorState { MOTOR_OFF, LOW_SPEED, HIGH_SPEED };
MotorState currentState = MOTOR_OFF;

bool lastLeftState  = HIGH;
bool lastRightState = HIGH;

void kickstart() {
  analogWrite(motorPin, 255);
  Serial.println("Kickstarting motor...");
  delay(KICKSTART_DURATION);
}

void applyMotorState() {
  switch (currentState) {
    case MOTOR_OFF:
      analogWrite(motorPin, 0);
      Serial.println("Motor: OFF");
      break;
    case LOW_SPEED:
      kickstart();
      analogWrite(motorPin, LOW_INTENSITY);
      Serial.println("Motor: LOW");
      break;
    case HIGH_SPEED:
      kickstart();
      analogWrite(motorPin, HIGH_INTENSITY);
      Serial.println("Motor: HIGH");
      break;
  }
}

void setup() {
  Serial.begin(115200);
  pinMode(motorPin,  OUTPUT);
  pinMode(leftPin,   INPUT_PULLUP);  // Switch COM → GND
  pinMode(rightPin,  INPUT_PULLUP);  // Switch COM → GND
  analogWrite(motorPin, 0);
  Serial.println("Setup done!");
}

void loop() {
  bool leftRead  = digitalRead(leftPin);
  bool rightRead = digitalRead(rightPin);

  // Temporary debug — add this
  Serial.print("Left: "); Serial.print(leftRead);
  Serial.print(" | Right: "); Serial.println(rightRead);
  delay(100);
  
  // ... rest of your loop
  // Middle position — both HIGH (floating with pullup) → OFF
  if (leftRead == HIGH && rightRead == HIGH) {
    if (currentState != MOTOR_OFF) {
      currentState = MOTOR_OFF;
      applyMotorState();
    }
  }

  // Left pressed → LOW_SPEED
  if (lastLeftState == HIGH && leftRead == LOW) {
    currentState = LOW_SPEED;
    applyMotorState();
    delay(DEBOUNCE_DELAY);
  }

  // Right pressed → HIGH_SPEED
  if (lastRightState == HIGH && rightRead == LOW) {
    currentState = HIGH_SPEED;
    applyMotorState();
    delay(DEBOUNCE_DELAY);
  }

  lastLeftState  = leftRead;
  lastRightState = rightRead;
}
