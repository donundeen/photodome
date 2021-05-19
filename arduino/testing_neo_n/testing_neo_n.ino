#include <Adafruit_NeoPixel.h>
// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1:
#define LED_PIN    6


// How many NeoPixels are attached to the Arduino?
#define LED_COUNT 320


// Declare our NeoPixel strip object:
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_RGBW + NEO_KHZ800);
// Argument 1 = Number of pixels in NeoPixel strip
// Argument 2 = Arduino pin number (most are valid)
// Argument 3 = Pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
//   NEO_RGBW    Pixels are wired for RGBW bitstream (NeoPixel RGBW products)


int rpin = A0;
int gpin = A1;
int bpin = A2;
int wpin = A3;

int rval = 0;
int gval = 0;
int bval = 0;
int wval = 0;

int minval = 0;
float maxval = 1023.0;

int brightness = 50 ;

float maxColorVal = 255.0;

void setup() {
    Serial.begin(9600);

  // put your setup code here, to run once:
  strip.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  strip.show();            // Turn OFF all pixels ASAP
  strip.setBrightness(brightness); // Set BRIGHTNESS to about 1/5 (max = 255)

}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("loop");
  rval = analogRead(rpin);
  Serial.println(rval);
  float rmult = rval / maxval;
  Serial.println(rmult);
  int rcol = rmult * 255;
  Serial.println(rcol);
  
//  uint32_t color = strip.Color(rcol, rcol, rcol, rcol);
  uint32_t color = strip.Color(0, 0, 0, rcol);
  strip.fill(color, 0, LED_COUNT);
  strip.show();
 /*     
   for(int i=0; i<strip.numPixels(); i++) { // For each pixel in strip...
    strip.setPixelColor(i, color);         //  Set pixel's color (in RAM)
    strip.show();                          //  Update strip to match
                               //  Pause for a moment
  }
  */
  delay(100);
}