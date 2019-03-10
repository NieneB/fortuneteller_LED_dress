#include <Adafruit_NeoPixel.h>

#define PIN 9  // LED data pin
#define buttonPin 6   //Button pin
int buttonPushCounter = 0;   // counter for the number of button presses
int buttonState = LOW;  // Button state HIGH / LOW
int lastButtonState = LOW;     // previous state of the button
int program;
int voorspellingCount = 0; 

//INITIALIZE STRIP 
Adafruit_NeoPixel strip = Adafruit_NeoPixel(108, PIN, NEO_GRB + NEO_KHZ800); //108

// 3 components of dress
int NUM_PIXELS = strip.numPixels() ; 
int NUM_PIX_RING = 12;
int NUM_PIX_STRIP = 78;
int START_PIX_RING_1 = 0; 
int START_PIX_STRIP = NUM_PIX_RING;
int START_PIX_RING_2 = NUM_PIX_RING+NUM_PIX_STRIP;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  strip.begin();
  strip.setBrightness(255); // between 0-255
  strip.show(); 
  randomSeed(analogRead(0)); // random seed on noise pin 0
}

void loop() {
// program4();
//  reset();
  //to test play all programs
//   startProgram(1);
   //read the pushbutton input pin:
  buttonState = digitalRead(buttonPin);
  // IF button is pressed start counting
  if(buttonState == LOW){
    voorspelling(1); // One glow per count
    buttonPushCounter++;
    delay(200); //test
  };
  //When button is released 
  if (buttonState != lastButtonState) {
    startProgram(buttonPushCounter);
  };
  // When button is held longer then 5 x 200 is rainbow program chase
  if(buttonPushCounter == 4){
    voorspellingCount = 0;
    program8();
    reset();
  };
}

void startProgram(int count){
  //One press is random program:  
  if(count==1){
    voorspellingCount = 2;
    program = random(8);
    switch(program){
      case 1:
        program1();
        break;
      case 2:
        program2();
        break;
      case 3:
        program3();
        break;
      case 4:
        program4();
        break;
      case 5:
        program5();
        break;
      case 6:
        program6();
        break;
      case 7:
        program7();
        break;
    }
  }
  //Hold 2 counts is program no green and red
  if(count==2){
    voorspellingCount = 1;
    program = random(4);
    switch(program){
      case 1:
        program1();
        break;
      case 2:
        program4();
        break;
      case 3:
        program5();
        break;
      case 4:
        program6();
        break;
    }
    
  } 
  //Hold 3 counts is red 
  if(count==3){
    voorspellingCount = 0;
    program3(); //red
    } 
   //Hold 4 counts is rainbow sepcialprogram
  if(count==4){
    voorspellingCount = 0;
    program8();} //Regenboog
}

//RESET count and strips OFF 
void reset(){
  buttonPushCounter = 0;
  buttonState = 0; 
  lastButtonState = 0;
  ColorStrip(0,0,0,4);
  voorspellingCount = 0;
  delay(10);
}

// ColorWhole Strip 
void ColorStrip(int r, int g , int b, int wait){
  ring1(r,g,b);
  strips(r,g,b);
  ring2(r,g,b);
  strip.show();
  delay(wait);
}

//COLOR ring 1 
void ring1(int r, int g , int b ){
  for( int i = START_PIX_RING_1; i < NUM_PIX_RING; i++ ){
    strip.setPixelColor(i, strip.Color(r,g,b));
  }
}

//COLOR strips
void strips(int r, int g , int b ){
  for( int i = START_PIX_STRIP; i < NUM_PIX_STRIP+START_PIX_STRIP; i++ ){
    strip.setPixelColor(i, strip.Color(g,r,b));
  }
}

//COLOR ring 2
void ring2(int r, int g , int b ){
  for( int i = START_PIX_RING_2; i < NUM_PIX_RING+START_PIX_RING_2; i++ ){
    strip.setPixelColor(i, strip.Color(r,g,b));
  }
}

