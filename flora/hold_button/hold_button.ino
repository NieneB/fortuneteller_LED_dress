#include <Adafruit_NeoPixel.h>

#define PIN 9
#define buttonPin 6 
int buttonPushCounter = 0;   // counter for the number of button presses
int buttonState = 0; 
int lastButtonState = 0;     // previous state of the button

int offset = 0;

Adafruit_NeoPixel strip = Adafruit_NeoPixel(108, PIN, NEO_GRB + NEO_KHZ800); //108?

// 3 components of dress
int NUM_PIXELS = strip.numPixels() ; 
int START_PIX_RING_1 = 1;
int NUM_PIX_RING_1 = 12;
int START_PIX_STRIP = 13;
int NUM_PIX_STRIP =  84 ;
int START_PIX_RING_2 = 97;
int NUM_PIX_RING_2 = 12;

//RED
//RED_RING = strip.Color(255,0,0);
//RED_STRIP = strip.Color(0,255,0);
////GREEN
//GREEN_RING = strip.Color(0,255,0);
//GREEN_STRIP = strip.Color(255,0,0);
////BLUE
//BLUE_RING = strip.Color(0,0,255);
//BLUE_STRIP = strip.Color(0,0,255);
////YELLOW
//YELLOW_RING = strip.Color(255,0,255);
//YELLOW_STRIP = strip.Color(0,255,255);
////PURPLE
//PURPLE_RING = strip.Color(255,0,100);
//PURPLE_STRIP = strip.Color(0,255,100);
////WHITE
//WHITE_RING = strip.Color(255,255,255);
//WHITE_STRIP = strip.Color(255,255,255);


void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  strip.begin();
  strip.setBrightness(100);
  strip.show(); 
}

void loop() {
  // read the pushbutton input pin:
  buttonState = digitalRead(buttonPin);

  if(buttonState == LOW)
  {
    voorspelling();
    buttonPushCounter++;
      delay(200);

  };

   
  if (buttonState != lastButtonState) {
    startProgram(buttonPushCounter);
  };
  
  if(buttonPushCounter == 5){
    program5();
    reset();
  };
}

void startProgram(int count){
  if(count==1){program1();}
  if(count==2){program2();}
  if(count==3){program3();}
  if(count==4){program4();}
}


void program1(){ //BLAUW
    voorspelling();
    delay(200);
    voorspelling();
    delay(200);
    // Fade IN
    for(int k = 0; k < 151; k++) {
      ColorStrip(strip.Color(0,0,k));
      strip.show();
      delay(10);
    }
    delay(5000);
    // Fade OUT
    for(int k = 150; k >= 0; k--) {
      ColorStrip(strip.Color(0,0,k));
      strip.show();
      delay(10);
    }
    reset();
}

void program2(){ //GROEN
    voorspelling();
    delay(200);
    // Fade IN
    for(int k = 0; k < 151; k++) {
      ColorStrip(strip.Color(0,k,0));
      strip.show();
      delay(10);
    }
    delay(5000);
    // Fade OUT
    for(int k = 150; k >= 0; k--) {
      ColorStrip(strip.Color(0,k,0));
      strip.show();
      delay(10);
    }
    reset();
}

void program3(){ //ROOD
    voorspelling();
    ColorStrip(strip.Color(255,0,0));
    delay(2000);
//twinkle out
    for (int i=0; i<250; i++) {
     strip.setPixelColor(random(108),strip.Color(0,0,0));
     strip.show();
     delay(20);
   }
    delay(200);
    reset();
}

void program4(){ //Roze
    ColorStrip(strip.Color(255,0,255));
    delay(2000);
    reset();
}

void program5(){ //GEEL
    ColorStrip(strip.Color(255,187,104));
    delay(2000);
    reset();
}

void reset(){
  buttonPushCounter = 0;
  buttonState = 0; 
  lastButtonState = 0;
  ColorStrip(strip.Color(0,0,0));
  delay(10);
}

void voorspelling(){ //glow yellow red white light // RING ONLY
  // Fade IN
    for(int k = 0; k < 100; k++) {
      int r = (k*255)/100;
      int g = ((k/3)*255)/100;
      int b = ((k/10)*255)/100;
      for( int i = 0; i <12; i++ )
        strip.setPixelColor(i, strip.Color(r,g,b));
      strip.show();
      delay(4);
    }
    // Fade OUT
    for(int k = 100; k >= 0; k--) {
      int r = (k*255)/100;
      int g = ((k/3)*255)/100;
      int b = ((k/10)*255)/100;
      strip.Color(k,k,0);
        for( int i = 0; i <12; i++ )
          strip.setPixelColor(i, strip.Color(r,g,b));     
        strip.show();
      delay(4);
    }
}







