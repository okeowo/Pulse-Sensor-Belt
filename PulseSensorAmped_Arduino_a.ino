  //variables for neopixel
#include <Adafruit_NeoPixel.h>
#define PIN 6
 
Adafruit_NeoPixel strip = Adafruit_NeoPixel(59, PIN, NEO_GRB + NEO_KHZ800);
 
//variables for pulse
int pulsePin = A0;
int ledStrip = 6;
//int fadeRate = 0; 
 
// these variables are volatile because they are used during the interrupt service routine!
volatile int BPM;                   // used to hold the pulse rate
volatile int Signal;                // holds the incoming raw data
volatile int IBI = 600;             // holds the time between beats, must be seeded! 
volatile boolean Pulse = false;     // true when pulse wave is high, false when it's low
volatile boolean QS = false;        // becomes true when Arduoino finds a beat.
int QScounter;
boolean fingerDect;
 
 // Regards Serial OutPut  -- Set This Up to your needs
//static boolean serialVisual = true;   // Set to 'false' by Default.  Re-set to 'true' to see Arduino Serial Monitor ASCII Visual Pulse 
 
void setup(){
  Serial.begin(9600);
  pinMode(pulsePin,INPUT);
  pinMode(ledStrip,OUTPUT);
  strip.begin();
  //strip.setBrightness(255);
  strip.show();
  interruptSetup();
}

void colorWipe(uint32_t c, uint8_t wait);
 
void loop(){
 
  if(BPM > 55) {
   fingerDect = true; 
  }
  
  if (QS == true && fingerDect == true && IBI > 650 && IBI < 1100){
  colorWipe(strip.Color(127,0,0), 5);      // blue
  colorWipe(strip.Color(0,0,0), 5);        // black
  Serial.println("QS true and fingerDect present!");
  }   
}
 
// Fill the dots one after the other with a color
/*void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, c);
      strip.show();
      delay(wait);
  }
}*/

void colorWipe(uint32_t c, uint8_t wait) {
  int i;

  for (i=0; i < strip.numPixels(); i++) {
      strip.setPixelColor(i, c);
      strip.show();
      delay(wait);
  }
}