//ONE GLOW for first ring
void voorspelling(int times){ //glow yellow red white light // RING ONLY
  for(int i = 0; i < times; i++){
     // Fade IN
      for(int k = 0; k <= 100; k++) {
        int r = (k*255)/100;
        int g = ((k/3)*255)/100;
        int b = ((k/10)*255)/100;
        ring1(r, g, b);
        strip.show();
        delay(4);
      }
      // Fade OUT
      for(int k = 100; k >= 0; k--) {
        int r = (k*255)/100;
        int g = ((k/3)*255)/100;
        int b = ((k/10)*255)/100;
        ring1(r, g ,b);
        strip.show();
        delay(4);
      }
      //PAUSE
      delay(200);
  }
}

void program1(){ //BLAUW
    voorspelling(voorspellingCount);
    
    // Fade IN
    for(int k = 0; k <= 255; k++) {
      ColorStrip(0,0,k,5);
    }
    delay(5000);
    // Fade OUT
    for(int k = 255; k >= 0; k--) {
      ColorStrip(0,0,k,8);
    }
    reset();
}

void program2(){ //GROEN
    voorspelling(voorspellingCount);
    
    // Fade IN
    for(int k = 0; k <= 255; k++) {
      ColorStrip(0,k,0,5);
    }
    delay(5000);
    //Bink out
    ColorStrip(0,0,0,100);
    ColorStrip(0,255,0,100);
    ColorStrip(0,0,0,50);
    ColorStrip(0,255,0,50);
    ColorStrip(0,0,0,40);
    ColorStrip(0,255,0,40);
    ColorStrip(0,0,0,100);
    ColorStrip(0,255,0,100);
    ColorStrip(0,0,0,50);
    ColorStrip(0,255,0,50);
    ColorStrip(0,0,0,40);
    ColorStrip(0,255,0,40);
    ColorStrip(0,0,0,100);
    ColorStrip(0,255,0,100);
    ColorStrip(0,0,0,50);
    ColorStrip(0,255,0,50);
    ColorStrip(0,0,0,40);
    reset();
}

void program3(){ //ROOD
    voorspelling(voorspellingCount);
    
    //fade in
    for(int k = 0; k <= 80; k++) {
          ColorStrip(k,0,0,1);
    };
    // four iterations
    for(int i=0; i <= 4; i ++){ 
        //start hartbeat
        ColorStrip(80,0,0,1);
        delay(400);
        //beat 1        
        for(int k = 80; k <= 255; k++) {
          ColorStrip(k,0,0,1);
        }
        for(int k = 255; k >= 80; k--) {
          ColorStrip(k,0,0,1);
        }
        delay(300);
        //beat 2      
        for(int k = 80; k < 150; k++) {
          ColorStrip(k,0,0,1);
        }
        for(int k = 150; k >= 80; k--) {
          ColorStrip(k,0,0,1);
        }
        //beat3
        delay(150);
         for(int k = 80; k <= 200; k++) {
          ColorStrip(k,0,0,1);
        }
        for(int k = 200; k >= 80; k--) {
          ColorStrip(k,0,0,1);
        }
    };
    for(int k = 80; k >= 0; k--) {
          ColorStrip(k,0,0,4);
        }
    reset();
}

void program4(){ //GEEL
    voorspelling(voorspellingCount);
     ColorStrip(255,208,0,8);
    delay(5000);

//    //define strips as matrix    
//    int strip1[] = {12,13,14,15,16,17,18,19,20,21,22,23,24};
//    int strip2[] = {37,36,35,34,33,32,31,30,29,28,27,26,25};
//    int strip3[] = {38,39,40,41,42,43,44,45,46,47,48,49,50};
//    int strip4[] = {63,62,61,60,59,58,57,56,55,54,53,52,51};
//    int strip5[] = {64,65,66,67,68,69,70,71,72,73,74,75,76};
//    int strip6[] = {89,88,87,86,85,84,83,82,81,80,79,78,77};
//    ring1(255,208,0);
//    ring2(255,208,0);
    //Waterfall down
//    for(int j =0; j < 10; j++){
//      
//      for(int i =0; i <= 14; i++){
//         strip.setPixelColor(strip1[i], strip.Color(255,211,0));
//         strip.setPixelColor(strip2[i], strip.Color(255,211,0));
//         strip.setPixelColor(strip3[i], strip.Color(255,211,0));
//         strip.setPixelColor(strip4[i], strip.Color(255,211,0));
//         strip.setPixelColor(strip5[i], strip.Color(255,211,0));
//         strip.setPixelColor(strip6[i], strip.Color(255,211,0));
//         strip.show();
//         delay(60);
//         strip.setPixelColor(strip1[i-2], strip.Color(0,0,0));
//         strip.setPixelColor(strip2[i-2], strip.Color(0,0,0));
//         strip.setPixelColor(strip3[i-2], strip.Color(0,0,0));
//         strip.setPixelColor(strip4[i-2], strip.Color(0,0,0));
//         strip.setPixelColor(strip5[i-2], strip.Color(0,0,0));
//         strip.setPixelColor(strip6[i-2], strip.Color(0,0,0));
//         strip.show();
//         delay(4);
//      }
//    };
    reset();
}

