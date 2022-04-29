#include <HCSR04.h>

//Code by Isaac Shaw
/*
Integration with FPGA, ultrasonic sensor reads distance
This code reads ultrasonic input, converts it to binary, then sends it to the FPGA in parallel
The FPGA does logic to determine what note should be played then sends binary number in binary parallel
Arduino then converts this number into a usable tone for the buzzer and use the Tone commands to play the note.
*/
#include "pitches.h"


HCSR04 hc(7, 8); //initialisation class HCSR04 (trig pin , echo pin)

// 12 note scale
int scale[] = {
  NOTE_A4, NOTE_AS4, NOTE_B4, NOTE_C4, NOTE_CS5, NOTE_D5, NOTE_DS5, NOTE_E5, NOTE_F5, NOTE_FS5, NOTE_G5, NOTE_GS5, NOTE_A5
};

int note = 12;
char s[] = "00000";

void setup()
{
    Serial.begin(9600);
    for(int i = 0; i <= 5; i++){
      pinMode(i, OUTPUT);
    }
    for(int i = 9; i < 13; i++){
      pinMode(i, INPUT);
    }

    // iterate over the notes of the melody:

}

void loop(){
  sendBinary(hc.dist());
  readBinary();
  if(note > 12){
    noTone(6);
  }else{
     tone(6, scale[note]);
  }
}

void sendBinary(int input){
    for (int i = 6; i >= 0; i--) {
        int b = input >> i;
        if (b & 1){
          digitalWrite(i, HIGH);
          Serial.print("1");
        }else{
          digitalWrite(i, LOW);
          Serial.print("0");
          }
        }
        Serial.println();
        delay(1000);
    }

void readBinary(){

    for (int i = 5; i > 0; i--){
      s[i] = "00000";
      if(digitalRead(i+8) == HIGH){
          s[i] = '1';
          Serial.print("1");
        }else{
          s[i] = '0';
          Serial.print("0");
        }
      }
      Serial.println();

      note = 0;
      
      for (int i=4; i <= 0; i--)
      {
        if (s[i] == '1'){
          note = note + pow(2, i);
        }
      }
    Serial.println(current);
    delay(1000);
  }
