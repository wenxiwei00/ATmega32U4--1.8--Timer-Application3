/* Name: main.c
 * Author: <insert your name here>
 * Copyright: <insert your copyright message here>
 * License: <insert your license reference here>
 */

#include "MEAM_general.h"  // includes the resources included in the MEAM_general.h file
#define MAX_PWM 1023 // I choose mode 7


void setPWMMode(){
    _clockdivide(0);
    set(TCCR3B, CS31); //set clock of counter equal to 2MHz (i.e. set prescaler=8)

    DDRC |= 0x40; //set port PC6 as output

    set(TCCR3A, COM3A1); //	clear at OCR3A, set at rollover

    set(TCCR3B, WGM32); //set timer to mode 7.
    set(TCCR3A, WGM31);
    set(TCCR3A, WGM30);
}


void setDifferentIntensity(uint8_t intensity){
    OCR3A = (intensity / 100.0) * MAX_PWM;    //50% * 1023
}

void changeIntensity(uint8_t startIntensity, uint8_t endIntensity, uint16_t time){
    int16_t steps = 100; // increase and decrease smoothly
    int16_t stepTime = time / steps; //increase or decrease the intensity every xx ms

    int16_t i;
    for (i = 0; i < steps; i++){ 
        uint8_t nowIntensity = startIntensity + (i * (endIntensity - startIntensity) / steps) ;  // intensity now = startIntensity - i*changed intensity each time
        setDifferentIntensity(nowIntensity);
        _delay_ms(stepTime);
    }
}


void heartbeatToStop(void){
    int8_t j;
    for (j=0; j<=20; j++){
        changeIntensity(0, 100 - 5*j, 100);
        changeIntensity(100-5*j, 0, 100);
        changeIntensity(0, 50-2.5*j, 100);
        changeIntensity(50-2.5*j, 0, 100);
        _delay_ms(1000);
    }
}

int main(void){
    setPWMMode();
    while(1){
        heartbeatToStop();
    }
    return 0;
}