#include <LiquidCrystal_I2C.h>
#include "traffic_light.hpp"

LiquidCrystal_I2C lcdScreen(0x27, 16, 2);

TrafficLight signalOne(PIN2, PIN3, PIN4);
TrafficLight signalTwo(PIN5, PIN6, PIN7);

// led time in millisecond
uint32_t greenLedTime = 7000;
uint32_t yellowLedTime = 3000;

void setup() {
  lcdScreen.init();
  lcdScreen.backlight();

  signalOne.init();
  signalTwo.init();
}

void loop() {
  // signal 1 is turned on
  signalOne.turnOff();
  signalTwo.turnOff();
  printInforOnLcdSreen("X", "D");
  signalOne.turnOnGreenLed();
  signalTwo.turnOnRedLed();
  delay(greenLedTime);

  printInforOnLcdSreen("V", "D");
  signalOne.turnOnYellowLed();
  delay(yellowLedTime);

  // signal 2 is turned on
  signalOne.turnOff();
  signalTwo.turnOff();
  printInforOnLcdSreen("D", "X");
  signalTwo.turnOnGreenLed();
  signalOne.turnOnRedLed();
  delay(greenLedTime);

  printInforOnLcdSreen("D", "V");
  signalTwo.turnOnYellowLed();
  delay(yellowLedTime);
}

void printInforOnLcdSreen(String signalOne, String signalTwo) {
  lcdScreen.clear();
  lcdScreen.print("A1: " + signalOne + " - A2: " + signalOne);
  lcdScreen.setCursor(0, 1);
  lcdScreen.print("B1: " + signalTwo + " - B2: " + signalTwo);
}
