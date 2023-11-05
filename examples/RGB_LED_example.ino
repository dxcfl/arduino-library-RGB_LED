// Example testing sketch for RGB LEDs
// Written by dxcfl, public domain

// REQUIRES the following Arduino library:
// - RGB LED Library: https://github.com/dxcfl/arduino-library-RGB_LED

#include "RGB_LED.h"

#define RGB_LED_RED_PIN 31       
#define RGB_LED_GREEN_PIN 32       
#define RGB_LED_BLUE_PIN 33      

RGB_LED rgb_led(RGB_LED_RED_PIN,RGB_LED_GREEN_PIN,RGB_LED_BLUE_PIN);

void setup() {
  Serial.begin(9600);
  Serial.println(F("RGB LED test!"));
  rgb_led.begin();
}

void loop() {
  Serial.println(F("Blink red ..."));
  rgb_led.setOn();
  rgb_led.setColor(RGB_LED::COLOR_RED); 
  for (int i = 0; i < 10; i++) {
    rgb_led.toggle();
    delay(500);  
  }
  rgb_led.setOff();
  delay(1000);

  Serial.println(F("Rise into green ..."));
  rgb_led.setOn(); 
  rgb_led.setColor(RGB_LED::COLOR_GREEN); 
  for (float b = 1.0 ; b > 0; b -= 0.1 ) {
    rgb_led.setBrightness(1-b);
    delay(500);
  }
  delay(1000);

  Serial.println(F("Fade from blue ..."));
  rgb_led.setColor(RGB_LED::COLOR_BLUE);
  for (float b = 1.0 ; b > 0; b -= 0.1 ) {
    rgb_led.setBrightness(b);
    delay(500);
  }
  delay(1000);

  Serial.println(F("Flash bright white ..."));
  rgb_led.setBrightness(1.0);
  rgb_led.setColor(RGB_LED::COLOR_WHITE);
  for (int i = 0; i < 5; i++) {
    rgb_led.toggle();
    delay(100);  
  } 

  rgb_led.setOn();
  Serial.println(F("Dim orange ..."));
  rgb_led.setBrightness(0.33);
  rgb_led.setColor(RGB_LED::COLOR_ORANGE);
  delay(1000);

  Serial.println(F("Lighter purple ..."));
  rgb_led.setBrightness(0.8);
  rgb_led.setColor(RGB_LED::COLOR_PURPLE);
  delay(1000);

  Serial.println(F("Bright yellow ..."));
  rgb_led.setBrightness(1.0);
  rgb_led.setColor(RGB_LED::COLOR_YELLOW);
  delay(1000);
  
  rgb_led.setOff();
  delay(1000);
}
