/********************************************************************
 Software License Agreement:

 The software supplied herewith by Microchip Technology Incorporated
 (the "Company") for its PIC(R) Microcontroller is intended and
 supplied to you, the Company's customer, for use solely and
 exclusively on Microchip PIC Microcontroller products. The
 software is owned by the Company and/or its supplier, and is
 protected under applicable copyright laws. All rights are reserved.
 Any use in violation of the foregoing restrictions may subject the
 user to criminal sanctions under applicable laws, as well as to
 civil liability for the breach of the terms and conditions of this
 license.

 THIS SOFTWARE IS PROVIDED IN AN "AS IS" CONDITION. NO WARRANTIES,
 WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING, BUT NOT LIMITED
 TO, IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
 PARTICULAR PURPOSE APPLY TO THIS SOFTWARE. THE COMPANY SHALL NOT,
 IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL OR
 CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 *******************************************************************/

#include <xc.h>
#include <stdbool.h>
#include <buttons.h>

/*** Button Definitions *********************************************/
#define S1_PORT  PORTAbits.RA3

#define S_A5_PORT  PORTAbits.RA5 //flippers      
#define S_A4_PORT  PORTAbits.RA4

#define S_A3_PORT  PORTAbits.RA3 //player
#define S_C5_PORT  PORTCbits.RC5 //launch
#define S_C2_PORT  PORTCbits.RC2 //admin    

#define S_C4_PORT  PORTCbits.RC4 //mercury switches      
#define S_C3_PORT  PORTCbits.RC3      

#define S_TRISA5  TRISAbits.TRISA5 //flippers 
#define S_TRISA4  TRISAbits.TRISA4

#define S_TRISA3  TRISAbits.TRISA3 //player
#define S_TRISC5  TRISCbits.TRISC5 //launch
#define S_TRISC2  TRISCbits.TRISC2 //admin

#define S_TRISC4  TRISCbits.TRISC4 //mercury switches
#define S_TRISC3  TRISCbits.TRISC3

#define BUTTON_PRESSED      0
#define BUTTON_NOT_PRESSED  1

#define PIN_INPUT           1
#define PIN_OUTPUT          0

#define PIN_DIGITAL         1
#define PIN_ANALOG          0

/*********************************************************************
* Function: bool BUTTON_IsPressed(BUTTON button);
*
* Overview: Returns the current state of the requested button
*
* PreCondition: button configured via BUTTON_SetConfiguration()
*
* Input: BUTTON button - enumeration of the buttons available in
*        this demo.  They should be meaningful names and not the names 
*        of the buttons on the silkscreen on the board (as the demo 
*        code may be ported to other boards).
*         i.e. - ButtonIsPressed(BUTTON_SEND_MESSAGE);
*
* Output: TRUE if pressed; FALSE if not pressed.
*
********************************************************************/
bool BUTTON_IsPressed(BUTTON button)
{
    switch(button)
    {
//        case BUTTON_S1:
//            return ( (S1_PORT == BUTTON_PRESSED) ? true : false);
//
//        case BUTTON_NONE:
//            return false;
        
        case BUTTON_LEFT:
            return ( (S_A5_PORT == BUTTON_PRESSED) ? true : false);
            
        case BUTTON_RIGHT:
            return ( (S_A4_PORT == BUTTON_PRESSED) ? true : false);
           
        case BUTTON_PLAYER:
            return ( (S_A3_PORT == BUTTON_PRESSED) ? true : false);
            
        case BUTTON_LAUNCH:
            return ( (S_C5_PORT == BUTTON_PRESSED) ? true : false);
            
        case BUTTON_ADMIN:
            return ( (S_C2_PORT == BUTTON_PRESSED) ? true : false);
            
        case SWITCH_LEFT_TILT:
            return ( (S_C4_PORT == BUTTON_PRESSED) ? true : false);
            
        case SWITCH_RIGHT_TILT:
            return ( (S_C3_PORT == BUTTON_PRESSED) ? true : false);
            
        case BUTTON_NONE:
            return false;
    }
    
    return false;
}

/*********************************************************************
* Function: void BUTTON_Enable(BUTTON button);
*
* Overview: Returns the current state of the requested button
*
* PreCondition: button configured via BUTTON_SetConfiguration()
*
* Input: BUTTON button - enumeration of the buttons available in
*        this demo.  They should be meaningful names and not the names
*        of the buttons on the silkscreen on the board (as the demo
*        code may be ported to other boards).
*         i.e. - ButtonIsPressed(BUTTON_SEND_MESSAGE);
*
* Output: None
*
********************************************************************/
void BUTTON_Enable(BUTTON button)
{
    switch(button)
    {
//        case BUTTON_S1:
//            break;
//
//        case BUTTON_NONE:
//            break;
        
        case BUTTON_LEFT:
            S_TRISA5 = PIN_INPUT;
            break;    

        case BUTTON_RIGHT:
            S_TRISA4 = PIN_INPUT;
            break;    

        case BUTTON_PLAYER:
            //S_TRISA3 = PIN_INPUT; Is always input on the pic16f1455
            break;               
            
        case BUTTON_LAUNCH:
            S_TRISC5 = PIN_INPUT;
            break;               
            
        case BUTTON_ADMIN:
            S_TRISC2 = PIN_INPUT;
            break;               
            
        case SWITCH_LEFT_TILT:
            S_TRISC4 = PIN_INPUT;
            break;               
            
        case SWITCH_RIGHT_TILT:
            S_TRISC3 = PIN_INPUT;
            break;               
            
        case BUTTON_NONE:
            break;
        
    }
}