void program5(){ //WIT
    voorspelling(voorspellingCount);
    delay(60);
    theaterChase(strip.Color(255,255,255), 100);
    reset();
}


void program6(){ //PURPLE
    voorspelling(voorspellingCount);
    delay(60);

    ColorStrip(255,0,255,4);
    delay(5000);
    
    //twinkle out
    for (int i=0; i<= 300; i++) {
     strip.setPixelColor(random(108),strip.Color(0,0,0));
     strip.show();
     delay(9);
   }
    reset();
}

void program7(){ //RAINBOW  
    voorspelling(voorspellingCount);
    delay(40);
    rainbowCycle(8);
    reset();
}

void program8(){ //RAINBOW  SPECIAL
    for(int i=0; i <= strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel((i) & 255));
    }
    strip.show();
    delay(300);
    ColorStrip(0,0,0,5);
    delay(300);
    for(int i=0; i <= strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel((i) & 255));
    }
    strip.show();
    delay(200);
    ColorStrip(0,0,0,5);
    delay(200);
    for(int i=0; i <= strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel((i) & 255));
    }
    strip.show();
    delay(100);
    ColorStrip(0,0,0,5);
    delay(100);
    for(int i=0; i <= strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel((i) & 255));
    }
    strip.show();
    delay(50);
    ColorStrip(0,0,0,5);
    delay(50);
    for(int i=0; i <= strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel((i) & 255));
    }
    strip.show();
    delay(10);
    ColorStrip(0,0,0,5);
    delay(10);
    theaterChaseRainbow(40);
    reset();
}

void rainbow(uint8_t wait) {
  uint16_t i, j;
  for(j=0; j<= 255; j++) {
    for(i=0; i <= strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel((i+j) & 255));
    }
    strip.show();
    delay(wait);
  }
}

//Theatre-style crawling lights with rainbow effect
void theaterChaseRainbow(uint8_t wait) {
  for (int j=0; j <= 255; j++) {     // cycle all 256 colors in the wheel
    for (int q=0; q < 4; q++) {
      for (uint16_t i=0; i <= strip.numPixels(); i=i+4) {
        strip.setPixelColor(i+q, Wheel( (i+j) % 255));    //turn every third pixel on
      }
      strip.show();

      delay(wait);

      for (uint16_t i=0; i <= strip.numPixels(); i=i+4) {
        strip.setPixelColor(i+q, 0);        //turn every third pixel off
      }
    }
  }
}

// Slightly different, this makes the rainbow equally distributed throughout
void rainbowCycle(uint8_t wait) {
  uint16_t i, j;
  for(j=0; j<256*4; j++) { // 5 cycles of all colors on wheel
    for(i=0; i< strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j) & 255));
    }
    strip.show();
    delay(wait);
  }
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}



//Theatre-style crawling lights.
void theaterChase(uint32_t c, uint8_t wait) {
  for (int j=0; j<20; j++) {  //do 10 cycles of chasing
    for (int q=0; q < 3; q++) {
      for (uint16_t i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, c);    //turn every third pixel on
      }
      strip.show();

      delay(wait);

      for (uint16_t i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, 0);        //turn every third pixel off
      }
    }
  }
}
