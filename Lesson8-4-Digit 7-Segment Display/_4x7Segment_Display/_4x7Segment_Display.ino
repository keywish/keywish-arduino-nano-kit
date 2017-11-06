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
 * [Title]     4x8bit Numeric led Display the count down numble .
 * [Diagram]
 *         Arduino PIN 2   ===================  8bit Numeric led a
 *         Arduino PIN 3   ===================  8bit Numeric led b
 *         Arduino PIN 4   ===================  8bit Numeric led c
 *         Arduino PIN 5   ===================  8bit Numeric led d
 *         Arduino PIN 6   ===================  8bit Numeric led e
 *         Arduino PIN 7   ===================  8bit Numeric led f
 *         Arduino PIN 8   ===================  8bit Numeric led g
 *         Arduino PIN 9   ===================  8bit Numeric led h
 *         Arduino PIN 10   ===================  8bit Numeric led D1
 *         Arduino PIN 11  ===================  8bit Numeric led D2
 *         Arduino PIN 12  ===================  8bit Numeric led D3
 *         Arduino PIN 13  ===================  8bit Numeric led D4
 */
#define  LED_A   2       // define Arduino GPIO1 for led a
#define  LED_B   3       // define Arduino GPIO2 for led b
#define  LED_C   4       // define Arduino GPIO3 for led c
#define  LED_D   5       // define Arduino GPIO4 for led d
#define  LED_E   6       // define Arduino GPIO5 for led e
#define  LED_F   7       // define Arduino GPIO6 for led f
#define  LED_G   8       // define Arduino GPIO7 for led g
#define  LED_H   9       // define Arduino GPIO8 for led h
#define  LED_D1  10
#define  LED_D2  11
#define  LED_D3  12
#define  LED_D4  13

#define  COM_PORT   2     //  1:common negative port   2: common positive port
char LED_PIN[8]    = {  LED_A , LED_B , LED_C , LED_D , LED_E , LED_F , LED_G , LED_H } ;
char LED_SELECT[4] = {  LED_D1 , LED_D2 , LED_D3 , LED_D4  } ;

char disp[4] = { 0 , 0 , 0 , 0 } ;         // display array value
int display_dat = 59, count = 0 ;
char LED_Display_Value[][3]  =
{ //value negative positive
    { '0', 0x3F , 0xC0 } ,
    { '1', 0x06 , 0xF9 } ,
    { '2', 0x5B , 0xA4 } ,
    { '3', 0x4F , 0xB0 } ,
    { '4', 0x66 , 0x99 } ,
    { '5', 0x6D , 0x92 } ,
    { '6', 0x7D , 0x82 } ,
    { '7', 0x07 , 0xF8 } ,
    { '8', 0x7F , 0x80 } ,
    { '9', 0x6F , 0x90 } ,
    {  0 , 0x00 , 0xFF }
};
// turn off all led
void  DisplayOff(void)
{
    int i ;
    for( i = 0 ; i < 8 ; i++)
    digitalWrite(LED_PIN[i],LOW);
    for( i = 0 ; i < 4 ; i++)
    digitalWrite(LED_SELECT[i],LOW);
}

// convert Numbers to  led display  code
char  GetDisplayValue(char Array[][3] , char DisplayChar )
{
    int i = 0 ;
    for( i = 0 ; i < 10 ; i++)
    {
        if( Array[i][0] == DisplayChar )
            return Array[i][COM_PORT] ;    //return the common positive port value
    }
    return 0 ;
}
void LED_Display ( char ch)
{
    int i ;
    for( i = 0 ; i < 8 ; i++)
    {
        if(  ch & ( 1 << i ) )
        {
            digitalWrite(LED_PIN[i] , HIGH);
        }else{
            digitalWrite(LED_PIN[i],LOW);
       }
    }
}

//convert  integer nubles to ASCII
void numble2dis( int numble )
{
    int numble_bit = 0 ;
    int bit_base = 1000 ;
    for( numble_bit = 0 ; numble_bit < 4 ; numble_bit++ )
    {
        if( numble/bit_base != 0)
        {
            disp[numble_bit] = numble/bit_base + '0'  ;    // integer date convert to ASCII
            numble = numble%bit_base ;
        }else
        {
            disp[numble_bit] = '0';                 // led display none
        }
        bit_base = bit_base / 10 ;
    }
}
void setup()
{
    int i;
    for( i = 0 ; i < 8 ; i++ )
    pinMode( LED_PIN[i] ,OUTPUT ) ;         // set all led diplay array pin output mode
    for( i = 0 ; i < 4 ; i++ )
    pinMode( LED_SELECT[i] ,OUTPUT ) ;      // set led select output mode
    DisplayOff();
    numble2dis(59);
}
void loop()
{
    int i ;
    if( count++ > 50 )
    {
        display_dat-- ;
        numble2dis(display_dat);   // integer convert to ASCII
        count = 0 ;
    }
    for( i = 0  ; i < 4 ; i++ )
    {
        LED_Display( GetDisplayValue(LED_Display_Value,disp[i]) ) ;
        digitalWrite(LED_SELECT[i] ,HIGH );
        delay(5);
        digitalWrite(LED_SELECT[i] ,LOW );// you must turn off
    }
    if(display_dat == 0 )
    while(1);
}
