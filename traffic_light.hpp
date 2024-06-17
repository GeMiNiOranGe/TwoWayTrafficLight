#pragma once
#ifndef TRAFFIC_LIGHT_HPP
#define TRAFFIC_LIGHT_HPP

#include <Arduino.h>

class TrafficLight {
private:
  uint8_t redLedPin;
  uint8_t yellowLedPin;
  uint8_t greenLedPin;

public:
  TrafficLight(uint8_t redLedPin_, uint8_t yellowLedPin_, uint8_t greenLedPin_);
  ~TrafficLight();

  void init();

  void turnOff();
  void turnOnRedLed();
  void turnOnYellowLed();
  void turnOnGreenLed();
};

#endif  // end TRAFFIC_LIGHT_HPP
