/*******************************************************************************
Copyright 2016 Microchip Technology Inc. (www.microchip.com)

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.

To request to license the code under the MLA license (www.microchip.com/mla_license), 
please contact mla_licensing@microchip.com
*******************************************************************************/

#include <xc.h>
#include "leds.h"
#include "io_mapping.h"

#define _XTAL_FREQ 16000000

/*
 Ensure LEDs are enabled before calling these functions.
 */

void flash_led_red()
{
    for (uint8_t x=0; x<3; x++){
        LED_On(LED_LAUNCH_BUTTON);
        __delay_ms(1000);
        LED_Off(LED_LAUNCH_BUTTON);
        __delay_ms(1000);        
    }
}

void flash_led_green()
{
    for (uint8_t x=0; x<3; x++){
        LED_On(LED_PLAYER_BUTTON);
        __delay_ms(1000);
        LED_Off(LED_PLAYER_BUTTON);
        __delay_ms(1000);
    }
    
}

