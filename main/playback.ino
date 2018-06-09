#include "pitches.h"

// notes in the melody:
int melody[] = {
  NOTE_C3, NOTE_E3, NOTE_G3, NOTE_C4, NOTE_C4 ,NOTE_G3, NOTE_E3, NOTE_C3,
  NOTE_C3, NOTE_E3, NOTE_G3, NOTE_C4, NOTE_C4 ,NOTE_G3, NOTE_E3, NOTE_C3,
  NOTE_C3, NOTE_D3, NOTE_E3, NOTE_F3, NOTE_G3, NOTE_A3 ,NOTE_B3, NOTE_C4,
  NOTE_B3, NOTE_G3, NOTE_G3, 
  NOTE_B2, NOTE_C3, NOTE_D3, NOTE_E3, NOTE_F3, NOTE_G3, NOTE_A3 ,NOTE_B3,
  NOTE_A3, NOTE_G3, NOTE_E3,
  NOTE_C3, NOTE_E3, NOTE_G3, NOTE_E3, NOTE_C3, NOTE_E3, NOTE_G3, NOTE_E3,
  NOTE_F3, NOTE_A3, NOTE_C4, NOTE_A3, NOTE_C4,
  NOTE_C4, NOTE_B3, NOTE_A3, NOTE_G3, NOTE_F3, NOTE_E3 ,NOTE_D3, NOTE_C3,
  NOTE_D3, NOTE_C3, NOTE_C3
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  4,4,4,4,4,4,4,4,
  4,4,4,4,4,4,4,4,
  4,4,4,4,4,4,4,4,
  2,2,1,
  4,4,4,4,4,4,4,4,
  2,2,1,
  4,4,4,4,4,4,4,4,
  4,4,4,4,1,
  4,4,4,4,4,4,4,4,
  2,4,1
};

void play() {
  // iterate over the notes of the melody:
  for(int i=0; i<2; i++){
    for (int thisNote = 0; thisNote < 62; thisNote++) {

      // to calculate the note duration, take one second divided by the note type.
      //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
      int noteDuration = 1000 / noteDurations[thisNote];
      tone(8, melody[thisNote], noteDuration);

      // to distinguish the notes, set a minimum time between them.
      // the note's duration + 30% seems to work well:
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
      // stop the tone playing:
    noTone(8);
    }
  }
}

