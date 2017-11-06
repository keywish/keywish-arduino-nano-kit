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
 * [Title]     led Brightness controled by continuous potentiometer
 * [diagram]
 *           Arduino PIN A0   ===================   potentiometer pin 2
 *           Arduino PIN 11  ===================   LED
 */

int  ADPIN  = A0 ;
int  PWM_LEDPIN = 10 ;
int  value = 0 ;
float voltage = 0.0 ;
void setup()
{
    pinMode(ADPIN,INPUT);    // define ADPIN input PWM_LEDPIN output
    pinMode(PWM_LEDPIN,OUTPUT);
    Serial.begin(115200);    //Serial Baud rate is 115200
}
void loop()
{
    value =  analogRead(ADPIN);       //read analog pin raw data
    voltage = ( ( float )value )/1023 ;
    value = (int)voltage * 256 ;      //covert to voltage to PWM duty cycle
    analogWrite(PWM_LEDPIN,value);
    delay(1000);
}
