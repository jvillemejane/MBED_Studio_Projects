/****************************************************************************/
/*  CONFIG_SPOT_MIDI module library                                         */
/****************************************************************************/
/*  LEnsE / Julien VILLEMEJANE       /   Institut d'Optique Graduate School */
/****************************************************************************/

#include "CONFIG_SPOT_MIDI.h"
#include <cstdint>

/* Variables globales */
DMX_spots       spots[NB_SPOTS];
uint8_t         spot_[13];

// TYPE / ADD / CHAN / GPE

/* Copie d'un tableau d'entier */
void    cpyTab(uint8_t* source, uint8_t* dest, int size){
    for(int k = 0; k < size; k++){
        dest[k] = source[k];
    }
}

/* Configuration des spots */
void    configSpots(void){
    for(int k = 0; k < NB_SPOTS; k++){
        spots[k].setAdd(type_spot[k][1]);
        spots[k].setChan(type_spot[k][2]);
        spots[k].setGroup(type_spot[k][3]);
        switch(type_spot[k][0]){
            case 1:
                cpyTab((uint8_t*)spotLEDPARTY, spot_, 13);
                break;            
            case 2:
                cpyTab((uint8_t*)spotRenkLVPT, spot_, 13);
                break;          
            case 3:
                cpyTab((uint8_t*)spotSLS7, spot_, 13);
                break;          
            case 4:
                cpyTab((uint8_t*)spotTMH, spot_, 13);
                break;
            default:
                break;
        }
        
// DIM / STR / R / G / B / W / A / UV / MODE / DEF_MOD / PAN / TILT / SPEED
        spots[k].setMode(spot_[8]);
        spots[k].setChanDimmer(spot_[0]);
        spots[k].setDimmerMin(0);
        spots[k].setDimmerMax(255);
        spots[k].setChanRGB(spot_[2], spot_[3], spot_[4]);
        spots[k].setChanW(spot_[5]);
        spots[k].setChanA(spot_[6]);
        spots[k].setChanUV(spot_[7]);
        spots[k].setChanNoFuncMode(spot_[8], spot_[9]);
        spots[k].setChanPan(spot_[10]);
        spots[k].setChanTilt(spot_[11]);
        spots[k].setChanPTSpeed(spot_[12]);
    }
}


/* Test des couleurs */
void    testConfigSpots(void){
    for(int k = 0; k < NB_SPOTS; k++){
        spots[k].setModeNoFunc();
        spots[k].setDimmer(200);
        spots[k].setRGB(0,255,255);
    }    
}