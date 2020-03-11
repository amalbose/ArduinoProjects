#include "SevSeg.h"
SevSeg sevseg; 

int val = 0;
int out = 0;
void setup(){
    byte numDigits = 1;
    byte digitPins[] = {};
    byte segmentPins[] = {6, 5, 2, 3, 4, 7, 8, 9};
    bool resistorsOnSegments = true;

    byte hardwareConfig = COMMON_CATHODE; 
    sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments);
    sevseg.setBrightness(90);
    Serial.begin(9600);
}

void loop(){
  val = analogRead(A0);
  out = map(val, 0, 1023,0,9);
  sevseg.setNumber(out);
  sevseg.refreshDisplay();    
}
