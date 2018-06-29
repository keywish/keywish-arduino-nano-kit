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
 * [Title]      SW520D Ball Switch
 * [Diagram]
 *         Arduino PIN A5   ===================  SW520D PIN 1
 *         Arduino PIN GND  ===================  SW520D PIN 2
 *         Arduino PIN A5   ===================  10kΩresistor PIN 1
 *         Arduino PIN 5V   ===================  10kΩresistor PIN 2
 *         Arduino PIN 13   ===================  LED PIN +
 *         Arduino PIN GND  ===================  LED PIN -
 */
int Led=13;
int buttonpin=A5;
int val=0;
void setup() 
{  
  pinMode(Led,OUTPUT);
  pinMode(buttonpin,INPUT);
}  
void loop() 
{  
    val=analogRead(buttonpin);
    if (val>512) {  
        digitalWrite(Led,HIGH); 
    } 
    else {  
        digitalWrite(Led,LOW); 
    } 
}
