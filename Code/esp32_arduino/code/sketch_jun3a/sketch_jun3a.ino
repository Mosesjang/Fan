#define RED_PIN 25
#define GREEN_PIN 26
#define BLUE_PIN 27
#define BUTTON_PIN 13
#define FAN_PIN 14
#define FAN_PIN2 32

int fanState = 0;
int prevButton = HIGH;

void setup() {
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  ledcAttach(FAN_PIN, 25000, 8);
  ledcAttach(FAN_PIN2, 1000, 8);
}

void setColor(int r, int g, int b) {
  digitalWrite(RED_PIN, r);
  digitalWrite(GREEN_PIN, g);
  digitalWrite(BLUE_PIN, b);
}

void loop() {
  int buttonState = digitalRead(BUTTON_PIN);

  if (buttonState == LOW && prevButton == HIGH) {
    fanState++;
    if (fanState > 3) fanState = 0;

    switch (fanState) {
      case 0: // OFF
        ledcWrite(FAN_PIN, 0);
        ledcWrite(FAN_PIN2, 0);
        setColor(LOW, LOW, LOW);
        break;
      case 1: // Speed 1
        ledcWrite(FAN_PIN, 180);
        ledcWrite(FAN_PIN2, 80);
        setColor(HIGH, LOW, LOW); // Red
        break;
      case 2: // Speed 2
        ledcWrite(FAN_PIN, 200);
        ledcWrite(FAN_PIN2, 160);
        setColor(LOW, HIGH, LOW); // Green
        break;
      case 3: // Speed 3
        ledcWrite(FAN_PIN, 255);
        ledcWrite(FAN_PIN2, 255);
        setColor(LOW, LOW, HIGH); // Blue
        break;
    }
  }

  prevButton = buttonState;
  delay(50);
}