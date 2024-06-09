// signal 1
uint8_t signalOneRedLedPin = PIN2;
uint8_t signalOneYellowLedPin = PIN3;
uint8_t signalOneGreenLedPin = PIN4;

// signal 2
uint8_t signalTwoRedLedPin = PIN5;
uint8_t signalTwoYellowLedPin = PIN6;
uint8_t signalTwoGreenLedPin = PIN7;

// led time in millisecond
uint32_t greenLedTime = 7000;
uint32_t yellowLedTime = 3000;
uint32_t redLedTime = greenLedTime + yellowLedTime;

// constant value
const uint32_t LED_INTERVAL_TIME = 1000;

void setup() {
  // pin mode of signal 1
  pinMode(signalOneGreenLedPin, OUTPUT);
  pinMode(signalOneYellowLedPin, OUTPUT);
  pinMode(signalOneRedLedPin, OUTPUT);

  // pin mode of signal 2
  pinMode(signalTwoGreenLedPin, OUTPUT);
  pinMode(signalTwoYellowLedPin, OUTPUT);
  pinMode(signalTwoRedLedPin, OUTPUT);

  Serial.begin(9600);
  Serial.println(redLedTime);
}

void loop() {
  // signal 1 is turned on
  turnOffAllLed();
  digitalWrite(signalOneGreenLedPin, HIGH);
  digitalWrite(signalTwoRedLedPin, HIGH);
  delay(greenLedTime);

  digitalWrite(signalOneGreenLedPin, LOW);
  digitalWrite(signalOneYellowLedPin, HIGH);
  delay(yellowLedTime);

  // // signal 2 is turned on
  turnOffAllLed();
  digitalWrite(signalTwoGreenLedPin, HIGH);
  digitalWrite(signalOneRedLedPin, HIGH);
  delay(greenLedTime);

  digitalWrite(signalTwoGreenLedPin, LOW);
  digitalWrite(signalTwoYellowLedPin, HIGH);
  delay(yellowLedTime);
}

void turnOffAllLed() {
  digitalWrite(signalOneGreenLedPin, LOW);
  digitalWrite(signalOneYellowLedPin, LOW);
  digitalWrite(signalOneRedLedPin, LOW);

  digitalWrite(signalTwoGreenLedPin, LOW);
  digitalWrite(signalTwoYellowLedPin, LOW);
  digitalWrite(signalTwoRedLedPin, LOW);
}
