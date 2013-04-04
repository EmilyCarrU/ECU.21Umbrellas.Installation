
//---------------------------------------------------------------//
// RESET

void resetStrand(int i) {
  
  timer[i] = 0;
  speed[i] = 0;
  
  // Is It At the End ?? Then Reset
  if (i >= endLED[i]){
    timer[i] = speed[i];
  }
  
  // Is Our Timer Ready To Switch ?? 
  if(currentMillis[i] - stepTime[i] >= timer[i]) {
    
    // Turn The LEDs Black
    leds[LEDsections[i]].r = 0;
    leds[LEDsections[i]].g = 0;
    leds[LEDsections[i]].b = 0;

    // Increment
    LEDsections[i]++;

    // Go Back To The Beginning
    if(LEDsections[i] == endLED[i]){
      LEDsections[i] = startLED[i];
      timer[i] = speed[i];
    }

    // Turn The LEDs White
    leds[LEDsections[i]].r = 255;
    leds[LEDsections[i]].g = 255;
    leds[LEDsections[i]].b = 255;

    // Reset Our Timer
    stepTime[i] = currentMillis[i];
  }
  
  
}