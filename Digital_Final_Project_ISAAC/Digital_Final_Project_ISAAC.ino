#include <HCSR04.h>

//Code by Isaac Shaw
/*
Integration with FPGA, ultrasonic sensor reads distance
This code reads ultrasonic input, converts it to binary parallel, then sends it to the FPGA
The FPGA does logic to determine what note should be played then sends binary number in binary parallel
Arduino then converts this number into a usable tone for the buzzer and sends it out.
*/
#include "pitches.h"


HCSR04 hc(7, 8); //initialisation class HCSR04 (trig pin , echo pin)

// 12 note scale
int scale[] = {
  NOTE_A4, NOTE_AS4, NOTE_B4, NOTE_C4, NOTE_CS5, NOTE_D5, NOTE_DS5, NOTE_E5, NOTE_F5, NOTE_FS5, NOTE_G5, NOTE_GS5, NOTE_A5
};

int current = 12;
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
  if(current > 12){
    noTone(6);
  }else{
     tone(6, scale[current]);
  }
  /*
  if(hc.dist() < 41 || hc.dist() > 2){
      if(hc.dist() > 2 && hc.dist() < 5){
        current_note = 0;
      }else if(hc.dist() > 5 && hc.dist() < 8){
        current_note = 1;
      }else if(hc.dist() > 8 && hc.dist() < 11){
        current_note = 2;
      }else if(hc.dist() > 11 && hc.dist() < 14){
        current_note = 3;
      }else if(hc.dist() > 14 && hc.dist() < 17){
        current_note = 4;
      }else if(hc.dist() > 17 && hc.dist() < 20){
        current_note = 5;
      }else if(hc.dist() > 20 && hc.dist() < 23){
        current_note = 6;
      }else if(hc.dist() > 23 && hc.dist() < 26){
        current_note = 7;
      }else if(hc.dist() > 26 && hc.dist() < 29){
        current_note = 8;
      }else if(hc.dist() > 29 && hc.dist() < 32){
        current_note = 9;
      }else if(hc.dist() > 32 && hc.dist() < 35){
        current_note = 10;
      }else if(hc.dist() > 35 && hc.dist() < 38){
        current_note = 11;
      }else if(hc.dist() > 38 && hc.dist() < 41){
        current_note = 12;
      }else if(hc.dist() > 41 || hc.dist() < 2){
        current_note = 13;
      }
      tone(6, scale[current_note]);
      //analogWrite(6, scale[current_note]);
    }else{
      analogWrite(6, LOW);
    }
    delay(200);
    */
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
      s[i] = '0';
      if(digitalRead(i+8) == HIGH){
          s[i] = '1';
          Serial.print("1");
        }else{
          s[i] = '0';
          Serial.print("0");
        }
      }
      Serial.println();

      current = 0;
      
      for (int i=5; i < 0; i--)
      {
        current *= 2; // double the result so far
        if (s[i] == '1'){
          current++;  //add 1 if needed
        }
      }
    Serial.println(current);
    delay(1000);
  }
