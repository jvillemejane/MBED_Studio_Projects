/****************************************************************************/
/*  CONFIG_SPOT_MIDI module library                                         */
/****************************************************************************/
/*  LEnsE / Julien VILLEMEJANE       /   Institut d'Optique Graduate School */
/****************************************************************************/

#include "CONFIG_SPOT_MIDI.h"
#include <cstdint>

/* Variables globales */
DMX_spots       spots[NB_SPOTS];
uint8_t         spot_[NB_PARAMS];

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
                cpyTab((uint8_t*)spotLEDPARTY, spot_, NB_PARAMS);
                break;            
            case 2:
                cpyTab((uint8_t*)spotRenkLVPT, spot_, NB_PARAMS);
                break;          
            case 3:
                cpyTab((uint8_t*)spotSLS7, spot_, NB_PARAMS);
                break;          
            case 4:
                cpyTab((uint8_t*)spotTMH, spot_, NB_PARAMS);
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
        spots[k].setChanSoundMode(spot_[13], false, spot_[14], spot_[15]);
        spots[k].setFadeMode(spot_[16]);
    }
}

/* Mise à jour des couleurs */
void    setAllColorSpots(uint8_t gpe, uint8_t color[]){
    for(int k = 0; k < NB_SPOTS; k++){
        if((spots[k].getGroup() == gpe) || (gpe == 0)){
            spots[k].setRGB(color[COLOR_POS_R], color[COLOR_POS_G], color[COLOR_POS_B]);
            if(spots[k].getChanA() != 0)    spots[k].setA(color[COLOR_POS_A]);
            if(spots[k].getChanW() != 0)    spots[k].setW(color[COLOR_POS_W]);
            if(spots[k].getChanUV() != 0)   spots[k].setUV(color[COLOR_POS_UV]);
        }
    }    
}

void    setGpeColorSpots(uint8_t note){
    for(int m_ch = 0; m_ch < MIDI_CH; m_ch++){
        uint8_t color_nb = key_colors[(note-1) * MIDI_CH + m_ch];
        printf("[%d] %d ", m_ch, color_nb);
        uint8_t c[6];
        getColor(color_nb, c);
        setAllColorSpots(m_ch+1, c);
    }
    printf("\r\n");
}

/* Mise à jour des couleurs R, G, B */
void    setAllColorRGBSpots(uint8_t gpe, uint8_t R, uint8_t G, uint8_t B){
    for(int k = 0; k < NB_SPOTS; k++){
        if((spots[k].getGroup() == gpe) || (gpe == 0)){
            spots[k].setRGB(R, G, B);
        }
    }    
}

/* Mise à jour des couleurs A, W, UV */
void    setAllColorAWUVSpots(uint8_t gpe, uint8_t A, uint8_t W, uint8_t UV){
    for(int k = 0; k < NB_SPOTS; k++){
        if((spots[k].getGroup() == gpe) || (gpe == 0)){
            if(spots[k].getChanA() != 0)    spots[k].setA(A);
            if(spots[k].getChanW() != 0)    spots[k].setW(W);
            if(spots[k].getChanUV() != 0)   spots[k].setUV(UV);
        }
    }       
}

/* Mise à jour des couleurs - R */
void    setAllRSpots(uint8_t gpe, uint8_t val){
    for(int k = 0; k < NB_SPOTS; k++){
        if((spots[k].getGroup() == gpe) || (gpe == 0)){
            spots[k].setR(val);
        }
    }
}
void    setAllGSpots(uint8_t gpe, uint8_t val){
    for(int k = 0; k < NB_SPOTS; k++){
        if((spots[k].getGroup() == gpe) || (gpe == 0)){
            spots[k].setG(val);
        }
    }
}
void    setAllBSpots(uint8_t gpe, uint8_t val){
    for(int k = 0; k < NB_SPOTS; k++){
        if((spots[k].getGroup() == gpe) || (gpe == 0)){
            spots[k].setB(val);
        }
    }
}
void    setAllASpots(uint8_t gpe, uint8_t val){
    for(int k = 0; k < NB_SPOTS; k++){
        if((spots[k].getGroup() == gpe) || (gpe == 0)){
            if(spots[k].getChanA() != 0)    spots[k].setA(val);
        }
    }
}
void    setAllWSpots(uint8_t gpe, uint8_t val){
    for(int k = 0; k < NB_SPOTS; k++){
        if((spots[k].getGroup() == gpe) || (gpe == 0)){
            if(spots[k].getChanW() != 0)    spots[k].setW(val);
        }
    }
}
void    setAllUVSpots(uint8_t gpe, uint8_t val){
    for(int k = 0; k < NB_SPOTS; k++){
        if((spots[k].getGroup() == gpe) || (gpe == 0)){
            if(spots[k].getChanUV() != 0)   spots[k].setUV(val);
        }
    }
}
/* Mise à jour du dimmer */
void    setAllDimmerSpots(uint8_t gpe, uint8_t dim){
    for(int k = 0; k < NB_SPOTS; k++){
        if((spots[k].getGroup() == gpe) || (gpe == 0)){
            if(spots[k].getChanDimmer() != 0)   spots[k].setDimmer(dim);
        }
    }
}



