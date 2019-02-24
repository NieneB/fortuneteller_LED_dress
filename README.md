
My [previous princess dress](https://nieneb.nl/offline-projects/led_light_dress/) gave light for one evening. It was robust. Survived from 20:00 till 01:00. At exactly 01:00 when picking up my coat from the gardarobe the RaspberryPi ran out of power and stopped functioning. The LED strips survived a full crowd of people, bumping into me, dancing and drinking lots of beer. 

## So what went wrong the last time

A lot can be improved on my project. Starting with the software; using a [RaspberryPi for Neopixel LEDs](https://github.com/jgarff/rpi_ws281x) isn't the most convenient way to go. Although it did work thanks to Jeremy Garff's library and I had a python server running with an app on my phone that controlled the LEDs, it was overkill, not very solid or bug free.. I even used a `ssh` connection on my phone will standing in the pub to fix things on the spot! For the hardware; the cables I used for powering were way to stiff and large, I could have taken thinner cables. I sew on my strips, while using something like klitterband would have been more convenient. The power needed for the LED strips was over estimated at the time. So I dragged around too much hardware. 

The costume theme was a princess dress and it lacked the kind of small story that a costume makes a good costume. People were amazed by my costume and found it beautiful, but they didn't "get it". (and I certainly did not win the best costume price.... ) A princess dress doesn't give light and there was no interaction for the people to play with the cool functionality itself. It needed something more persuading. 

After that evening the dress went into storage. I wrapped a rope around the petticoat with the strips to make it smaller. I moved it several times. So when I picked up the dress after half a year, some strips were broken. Also some LEDs are damaged and I couldn't get it to work properly again. Time for something new. 

## The new idea:  Gipsy Fortune Teller

I started to take off the strips from the petticoat. Put on the petticoat. Went walking around the house and came to my sewing machine again. With some left over fabrics I started to transform the skirt into something more like a pirates skirt or.. a gipsy skirt! My head started spinning and before I knew I ordered more LED lights and another micro controller online.

The gipsy fortune teller costume is going to exist out of a fortune glass boll and a dress with necklace. People will be asked to put their hand on the boll in order to tell their fortune. When placing their hand on the boll, it will start glowing and then the whole dress and necklace will light up with the color of their mood. With the color comes a little card explaining them their fortune.

<a data-flickr-embed="true"  href="https://www.flickr.com/photos/141950816@N04/33279955788/in/album-72157678630288048/" title="VID_20190217_175844"><img src="https://farm8.staticflickr.com/7862/33279955788_6d4b2ce999.jpg" width="281" height="500" alt="VID_20190217_175844"></a>

## Making the costume

### Sewing

For the costume I re-use the petticoat from my previous dress. On top of that come layers of fabric with ruffle edges, composed form all kinds of left over fabric. Making it full and disorganized. Simply cutting circle skirts and making the ruffles. I had a nice black top laying around that goes perfect with it. 

For the ruffles I cut strips from 10 cm wide from all kinds of leftover fabric. So it depends on the fabric how much I got. I trimmed one edge with my trimming foot. Giving it a nice colored round edge. 
When sewing them to the bottom of a circle skirt I rimpled them up, just with hand while at the machine. No pins needed to attach these meters of fabric! I think I spend a few evenings verwerken my old fabrics. It felt good using and shrinking in my fabric collection.

<div style="text-align:center">
<a data-flickr-embed="true"  href="https://www.flickr.com/photos/141950816@N04/albums/72157676662356577" title="sewing_gypsy_dress"><img src="https://farm8.staticflickr.com/7843/46166825955_0aa63d6a01_c.jpg" width="800" height="536" alt="sewing_gypsy_dress"></a>
</div>

## The LED lights

### Tools and Gears. 

What will I use for this project:

* [Adafruit Flora v3](https://www.kiwi-electronics.nl/adafruit-flora-v3?search=flora&description=true) board
* [NeoPixel Ring 12 LEDs](https://www.kiwi-electronics.nl/adafruit/adafruit-leds/neopixel-ring-12x-ws2812-5050-rgb-led-met-drivers) 2X
* NeoPixel LED strips (60 pixels?) [re-use from previous project](https://nl.aliexpress.com/item/DC-5V-12V-WS2811-WS2812B-WS2812-IC-SMD-5050-digital-RGB-Strip-waterproof-Dream-Magic-Full/32823280011.html?spm=2114.search0104.8.3.SI6cRu)
* [Lead Accu](https://www.123accu.nl/Ultracell-UL4-5-6-VRLA-loodaccu-6V-4500-mAh-i25539.html?mkwid=sdHKNZFmA_dc%7Cpcrid%7C301521551187%7Cpkw%7C%7Cpmt%7C%7Cslid%7C%7Cprid%7CANB00549_4040849467585&pgrid=64202844390&ptaid=pla-349267766635&gclid=EAIaIQobChMIvp61wKDK4AIV1ud3Ch2u6AnBEAQYASABEgKUK_D_BwE)
* a button
* Arduino SLE 
* 2 pin JST connector
* cables, and soldering materials
* [Plastic bol](https://www.pipoos.com/transparante-plastic-bal-14-cm.html) 14cm from the arts and craft store

<a data-flickr-embed="true"  href="https://www.flickr.com/photos/141950816@N04/46356567174/in/album-72157678630288048/" title="IMG_20190201_135558"><img src="https://farm8.staticflickr.com/7816/46356567174_7b3548d93e_c.jpg" width="800" height="452" alt="IMG_20190201_135558"></a>

With the button on the boll I can trigger the LEDs to start a (random) program. The LED ring in the boll will start glowing 3 times with white light. Then it will set off the whole dress in a specific color, including a necklace that will join the dress. 

Instead of a RaspberryPi (which was overkill) I will use the Flora board. It runs of 5V so can be hooked onto the same power source as the LEDs. It can control up to 600 LEDs and has a reset button. And very easy to get going! 

I will reuse my Lead Accus from the last project. Not that it is the most convenient to drag around, but I still have them. Buying new Lithum Ion accus is another option, but this simply saves some money. 
They work on 6V and deliver ... mAh. So one will be enough? to run the Flora board and the LEDs. 
I will test out later how long one lasts. 

### Circuit Diagram


### Soldering and testing


### Powering

1 lead accus. of 6 volt, 4.5AH
[product](https://www.123accu.nl/Ultracell-UL4-5-6-VRLA-loodaccu-6V-4500-mAh-i25539.html?mkwid=sdHKNZFmA_dc%7Cpcrid%7C301521551187%7Cpkw%7C%7Cpmt%7C%7Cslid%7C%7Cprid%7CANB00549_4040849467585&pgrid=64202844390&ptaid=pla-349267766635&gclid=EAIaIQobChMIvp61wKDK4AIV1ud3Ch2u6AnBEAQYASABEgKUK_D_BwE)
**Specs:** 
Part Number: UL4.5-6
Length: 70 ± 2 mm (2.76 inches)
Width: 47 ± 2 mm (1.85 inches)
Container Height: 101 ± 2 mm (3.94inches)
Total Height (with terminal) : 106 ± 2 mm (4.17 inches)
Approx Weight: Approx 0.75kg (1.65lbs)


### Button programming

I wanted to play multiple light programs with just one button. Here is the basic code snippet of the counting for the button. It will count every 100 milli seconds you hold the button down and light up one LED for every count. When you let go it will play a light program showing all LEDs in specific color. The `buttonstate` tracks if you let go of the button, and only then it will continue executing a program. Of course this code can be extended untill you can count no further! Here I only show 5 different programs. At the count of 5 it will reset the button count and state. 

<a data-flickr-embed="true"  href="https://www.flickr.com/photos/141950816@N04/46356564114/in/album-72157678630288048/" title="VID_20190204_211948"><img src="https://farm8.staticflickr.com/7844/46356564114_b27c21f9ff.jpg" width="281" height="500" alt="VID_20190204_211948"></a>

This enables me to choose from multiple light programs with just one button! 

```
#include <Adafruit_NeoPixel.h>

#define PIN 9
#define buttonPin 6 
int buttonPushCounter = 0;   // counter for the number of button presses
int buttonState = 0; 
int lastButtonState = 0;     // previous state of the button

Adafruit_NeoPixel strip = Adafruit_NeoPixel(12, PIN, NEO_RGB + NEO_KHZ800);

void setup() {
    pinMode(buttonPin, INPUT_PULLUP);
    strip.begin();
    strip.setBrightness(100);
    strip.show(); 

}

void loop() {
  
    // read the pushbutton input pin:
    buttonState = digitalRead(buttonPin);

    // when button is pushed in start counting
    if(buttonState == LOW)
    {
        delay(100);
        buttonPushCounter++;
        //Show one led per count
        strip.setPixelColor(buttonPushCounter, strip.Color(255,0,0));
        strip.show();
    };

    // When button is up again
    if (buttonState != lastButtonState) {
        startProgram(buttonPushCounter);
    };

    //RESET automatically at count of 5 
    if(buttonPushCounter == 5){
        program5();
        reset();
    };
}

// Choose program
void startProgram(int count){
  if(count==1){program1();}
  if(count==2){program2();}
  if(count==3){program3();}
  if(count==4){program4();}
};

void program1(){ //Blue color
    ColorStrip(strip.Color(0,0,255));
    delay(1000);
    reset();
}

void program2(){ //Green color
    ColorStrip(strip.Color(0,255,0));
    delay(1000);
    reset();
}

void program3(){ //Red color
    ColorStrip(strip.Color(255,0,0));
    delay(1000);
    reset();
}

void program4(){ //Pink
    ColorStrip(strip.Color(255,0,255));
    delay(1000);
    reset();
}

void program5(){ //Yellow
    ColorStrip(strip.Color(255,187,104));
    delay(1000);
    reset();
}

// Reset button state and counter after every program
void reset(){
  buttonPushCounter = 0;
  buttonState = 0; 
  lastButtonState = 0;
  ColorStrip(strip.Color(0,0,0));
}


// Set one color on whole strip
void ColorStrip(uint32_t c){
    // set the colors for the strip
    for( int i = 0; i <strip.numPixels(); i++ )
        strip.setPixelColor(i, c);
    // show all pixels  
    strip.show();
    // wait for a short amount of time -- sometimes a short delay of 5ms will help
    // technically we only need to execute this one time, since we aren't changing the colors but we will build on this structure
    delay(10);
};

```

## More code! 

From this basic code I started working out the different light programs I wanted to show. To begin with I want a prediction light state in which the crystal ball would flow a few times before showing the final color. This is my prediction code:

```

``` 

## Working crystal ball

<a data-flickr-embed="true"  href="https://www.flickr.com/photos/141950816@N04/46240993975/in/album-72157678630288048/" title="IMG_20190217_175937"><img src="https://farm8.staticflickr.com/7887/46240993975_de926bb066.jpg" width="500" height="282" alt="IMG_20190217_175937"></a>
## LED strips
<a data-flickr-embed="true"  href="https://www.flickr.com/photos/141950816@N04/40115271943/in/album-72157678630288048/" title="IMG_20190209_190833"><img src="https://farm8.staticflickr.com/7823/40115271943_0f79b0872c.jpg" width="500" height="282" alt="IMG_20190209_190833"></a>

<a data-flickr-embed="true"  href="https://www.flickr.com/photos/141950816@N04/46166818555/in/album-72157678630288048/" title="IMG_20190211_203315"><img src="https://farm8.staticflickr.com/7883/46166818555_b2f84b6ac5.jpg" width="500" height="282" alt="IMG_20190211_203315"></a>

<a data-flickr-embed="true"  href="https://www.flickr.com/photos/141950816@N04/47028029642/in/album-72157678630288048/" title="IMG_20190211_201052_1"><img src="https://farm8.staticflickr.com/7892/47028029642_45edb87659.jpg" width="500" height="282" alt="IMG_20190211_201052_1"></a>

## Issues I've overcome
Here I just jot down some issues I come across during the process, with their solutions and answers. 

**I hope the Flora board will run with my Linux machine. I do not own anything else (I swore off Windows and Mac).**

Yes, the Flora board runs perfectly with Linux! I saw some comments with some Arduino microcontrollers and Lilypad stuf that made me doubt. But it is just plugging in, install the Arduino SLE and the right boards and go. 

Explanation here: 

NOTE: Do use a USB cable wich can transfer data! Not a power only cable. I did this first and got frustrated my usb was not detected.. 

**I will have to learn the Arduino syntax.**
No Prob. 


**Can I run the whole project on one Lead Accu?**

Yes, yes I can. 

**RGB, GRB?!!?**
The NeoPixel rings are rgb but my strips are grb... (yes cheap strips) So needed to work some code to rewrite the colors for the 3 components independently. Also coming in handy when you only want to light up one component. 

```C++
// Color Whole Strip 
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
```