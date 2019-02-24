#include <Adafruit_NeoPixel.h>

#define PIN 9  // LED data pin
#define buttonPin 6   //Button pin
int buttonPushCounter = 0;   // counter for the number of button presses
int buttonState = LOW;  // Button state HIGH / LOW
int lastButtonState = LOW;     // previous state of the button

int offset = 0;//?

int voorspellingCount = 0; 

//INITIALIZE STRIP 
Adafruit_NeoPixel strip = Adafruit_NeoPixel(12, PIN, NEO_GRB + NEO_KHZ800); //108?
void setup() {
  // put your setup code here, to run once:
  strip.begin();
  strip.setBrightness(255); // between 0- 255
  strip.show(); 
}

void loop() {
  
  // put your main code here, to run repeatedly:
  int program = random(0,12);
  for( int i = 0; i <= program; i++ ){
       strip.setPixelColor(i, strip.Color(255,0,0));
    }
   strip.show();
   delay(500);
   for( int i = 0; i <= program; i++ ){
       strip.setPixelColor(i, strip.Color(0,0,0));
    }
   strip.show();
   delay(500);
}