void Twinkle(byte red, byte green, byte blue, int Count, int SpeedDelay, boolean OnlyOne) {
  ColorStrip(strip.Color(0,0,0));
  for (int i=0; i<Count; i++) {
     strip.setPixelColor(random(12),red,green,blue);
   strip.show();
     delay(SpeedDelay);
     if(OnlyOne) { 
      ColorStrip(strip.Color(0,0,0));
     }
   }
  delay(SpeedDelay);
}

//Fade
void Fade(){
  // Fade IN
    for(int k = 0; k < 151; k++) {
      ColorStrip(strip.Color(k,0,0));
      strip.show();
      delay(0);
    }
    // Fade OUT
    for(int k = 150; k >= 0; k--) {
      ColorStrip(strip.Color(k,0,0));
      strip.show();
      delay(0);
    }
}

// Set one color on whole strip
void ColorStrip(uint32_t c){
   for( int i = 0; i <strip.numPixels(); i++ )
       strip.setPixelColor(i, c);
   strip.show();
//   delay(10);
}

// void NewKITT(byte red, byte green, byte blue, int EyeSize, int SpeedDelay, int ReturnDelay){
//   RightToLeft(red, green, blue, EyeSize, SpeedDelay, ReturnDelay);
//   RightToLeft(red, green, blue, EyeSize, SpeedDelay, ReturnDelay);
//   RightToLeft(red, green, blue, EyeSize, SpeedDelay, ReturnDelay);
//   RightToLeft(red, green, blue, EyeSize, SpeedDelay, ReturnDelay);
 
// }

// void CenterToOutside(byte red, byte green, byte blue, int EyeSize, int SpeedDelay, int ReturnDelay) {
//   for(int i =((12-EyeSize)/2); i>=0; i--) {
//     setAll(0,0,0);
   
//     setPixel(i, red/10, green/10, blue/10);
//     for(int j = 1; j <= EyeSize; j++) {
//       setPixel(i+j, red, green, blue);
//     }
//     setPixel(i+EyeSize+1, red/10, green/10, blue/10);
   
//     setPixel(12-i, red/10, green/10, blue/10);
//     for(int j = 1; j <= EyeSize; j++) {
//       setPixel(12-i-j, red, green, blue);
//     }
//     setPixel(12-i-EyeSize-1, red/10, green/10, blue/10);
   
//     showStrip();
//     delay(SpeedDelay);
//   }
//   delay(ReturnDelay);
// }

// void OutsideToCenter(byte red, byte green, byte blue, int EyeSize, int SpeedDelay, int ReturnDelay) {
//   for(int i = 0; i<=((12-EyeSize)/2); i++) {
//     setAll(0,0,0);
   
//     setPixel(i, red/10, green/10, blue/10);
//     for(int j = 1; j <= EyeSize; j++) {
//       setPixel(i+j, red, green, blue);
//     }
//     setPixel(i+EyeSize+1, red/10, green/10, blue/10);
   
//     setPixel(12-i, red/10, green/10, blue/10);
//     for(int j = 1; j <= EyeSize; j++) {
//       setPixel(12-i-j, red, green, blue);
//     }
//     setPixel(12-i-EyeSize-1, red/10, green/10, blue/10);
   
//     showStrip();
//     delay(SpeedDelay);
//   }
//   delay(ReturnDelay);
// }

// void LeftToRight(byte red, byte green, byte blue, int EyeSize, int SpeedDelay, int ReturnDelay) {
//   for(int i = 0; i < 12-EyeSize-2; i++) {
//     setAll(0,0,0);
//     setPixel(i, red/10, green/10, blue/10);
//     for(int j = 1; j <= EyeSize; j++) {
//       setPixel(i+j, red, green, blue);
//     }
//     setPixel(i+EyeSize+1, red/10, green/10, blue/10);
//     showStrip();
//     delay(SpeedDelay);
//   }
//   delay(ReturnDelay);
// }

// void RightToLeft(byte red, byte green, byte blue, int EyeSize, int SpeedDelay, int ReturnDelay) {
//   for(int i = 12-EyeSize-2; i >= 0; i--) {
//     setAll(0,0,0);
//     setPixel(i, red/10, green/10, blue/10);
//     for(int j = 1; j <= EyeSize; j++) {
//       setPixel(i+j, red, green, blue);
//     }
//     setPixel(i+EyeSize+1, red/10, green/10, blue/10);
//     showStrip();
//     delay(SpeedDelay);
//   }
//   delay(ReturnDelay);
// }

    