/* Mise à jour des positions */
void    setAllPosition(uint8_t gpe, uint8_t speed, uint16_t pan, uint16_t tilt){
    for(int k = 0; k < NB_SPOTS; k++){
        if((spots[k].getGroup() == gpe) || (gpe == 0)){
            if(spots[k].getChanPTSpeed() != 0)  spots[k].setPTSpeed(speed);
            if(spots[k].getChanPan() != 0)      spots[k].setPan(pan >> 8);
            if(spots[k].getChanPanF() != 0)     spots[k].setPanF(pan & 0xFF);
            if(spots[k].getChanTilt() != 0)     spots[k].setTilt(tilt >> 8);
            if(spots[k].getChanTiltF() != 0)    spots[k].setTiltF(pan & 0xFF);
        }
    }    
}

void    setAllPTSpeed(uint8_t gpe, uint8_t speed){
    for(int k = 0; k < NB_SPOTS; k++){
        if((spots[k].getGroup() == gpe) || (gpe == 0)){
            if(spots[k].getChanPTSpeed() != 0)  spots[k].setPTSpeed(speed);
        }
    }    
}

void    setAllPan(uint8_t gpe, uint8_t pan){
    for(int k = 0; k < NB_SPOTS; k++){
        if((spots[k].getGroup() == gpe) || (gpe == 0)){
            if(spots[k].getChanPan() != 0)      spots[k].setPan(pan);
        }
    }    
}

void    setAllTilt(uint8_t gpe, uint8_t tilt){
    for(int k = 0; k < NB_SPOTS; k++){
        if((spots[k].getGroup() == gpe) || (gpe == 0)){
            if(spots[k].getChanTilt() != 0)     spots[k].setTilt(tilt);
        }
    }    
}

void    setAllGlobalSpots(uint8_t gpe){
    setAllRSpots(gpe, global_r);
    setAllGSpots(gpe, global_g);
    setAllBSpots(gpe, global_b);
    setAllASpots(gpe, global_a);
    setAllWSpots(gpe, global_w);
    setAllUVSpots(gpe, global_uv);
}


void    setAllNoFuncMode(uint8_t gpe){
    ANNIV_mode_nofunc(gpe);
    /*
    for(int k = 0; k < NB_SPOTS; k++){
        if((spots[k].getGroup() == gpe) || (gpe == 0)){
            spots[k].setModeNoFunc();
        }
    }  
    */   
}

void    setAllSoundMode(uint8_t gpe, uint8_t val){
    ANNIV_mode_sound(gpe);
    /*
    for(int k = 0; k < NB_SPOTS; k++){
        if((spots[k].getGroup() == gpe) || (gpe == 0)){
            spots[k].setModeSound(val);
        }
    }  
    */   
}

void    setAllStrobeMode(uint8_t gpe, uint8_t val){
    ANNIV_mode_strobe(gpe);
    /*
    for(int k = 0; k < NB_SPOTS; k++){
        if((spots[k].getGroup() == gpe) || (gpe == 0)){
            spots[k].setModeSound(val);
        }
    }  
    */   
}

void    setAllSpeedStrobeSpots(uint8_t gpe, uint8_t speed){
    ANNIV_mode_strobe(gpe);
    /*
    for(int k = 0; k < NB_SPOTS; k++){
        if((spots[k].getGroup() == gpe) || (gpe == 0)){
            if(spots[k].getChanStrobeSpeed() != 0)     spots[k].setStrobeSpeed(speed);
        }
    }  
    */
}

void    setAllFadeSpots(uint8_t gpe){
    ANNIV_mode_fade(gpe);
    // TO DO
}