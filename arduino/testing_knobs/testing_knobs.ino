int rpin = A0;
int gpin = A1;
int bpin = A2;
int wpin = A3;

int rval = 0;
int gval = 0;
int bval = 0;
int wval = 0;

int minval = 0;
int maxval = 1023;

int maxColorVal = 255;

/*
 * 60 LEDS/m
 * spool: 4m
 * per arc = 4/3 = 1.33m
 * 1.33 * 60 = 80
 * max draw: 60ma/pixel
 * 80 NeoPixels × 60 mA ÷ 1,000 = 4.8 Amps minimum
 * 
 * full spool: 240pixel
 * 240 NeoPixels × 60 mA ÷ 1,000 = 14.4 Amps minimum
 * 240 NeoPixels × 20 mA ÷ 1,000 = 4.8 Amps minimum
 */

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  rval = analogRead(rpin);

  Serial.println(rval);

  delay(100);

}
