   
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
  NOTE_A4, NOTE_AS4, NOTE_B4, NOTE_C5, NOTE_CS5, NOTE_D5, NOTE_DS5, NOTE_E5, NOTE_F5, NOTE_FS5, NOTE_G5, NOTE_GS5, NOTE_A5
};

int note = 12;
int ratio = 4;
char s[] = "00000";

void setup()
{
    Serial.begin(9600);
    for(int i = 0; i < 6; i++){
      pinMode(i, OUTPUT);
    }
    for(int i = 9; i < 14; i++){
      pinMode(i, INPUT);
    }
     pinMode(6, OUTPUT);
    // iterate over the notes of the melody:

}

void loop(){

  /*
  sendBinary(hc.dist());
  readBinary();
  if(current > 12){
    noTone(6);
  }else{
     tone(6, scale[current]);
  }
  */
  float current_distance = hc.dist();
  sendBinary(hc.dist());
    if( hc.dist() > (14*ratio) ){
      noTone(6);
      Serial.println("out of range");
    }else{
      //tone(6, 10*hc.dist() + 100);
      for(int i = 0; i < 13; i++){
        if( hc.dist() > (i*ratio) && hc.dist() < ratio*( i + 1 )){
          tone(6, scale[i]);
          Serial.println(i);
        }
      }
    }
    delay(1000);
}
  

void sendBinary(int input){
    for (int i = 5; i >= 0; i--) {
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
    }

void readBinary(){

    for (int i = 5; i > 0; i--){
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
    Serial.println(note);
    delay(1000);
  }
