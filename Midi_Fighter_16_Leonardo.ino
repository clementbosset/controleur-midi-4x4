/*---------------------------------------------------------

            Projet contrôleur MIDI 16 boutons
                   par Clément Bosset

              Arduino Leonardo + 16 boutons

---------------------------------------------------------*/


//Librairie MIDIUSB (https://github.com/arduino-libraries/MIDIUSB)
//Inclusion de la librairie MidiUSB:
#include "MIDIUSB.h"

//Premier paramètre: Type d'évènement (0x09 = note on, 0x08 = note off)
//Second paramètre: note on/note off combiné au canal (0 - 15 = soit dans l'usage 1 - 16)
//Troisième paramètre: Numéro de la note (0 - 127) (https://musicordes.fr/tableau-frequences-numero-de-note-midi/)
//Quatrième paramètre: Vélocité (0 - 127)
//Fonction noteOn:
void noteOn(byte channel, byte pitch, byte velocity){
  midiEventPacket_t noteOn = {0x09, 0x90 | channel, pitch, velocity};
  MidiUSB.sendMIDI(noteOn);
}

//Fonction noteOff:
void noteOff(byte channel, byte pitch, byte velocity){
  midiEventPacket_t noteOff = {0x08, 0x80 | channel, pitch, velocity};
  MidiUSB.sendMIDI(noteOff);
}

//Fonction setup: (définitions initiales)
void setup() {
//Utilisations des pins comme entrées:
  pinMode(0, INPUT);  //S1
  pinMode(1, INPUT);  //S2
  pinMode(2, INPUT);  //S3
  pinMode(3, INPUT);  //S4
  pinMode(4, INPUT);  //S5
  pinMode(5, INPUT);  //S6
  pinMode(6, INPUT);  //S7
  pinMode(7, INPUT);  //S8
  pinMode(8, INPUT);  //S9
  pinMode(9, INPUT);  //S10
  pinMode(10, INPUT); //S11
  pinMode(11, INPUT); //S12
  pinMode(A0, INPUT); //S13
  pinMode(A1, INPUT); //S14
  pinMode(A2, INPUT); //S15
  pinMode(A3, INPUT); //S16

//Ouverture du port serie (observation test moniteur série)
  Serial.begin(115200);

}

//Fonction loop: (attente en boucle d'une action)
void loop() {

//Nomination lecture boutons
int S1 = digitalRead(0);
int S2 = digitalRead(1);
int S3 = digitalRead(2);
int S4 = digitalRead(3);
int S5 = digitalRead(4);
int S6 = digitalRead(5);
int S7 = digitalRead(6);
int S8 = digitalRead(7);
int S9 = digitalRead(8);
int S10 = digitalRead(9);
int S11 = digitalRead(10);
int S12 = digitalRead(11);
int S13 = digitalRead(A0);
int S14 = digitalRead(A1);
int S15 = digitalRead(A2);
int S16 = digitalRead(A3);

//Généralisation de valeurs
int cha = 0; //Canal
int vel = 127; //Vélocité

//Conditions (details dans "notes.txt")
  //Bouton 1
    if(S1==HIGH){                //Si S1 est appuyé...
      Serial.println("Note on"); //Test moniteur série
      noteOn(cha, 48, vel);      //Note activée (Canal 0, Note C, Velocité 127)
      MidiUSB.flush();           //Cette fonction force la couche USB à envoyer immédiatement les données
    }
    else{                        //Sinon...
      Serial.println("Note off");
      noteOff(cha, 48, vel);     //Note désactivée
      MidiUSB.flush();
    }
  //Bouton 2
    if(S2==HIGH){
      Serial.println("Note on");
      noteOn(cha, 49, vel);
      MidiUSB.flush();
    }
    else{
      Serial.println("Note off");
      noteOff(cha, 49, vel);
      MidiUSB.flush();
    }
  //Bouton 3
    if(S3==HIGH){
      noteOn(cha, 50, vel);
      MidiUSB.flush();
    }
    else{
      noteOff(cha, 50, vel);
      MidiUSB.flush();
    }
  //Bouton 4
    if(S4==HIGH){
      noteOn(cha, 51, vel);
      MidiUSB.flush();
    }
    else{
      noteOff(cha, 51, vel);
      MidiUSB.flush();
    }
  //Bouton 5
    if(S5==HIGH){
      noteOn(cha, 52, vel);
      MidiUSB.flush();
    }
    else{
      noteOff(cha, 52, vel);
      MidiUSB.flush();
    }
  //Bouton 6
    if(S6==HIGH){
      noteOn(cha, 53, vel);
      MidiUSB.flush();
    }
    else{
      noteOff(cha, 53, vel);
      MidiUSB.flush();
    }
  //Bouton 7
    if(S7==HIGH){
      noteOn(cha, 54, vel);
      MidiUSB.flush();
    }
    else{
      noteOff(cha, 54, vel);
      MidiUSB.flush();
    }
  //Bouton 8
    if(S8==HIGH){
      noteOn(cha, 55, vel);
      MidiUSB.flush();
    }
    else{
      noteOff(cha, 55, vel);
      MidiUSB.flush();
    }
  //Bouton 9
    if(S9==HIGH){
      noteOn(cha, 56, vel);
      MidiUSB.flush();
    }
    else{
      noteOff(cha, 56, vel);
      MidiUSB.flush();
    }
  //Bouton 10
    if(S10==HIGH){
      noteOn(cha, 57, vel);
      MidiUSB.flush();
    }
    else{
      noteOff(cha, 57, vel);
      MidiUSB.flush();
    }
  //Bouton 11
    if(S11==HIGH){
      noteOn(cha, 58, vel);
      MidiUSB.flush();
    }
    else{
      noteOff(cha, 58, vel);
      MidiUSB.flush();
    }
  //Bouton 12
    if(S12==HIGH){
      noteOn(cha, 59, vel);
      MidiUSB.flush();
    }
    else{
      noteOff(cha, 59, vel);
      MidiUSB.flush();
    }
  //Bouton 13
    if(S13==HIGH){
      noteOn(cha, 60, vel);
      MidiUSB.flush();
    }
    else{
      noteOff(cha, 60, vel);
      MidiUSB.flush();
    }
  //Bouton 14
    if(S14==HIGH){
      noteOn(cha, 61, vel);
      MidiUSB.flush();
    }
    else{
      noteOff(cha, 61, vel);
      MidiUSB.flush();
    }
  //Bouton 15
    if(S15==HIGH){
      noteOn(cha, 62, vel);
      MidiUSB.flush();
    }
    else{
      noteOff(cha, 62, vel);
      MidiUSB.flush();
    }
  //Bouton 16
    if(S16==HIGH){
      noteOn(cha, 63, vel);
      MidiUSB.flush();
    }
    else{
      noteOff(cha, 63, vel);
      MidiUSB.flush();
    }

}


/*---------------------------------------------------------

                       Fin du code.

---------------------------------------------------------*/
