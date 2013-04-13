/* 
 
 by Robert Werner
 floatingbob@icloud.com
 
 This sketch allows you to drive a strand of LEDs with a TM1009 chip. These
 LEDs currently drive from one pin, into LEDs that are hooked up in series. 
 Four strands blink at random speeds.
 
 I am currently attempting to streamline all my for statements that drive the LEDs into
 a single for array. 
 
 
 */


//---------------------------------------------------------------//
// VARIABLES

// INCLUDES  
#include <FastSPI_LED.h>

// DEFINES
#define NUM_LEDS 300

// STRUCTS
struct CRGB { 
  unsigned char r; 
  unsigned char g; 
  unsigned char b; 
};
struct CRGB *leds;

// SERIAL
int outputPin = 4;
const int sensorPin = 5;
long value = 0;
int cm = 0;
int inches = 0;

// CLOCK
unsigned long currentMillis[8] = {0,0,0,0,0,0,0,0}; //millis timer array strands 1-4

unsigned long stepTime[8] = {0,0,0,0,0,0,0,0}; //step time clock restarter strands 1-4

// Number Of Strands
int numStrands = 8;

// Length Of Strands
unsigned long strandLength = 18;

// Global load of start position based upon strand length
int startLED[8] = { 
  strandLength * 0,  // 0 
  strandLength * 1,  // 18
  strandLength * 2,  // 36
  strandLength * 3,  // 54
  strandLength * 4,  // 72
  strandLength * 5,  // 90
  strandLength * 6,  // 108
  strandLength * 7   // 126
}; 

// Starting position of the led (this number drives the LED through the strand from this start position)
int LEDsections[8] = {
  startLED[0],
  startLED[1], 
  startLED[2], 
  startLED[3], 
  startLED[4], 
  startLED[5],
  startLED[6],
  startLED[7] 
};

// Starting point of LED + strandLength
int endLED[8] = {
  startLED[0] + strandLength, 
  startLED[1] + strandLength, 
  startLED[2] + strandLength,
  startLED[3] + strandLength, 
  startLED[4] + strandLength, 
  startLED[5] + strandLength,
  startLED[6] + strandLength, 
  startLED[7] + strandLength 
}; 

int blinkSpeed[101] = {
  0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,
  41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,67,68,69,70,71,72,73,74,75,76,78,79,
  80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100
};

  
// Randomizer 
int randomizer[8];

// ??
long randNumber;

// Strand timer varialbe that allows an LED to run the full length at one speed
int timer[8] = {0,0,0,0,0,0,0,0}; 

// Speed variable, which pulls a random number from the blinkSpeed[]
int speed[8] = {0,0,0,0,0,0,0,0};

// Reset all LEDs when not sensing people
int reset = 0; 












