//Avec l'aide de https://www.arduino.cc/en/Tutorial/MidiDevice

#include "MIDIUSB.h"
#define NUM_SW 16

const uint8_t S1 = 0;
const uint8_t S2 = 1;
const uint8_t S3 = 2;
const uint8_t S4 = 3;
const uint8_t S5 = 4;
const uint8_t S6 = 5;
const uint8_t S7 = 6;
const uint8_t S8 = 7;
const uint8_t S9 = 8;
const uint8_t S10 = 9;
const uint8_t S11 = 10;
const uint8_t S12 = 11;
const uint8_t S13 = A0;
const uint8_t S14 = A1;
const uint8_t S15 = A2;
const uint8_t S16 = A3;

const uint8_t S[NUM_SW] = {S1, S2, S3, S4, S5, S6, S7, S8, S9, S10, S11, S12, S13, S14, S15, S16};
const byte note[NUM_SW] = {48, 49, 50, 51, 52, 43, 55, 56, 57, 58, 59, 60, 61, 62, 63};

uint8_t pressedSw = 0x00;
uint8_t previousSw = 0x00;
int vel = 127;
int cha = 0;

void setup(){
  for (int i = 0; i < NUM_SW; i++)
    pinMode(S[i], INPUT);
}

void loop(){
  readSwitches();
  playNotes();
}
/*
void controlChange(byte channel, byte control, byte value) {
  midiEventPacket_t event = {0x0B, 0xB0 | channel, control, value};
  MidiUSB.sendMIDI(event);
*/



void readSwitches(){
  for (int i = 0; i < NUM_SW; i++){
    if (digitalRead(S[i]) == HIGH){
      bitWrite(pressedSw, i, 1);
      delay(50);
    }
    else
      bitWrite(pressedSw, i, 0);
  }
}

void playNotes(){
  for (int i = 0; i < NUM_SW; i++){
    if (bitRead(pressedSw, i) != bitRead(previousSw, i)){
      if (bitRead(pressedSw, i)){
        bitWrite(previousSw, i, 1);
        noteOn(cha, note[i], vel);
        MidiUSB.flush();
      }
      else{
        bitWrite(previousSw, i, 0);
        noteOff(cha, note[i], vel);
        MidiUSB.flush();
      }
    }
  }
}

void noteOn(byte channel, byte pitch, byte velocity){
  midiEventPacket_t noteOn = {0x09, 0x90 | channel, pitch, velocity};
  MidiUSB.sendMIDI(noteOn);
}

void noteOff(byte channel, byte pitch, byte velocity){
  midiEventPacket_t noteOff = {0x08, 0x80 | channel, pitch, velocity};
  MidiUSB.sendMIDI(noteOff);
}
