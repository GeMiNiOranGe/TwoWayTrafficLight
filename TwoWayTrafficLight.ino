#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcdScreen(0x27, 16, 2);

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

void setup() {
  lcdScreen.init();
  lcdScreen.backlight();

  // pin mode of signal 1
  pinMode(signalOneGreenLedPin, OUTPUT);
  pinMode(signalOneYellowLedPin, OUTPUT);
  pinMode(signalOneRedLedPin, OUTPUT);

  // pin mode of signal 2
  pinMode(signalTwoGreenLedPin, OUTPUT);
  pinMode(signalTwoYellowLedPin, OUTPUT);
  pinMode(signalTwoRedLedPin, OUTPUT);
}

void loop() {
  // signal 1 is turned on
  turnOffAllLed();
  printInforOnLcdSreen("X", "X", "D", "D");
  digitalWrite(signalOneGreenLedPin, HIGH);
  digitalWrite(signalTwoRedLedPin, HIGH);
  delay(greenLedTime);

  printInforOnLcdSreen("V", "V", "D", "D");
  digitalWrite(signalOneGreenLedPin, LOW);
  digitalWrite(signalOneYellowLedPin, HIGH);
  delay(yellowLedTime);

  // signal 2 is turned on
  turnOffAllLed();
  printInforOnLcdSreen("D", "D", "X", "X");
  digitalWrite(signalTwoGreenLedPin, HIGH);
  digitalWrite(signalOneRedLedPin, HIGH);
  delay(greenLedTime);

  printInforOnLcdSreen("D", "D", "V", "V");
  digitalWrite(signalTwoGreenLedPin, LOW);
  digitalWrite(signalTwoYellowLedPin, HIGH);
  delay(yellowLedTime);
}

void printInforOnLcdSreen(String signalA1, String signalA2, String signalB1, String signalB2) {
  lcdScreen.clear();
  lcdScreen.print("A1: " + signalA1 + " - A2: " + signalA2);
  lcdScreen.setCursor(0, 1);
  lcdScreen.print("B1: " + signalB1 + " - B2: " + signalB2);
}

void turnOffAllLed() {
  digitalWrite(signalOneGreenLedPin, LOW);
  digitalWrite(signalOneYellowLedPin, LOW);
  digitalWrite(signalOneRedLedPin, LOW);

  digitalWrite(signalTwoGreenLedPin, LOW);
  digitalWrite(signalTwoYellowLedPin, LOW);
  digitalWrite(signalTwoRedLedPin, LOW);
}
