/***********************************************************************
 *       __                                                          _
 *      / /        _____  __    __  _          _   (_)   ________   | |
 *     / /____   / _____) \ \  / / | |   __   | |  | |  (  ______)  | |_____
 *    / / ___/  | |_____   \ \/ /  | |  /  \  | |  | |  | |______   |  ___  |
 *   / /\ \     | |_____|   \  /   | | / /\ \ | |  | |  (_______ )  | |   | |
 *  / /  \ \__  | |_____    / /    | |/ /  \ \| |  | |   ______| |  | |   | |
 * /_/    \___\  \______)  /_/      \__/    \__/   |_|  (________)  |_|   |_|
 *
 *
 * KeyWay Tech firmware
 *
 * Copyright (C) 2015-2020
 *
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, in version 3.
 * learn more you can see <http://www.gnu.org/licenses/>.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE.
 *
 *
 * [Title]     Photosensitive Light Experiment
 * [diagram]
 *            220Ω  ===================   LED
 *            10kΩ  ===================   Photovaristor
 *
 */
int photocellPin = 2; // photocell to anallog pin 2
int photocellVal = 0; // photocell variable
int minLight = 200;   
int ledPin = 12;
int ledState = 0; 
 
void setup() {
  pinMode(ledPin, OUTPUT); 
  Serial.begin(9600);
}
 
void loop() {
  photocellVal = analogRead(photocellPin);
  Serial.println(photocellVal);   
   
  if (photocellVal < minLight && ledState == 0) {
    digitalWrite(ledPin, HIGH); // turn on LED
    ledState = 1;
  }
   
  if (photocellVal > minLight && ledState == 1) {
    digitalWrite(ledPin, LOW); // turn off LED
    ledState = 0;
  }  
   
  delay(100);       
}
