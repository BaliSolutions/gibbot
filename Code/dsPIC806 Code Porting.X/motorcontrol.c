#include <stdio.h>
#include <stdlib.h>
#include <p33Exxxx.h>
#include "gibbot.h"

int direction;

void High(int pin){
    if(pin == 1){
        IOCON1bits.OVRENH = 0;  //Turn overide off for high pin
        IOCON1bits.OVRENL = 0;  //Turn overide off for low pin
    } else if(pin == 2){
        IOCON2bits.OVRENH = 0;  //Turn overide off for high pin
        IOCON2bits.OVRENL = 0;  //Turn overide off for low pin
    } else if(pin == 3){
        IOCON3bits.OVRENH = 0;  //Turn overide off for high pin
        IOCON3bits.OVRENL = 0;  //Turn overide off for low pin
    }
}

void Low(int pin){
    if(pin == 1){
        IOCON1bits.OVRDAT1 = 0; // PWM High Pin override output is off
        IOCON1bits.OVRDAT0 = 1; // PWM Low Pin override output is on
        IOCON1bits.OVRENH = 1;  //Turn overide on for high pin
        IOCON1bits.OVRENL = 1;  //Turn overide on for low pin
    } else if(pin == 2){
        IOCON2bits.OVRDAT1 = 0; // PWM High Pin override output is off
        IOCON2bits.OVRDAT0 = 1; // PWM Low Pin override output is on
        IOCON2bits.OVRENH = 1;  //Turn overide on for high pin
        IOCON2bits.OVRENL = 1;  //Turn overide on for low pin
    } else if(pin == 3){
        IOCON3bits.OVRDAT1 = 0; // PWM High Pin override output is off
        IOCON3bits.OVRDAT0 = 1; // PWM Low Pin override output is on
        IOCON3bits.OVRENH = 1;  //Turn overide on for high pin
        IOCON3bits.OVRENL = 1;  //Turn overide on for low pin
    }
}

void Float(int pin){
    if(pin == 1){
        IOCON1bits.OVRDAT1 = 0; // PWM High Pin override output is off
        IOCON1bits.OVRDAT0 = 0; // PWM Low Pin override output is on
        IOCON1bits.OVRENH = 1;  //Turn overide on for high pin
        IOCON1bits.OVRENL = 1;  //Turn overide on for low pin
    } else if(pin == 2){
        IOCON2bits.OVRDAT1 = 0; // PWM High Pin override output is off
        IOCON2bits.OVRDAT0 = 0; // PWM Low Pin override output is on
        IOCON2bits.OVRENH = 1;  //Turn overide on for high pin
        IOCON2bits.OVRENL = 1;  //Turn overide on for low pin
    } else if(pin == 3){
        IOCON3bits.OVRDAT1 = 0; // PWM High Pin override output is off
        IOCON3bits.OVRDAT0 = 0; // PWM Low Pin override output is on
        IOCON3bits.OVRENH = 1;  //Turn overide on for high pin
        IOCON3bits.OVRENL = 1;  //Turn overide on for low pin
    }
}

//Commutation pattern for the Maxon Motor
void state5() {
    if(direction){
    High(1);  Low(2);   Float(3);
    } else{
    Low(1);  High(2);   Float(3);
    }
}
void state1() {
    if(direction){
    High(1);  Float(2); Low(3);
    } else{
    Low(1);  Float(2); High(3);
    }
}
void state3() {
    if(direction){
    Float(1); High(2);  Low(3);
    } else {
    Float(1); Low(2);  High(3);
    }
}
void state2() {
    if(direction){
    Low(1);   High(2);  Float(3);
    } else {
    High(1);   Low(2);  Float(3);
    }
}
void state6() {
    if(direction){
    Low(1);   Float(2); High(3);
    } else {
    High(1);   Float(2); Low(3);
    }
}
void state4() {
    if(direction){
    Float(1); Low(2);   High(3);
    } else {
    Float(1); High(2);   Low(3);
    }
}

//Off State
void state0() { Float(1); Float(2); Float(3);}
