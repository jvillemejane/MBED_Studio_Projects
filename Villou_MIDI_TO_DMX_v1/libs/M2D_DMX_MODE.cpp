/*H**********************************************************************
* FILENAME :        M2D_DMX_MODE.cpp           
*
* DESCRIPTION :
*       DMX Mode processing routines.
*
* NOTES :
*       These functions are a part of the MIDI2DMX application
*       Developped by Villou / LEnsE
**
* AUTHOR :    Julien VILLEMEJANE        START DATE :    22/sept/2022
*
*       LEnsE / Institut d'Optique Graduate School
*H***********************************************************************/

#include    "M2D_DMX_MODE.h"

/************************************/
/* Global Parameters                */
/************************************/
uint8_t         dmx_data[SAMPLES] = {0};

/****************************************************/
/* Functions                                        */  
/****************************************************/
/* DMX output initialization */
void initDMX(void){
    dmx.set_baud(250000);
    dmx.set_format (8, SerialBase::None, 2);
    enableDMX = 0;
    // Initialisation canaux DMX
    clearDMX();
    updateDMX();
} 

/* Clear internal values for DMX output */
void clearDMX(){
    for(int k = 0; k < SAMPLES; k++){
        dmx_data[k] = 0;
    }
}

/* Updating DMX output with internal values */
void updateDMX(){
    enableDMX = 1;
    start = 1;      // /start
    out_tx = 0;     // break
    wait_us(88);    
    out_tx = 1;     // mb
    wait_us(8);     
    out_tx = 0;     // break
    start = 0;
    uint8_t     temp_data = 0;
    dmx.write(&temp_data, 1);     // Start
    for(int i = 0; i < SAMPLES; i++){
        dmx.write(&dmx_data[i], 1); ;     // data
    }
    enableDMX = 0;
    wait_us(2000); // time between frame  
}

/* update internal DMX data */
void    updateDMXdata(void){
    for(int k = 0; k < global_spots_number; k++){        
        int add = spots_list[k].getAdd();
        // Mode
        uint8_t mode = spots_list[k].getChanMode();
        if(mode != 0)  dmx_data[add+mode-2] = spots_list[k].getMode();
        // GESTION DES MODES SOUND ET STROBE A REVOIR !!
        /*
        uint8_t mode_sound = this->spots[k].getModeSoundValue();
        if((!this->spots[k].isSoundInde()) && (mode_sound != 0)){
            this->dmx_data[add+mode-2] = this->spots[k].getModeSoundValue();
        }
        else{
            uint8_t mode_strobe = this->spots[k].getStrobeSpeed();
            if((!this->spots[k].isStrobeInde()) && (mode_strobe != 0)){
                this->dmx_data[add+mode-2] = this->spots[k].getStrobeSpeed();
            }
            else{
                if(mode != 0)  this->dmx_data[add+mode-2] = this->spots[k].getMode();
            }
        }
        */
        // Colors        
        uint8_t dim = spots_list[k].getChanDimmer();
        if(dim != 0)  dmx_data[add+dim-2] = spots_list[k].getDimmer();
        uint8_t r = spots_list[k].getChanR();
        if(r != 0)  dmx_data[add+r-2] = spots_list[k].getR();
        uint8_t g = spots_list[k].getChanG();
        if(g != 0)  dmx_data[add+g-2] = spots_list[k].getG();
        uint8_t b = spots_list[k].getChanB();
        if(b != 0)  dmx_data[add+b-2] = spots_list[k].getB();
        uint8_t w = spots_list[k].getChanW();
        if(w != 0)  dmx_data[add+w-2] = spots_list[k].getW();
        uint8_t a = spots_list[k].getChanA();
        if(a != 0)  dmx_data[add+a-2] = spots_list[k].getA();
        uint8_t uv = spots_list[k].getChanUV();
        if(uv != 0)  dmx_data[add+uv-2] = spots_list[k].getUV();
    }
}



