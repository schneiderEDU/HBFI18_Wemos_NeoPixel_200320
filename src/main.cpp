#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

#define LED_PIN D4
#define LED_NUM 7

const unsigned int TIME_WAIT = 200;

Adafruit_NeoPixel led(LED_NUM, LED_PIN, NEO_GRB + NEO_KHZ800);

uint32_t black   = led.Color(0, 0, 0);
uint32_t red10   = led.Color(25, 0, 0);
uint32_t green10 = led.Color(0, 25, 0);
uint32_t blue10  = led.Color(0, 0, 25);

unsigned long millis_current;
unsigned long millis_previous = 0;

int led_current = 1;

void setup() {
  led.begin();
  for(int i = 0; i < LED_NUM; i++) {
    led.setPixelColor(i, black);
  }
  led.show();
}

void loop() {
  millis_current = millis();
  if(millis_current - millis_previous >= TIME_WAIT) {
    led.setPixelColor(led_current, red10);
    led.show();
    led.setPixelColor(led_current, black);
    led_current++;
    if(led_current >= LED_NUM) led_current = 1;
    millis_previous = millis_current;
  }
}