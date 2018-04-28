char val;
int motor1_A=8;
int motor1_B=9;
int motor2_A=11;
int motor2_B=12;
int enable1=5;
int enable2=6;

int vel=100;
// released under the GPLv3 license to match the rest of the AdaFruit NeoPixel library

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1
#define PIN            3

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS      10

// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example for more information on possible values.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int delayval = 500; // delay for half a second

void setup() {
  // put your setup code here, to run once:
  Serial.begin(19200);
  Serial.println("Hello World");
  pinMode(motor1_A,OUTPUT);
  pinMode(motor1_B, OUTPUT);
  pinMode(motor2_A, OUTPUT);
  pinMode(motor2_B, OUTPUT); 
  #if defined (__AVR_ATtiny85__)
  if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
#endif
  // End of trinket special code

  pixels.begin(); // This initializes the NeoPixel library.   

    
}

void loop() {
   for(int i=0;i<NUMPIXELS;i++){

    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels.setPixelColor(i, pixels.Color(0,150,0)); // Moderately bright green color.

    pixels.show(); // This sends the updated pixel color to the hardware.

    delay(delayval); // Delay for a period of time (in milliseconds).

  }
  // put your main code here, to run repeatedly:
  analogWrite(enable1,vel);
  analogWrite(enable2,vel);
 if (Serial.available())
  val= Serial.read();
 if (val=='A'){
    digitalWrite(motor1_A, HIGH);
    digitalWrite(motor1_B, LOW);
    digitalWrite(motor2_A, LOW);
    digitalWrite(motor2_B, HIGH);
 }
 //Rectificar retroceso y derecha
 if (val=='R'){
  digitalWrite(motor1_B, LOW);
  digitalWrite(motor1_A, HIGH);
  digitalWrite(motor2_B, HIGH);
  digitalWrite(motor2_A, LOW);
 }
  if (val=='D'){
    digitalWrite(motor1_A, HIGH);
    digitalWrite(motor1_B, LOW);
    digitalWrite(motor2_A, LOW);
    digitalWrite(motor2_B, HIGH);
 }
 if (val=='I'){
  digitalWrite(motor1_A, LOW);
  digitalWrite(motor1_B, HIGH);
  digitalWrite(motor2_A, LOW);
  digitalWrite(motor2_B, HIGH);
 }
  if (val=='P'){
  digitalWrite(motor1_A, LOW);
  digitalWrite(motor1_B, LOW);
  digitalWrite(motor2_A, HIGH);
  digitalWrite(motor2_B, HIGH);
 }
}
