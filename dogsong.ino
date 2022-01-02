#include "pitches.h"

int buttonPin = 12;

// notes in the melody:
int melody[] = {0,GS4,0,F4,0,CS4,DS4,CS4,GS3,AS3,CS4,0,AS3,0,CS4,0,C4,CS4,DS4,0,0,GS4,0,F4,0,CS4,DS4,CS4,GS3,AS3,CS4,FS4,F4,DS4,0,DS4,CS4,AS3,0,AS3,CS4,CS4,0,GS3,0,GS4,0,F4,0,CS4,DS4,CS4,GS3,AS3,CS4,0,AS3,0,CS4,0,C4,CS4,DS4,0,GS3,0,GS4,0,F4,0,CS4,DS4,CS4,GS3,AS3,CS4,FS4,F4,DS4,0,DS4,CS4,AS3,0,AS3,CS4,CS4,0,0,AS3,0,AS3,0,AS3,CS4,C4,AS3,GS3,AS3,0,F3,0,F3,0,DS3,F3,FS3,F3,DS3,0,0,AS3,0,AS3,0,AS3,CS4,C4,AS3,GS3,AS3,0,C4,0,GS3,0,C4,DS4,CS4,C4,AS3,C4,0,AS3,0,AS3,0,AS3,CS4,C4,AS3,GS3,AS3,0,F3,0,F3,0,DS3,F3,FS3,F3,DS3,0,0,AS3,0,AS3,0,AS3,CS4,C4,AS3,GS3,AS3,0,C4,0,GS3,0,C4,DS4,CS4,0,C4,0,C4,C4,0,CS4,0,C4,0,C4,0,0};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {4,4,8,4,8,4,8,4,8,8,8,4,4,8,4,8,4,8,8,2,4,4,8,4,8,4,8,4,8,8,8,8,8,8,8,8,8,8,8,4,4,4,8,8,4,4,8,4,8,4,8,4,8,8,8,4,4,8,4,8,4,8,4,8,4,4,4,8,4,8,4,8,4,8,8,8,8,8,8,8,8,8,8,8,4,4,4,4,4,4,8,8,4,4,8,4,8,8,8,4,4,8,8,4,4,8,4,8,8,8,4,4,8,8,4,4,8,4,8,8,8,4,4,8,8,4,4,8,4,8,8,8,4,4,8,8,4,4,8,4,8,8,8,4,4,8,8,4,4,8,4,8,8,8,4,4,8,8,4,4,8,4,8,8,8,4,4,8,8,4,4,8,8,4,4,4,4,8,16,8,16,8,4,4,4,4};

void setup() 
{
  pinMode(buttonPin, INPUT);
}

void loop()
{
  //read the input pin
  int buttonState = digitalRead(buttonPin);

    //if the button is pressed
    if (buttonState == 1)
    {
  
      // iterate over the notes of the melody:
      for (int thisNote = 0; thisNote < 186; thisNote++) 
      {

        // to calculate the note duration, take one second divided by the note type.
        int noteDuration = 1000 / noteDurations[thisNote];

        tone(8, melody[thisNote], noteDuration);

        // to distinguish the notes, set a minimum time between them.
        int pauseBetweenNotes = noteDuration * 1.05;

        delay(pauseBetweenNotes);

        // stop the tone playing:
        noTone(8);
      }
    }
}
