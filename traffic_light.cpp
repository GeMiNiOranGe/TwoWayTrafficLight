#include "traffic_light.hpp"

TrafficLight::TrafficLight(uint8_t redLedPin_, uint8_t yellowLedPin_, uint8_t greenLedPin_) {
  this->redLedPin = redLedPin_;
  this->yellowLedPin = yellowLedPin_;
  this->greenLedPin = greenLedPin_;
}

TrafficLight::~TrafficLight() {
}

void TrafficLight::init() {
  pinMode(this->redLedPin, OUTPUT);
  pinMode(this->yellowLedPin, OUTPUT);
  pinMode(this->greenLedPin, OUTPUT);
}

void TrafficLight::turnOff() {
  digitalWrite(this->redLedPin, LOW);
  digitalWrite(this->yellowLedPin, LOW);
  digitalWrite(this->greenLedPin, LOW);
}

void TrafficLight::turnOnRedLed() {
  digitalWrite(this->redLedPin, HIGH);
  digitalWrite(this->yellowLedPin, LOW);
  digitalWrite(this->greenLedPin, LOW);
}

void TrafficLight::turnOnYellowLed() {
  digitalWrite(this->redLedPin, LOW);
  digitalWrite(this->yellowLedPin, HIGH);
  digitalWrite(this->greenLedPin, LOW);
}

void TrafficLight::turnOnGreenLed() {
  digitalWrite(this->redLedPin, LOW);
  digitalWrite(this->yellowLedPin, LOW);
  digitalWrite(this->greenLedPin, HIGH);
}
