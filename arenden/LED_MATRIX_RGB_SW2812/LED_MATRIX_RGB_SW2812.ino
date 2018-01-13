#include "FastLED.h"

#define NUM_LEDS 120
CRGB leds[NUM_LEDS];

void setup()
{
  //FastLED.addLeds<WS2812, 1, GRB>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
  FastLED.addLeds<WS2812, 2, GRB>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
  //FastLED.addLeds<WS2812, 3, GRB>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
  //FastLED.addLeds<WS2812, 4, GRB>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
  //FastLED.addLeds<WS2812, 5, GRB>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
  //FastLED.addLeds<WS2812, 6, GRB>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
  //FastLED.addLeds<WS2812, 7, GRB>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
  
}


void loop() {
  FadeInOutRGD();
  FadeInOutOneColor(0x00, 0x00, 0xff); // Green(0x00)
  FadeInOutOneColor(0x00, 0x00, 0xff); // Green(0x00)
  FadeInOutOneColor(0x00, 0x00, 0xff); // Green(0x00)
  FadeInOutOneColor(0x00, 0x7d, 0xff); // Green(0x00)
  FadeInOutOneColor(0x00, 0x2d, 0xff); // Green(0x00)
  Strobe(0x40, 0x40, 0x40, 10, 40, 1000); //Fast (Red(0x40), Green(0x40), Blue(0x40), Strobe count(10), Flash Delay,(100), End Pause(1000))
  Strobe(0x40, 0x40, 0x40, 10, 100, 1000); //Slow (Red(0x40), Green(0x40), Blue(0x40), Strobe count(10), Flash Delay,(100), End Pause(1000))
  KnightRider(0xff, 0, 0, 10, 0, 50); // (Red(0xff), Green(0), Blue(0), Size(60), Speed(990), Returndelay(50))
  Twinkle(0xff, 0, 0, 10, 50, false); // (Red(0xff), Green(0), Blue(0), Count(10), Speed(8756550), One(false))
  //TwinkleRandom(50, 100, false); // Random color (Count(50000), Speed(100), One(false))
  //Sparkle(0xff, 0xff, 0xff, 0); //White (Red(0xff), Green(0xff), Blue(0xff), Speed(0))
  //Sparkle(random(255), random(255), random(255), 0); // Random color (Red(255), Green(255), Blue(255), Speed(0))
  //SnowSparkle(0x10, 0x10, 0x10, 20, random(100,1000)); // (Red(0x10), Green(0x10), Blue(0x10), SparkleDelay(20), Random(100,1000))
  //RunningLights(0xff,0xff,0x00, 50); // (Red(0xff), Green(0xff), Blue(0x00), Speed(50))
  colorWipe(0x00,0xff,0x00, 1); // LED`s ON  Green(0xff),  Speed(1))
  colorWipe(0xff,0x00,0x00, 1); // LED`s ON  Green(0xff),  Speed(1))
  //colorWipe(0x00,0x00,0xff, 1); // LED`s ON Green(0xff),  Speed(1))
  //colorWipe(0x00,0x00,0x00, 1); // LED`s OFF Green(0x00),  Speed(1))
  //rainbowCycle(20); // (Speed(20))
  //theaterChase(0xff,0,0,50); // One Color Green(0), Speed(50))
  //theaterChaseRainbow(50); // Rainbow (Speed(5000))
  //Fire(40,120,15); // (Cooling(40), Sparking(120), Delay(15))
  //BouncingBalls(0xff,0,0, 3); // (Red(0xff), Green, Blue, Bal count(3))  
}

void showStrip() {
 #ifdef ADAFRUIT_NEOPIXEL_H
   // NeoPixel
   strip.show();
 #endif
 #ifndef ADAFRUIT_NEOPIXEL_H
   // FastLED
   FastLED.show();
 #endif
}

void setPixel(int Pixel, byte red, byte green, byte blue) {
 #ifdef ADAFRUIT_NEOPIXEL_H
   // NeoPixel
   strip.setPixelColor(Pixel, strip.Color(red, green, blue));
 #endif
 #ifndef ADAFRUIT_NEOPIXEL_H
   // FastLED
   leds[Pixel].r = red;
   leds[Pixel].g = green;
   leds[Pixel].b = blue;
 #endif
}

void setAll(byte red, byte green, byte blue) {
  for(int i = 0; i < NUM_LEDS; i++ ) {
    setPixel(i, red, green, blue);
  }
  showStrip();
}
