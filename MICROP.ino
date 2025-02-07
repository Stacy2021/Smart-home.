#include <Arduino.h>
#include <WiFi.h>
#include "SinricPro.h"
#include "SinricProSwitch.h"
#include <map>



#include <pinouts.h>
#include <setup.h>

void setup(){
    Serial.begin(BAUD_RATE); //serial monitor baud rate set to 115200
      pinMode(wifiLed, OUTPUT);  //the in-built led is used to show connection to wifi. 
  digitalWrite(wifiLed, LOW);  //the led is set to low at startup
  setupRelays();
   
  setupSwitches();
  setupWiFi();
  setupSinricPro();
}


void loop(){

  SinricPro.handle();
  handleFlipSwitches();

}
