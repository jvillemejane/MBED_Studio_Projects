/****************************************************************************/
/*  Test DMX512             + MIDI extension                       */
/****************************************************************************/
/*  LEnsE / Julien VILLEMEJANE       /   Institut d'Optique Graduate School */
/****************************************************************************/
/*  DMX_values / Library                                                    */
/****************************************************************************/
/*  Tested on Nucleo-L476RG                                                 */
/****************************************************************************/

#include    "DMX_values.h"

// standard constructor
DMX_values::DMX_values(void){    
    this->val_mode = 0;  
    this->val_mode_sound = 0;  
    this->val_mode_strobe = 0;
    this->val_dimmer = 0;
    this->val_r = 0;
    this->val_g = 0;
    this->val_b = 0;
    this->val_a = 0;
    this->val_uv = 0;
    this->val_w = 0;
    this->val_pan = 0;
    this->val_panf = 0;
    this->val_tilt = 0;
    this->val_tiltf = 0;
    this->val_speed = 0;
    this->val_st_speed = 0;
}

// reset values
void DMX_values::resetValues(void){
    this->val_mode = 0;  
    this->val_mode_sound = 0;  
    this->val_mode_strobe = 0;
    this->val_dimmer = 0;
    this->val_r = 0;
    this->val_g = 0;
    this->val_b = 0;
    this->val_a = 0;
    this->val_uv = 0;
    this->val_w = 0;
    this->val_pan = 0;
    this->val_panf = 0;
    this->val_tilt = 0;
    this->val_tiltf = 0;
    this->val_speed = 0;
    this->val_st_speed = 0;
}

// no function mode
uint8_t DMX_values::getMode(){ return this->val_mode; }
void DMX_values::setMode(uint8_t val){
    this->val_mode = val;
}
void DMX_values::setModeSound(uint8_t val){
    this->val_mode_sound = val;
}
void DMX_values::setModeStrobe(uint8_t val){
    this->val_mode_strobe = val;
}
// get/set dimmer
uint8_t DMX_values::getDimmer(){ return this->val_dimmer; }
void DMX_values::setDimmer(uint8_t val){
    this->val_dimmer = val;
}

// get/set RGB values
uint8_t DMX_values::getR(){ return this->val_r; }
uint8_t DMX_values::getG(){ return this->val_g; }
uint8_t DMX_values::getB(){ return this->val_b; }
void DMX_values::setR(uint8_t R){   this->val_r = R;    }
void DMX_values::setG(uint8_t G){   this->val_g = G;    }
void DMX_values::setB(uint8_t B){   this->val_b = B;    }
void DMX_values::setRGB(uint8_t R, uint8_t G, uint8_t B){
    this->val_r = R;
    this->val_g = G;
    this->val_b = B;
}   

// get/set A-UV-W values
uint8_t DMX_values::getW(){ return this->val_w; }
uint8_t DMX_values::getA(){ return this->val_a; }
uint8_t DMX_values::getUV(){ return this->val_uv; }
void DMX_values::setW(uint8_t W){   this->val_w = W;    }
void DMX_values::setA(uint8_t A){   this->val_a = A;    }
void DMX_values::setUV(uint8_t UV){   this->val_uv = UV;    }

// get/set pan-tilt values
uint8_t DMX_values::getPan(){ return this->val_pan; }
uint8_t DMX_values::getPanF(){ return this->val_panf; }
uint8_t DMX_values::getTilt(){ return this->val_tilt; }
uint8_t DMX_values::getTiltF(){ return this->val_tiltf; }
uint8_t DMX_values::getPTSpeed(){ return this->val_speed; }
void DMX_values::setPan(uint8_t pan){   this->val_pan = pan;    }
void DMX_values::setPanF(uint8_t panf){   this->val_panf = panf;    }
void DMX_values::setTilt(uint8_t tilt){   this->val_tilt = tilt;    }
void DMX_values::setTiltF(uint8_t tiltf){   this->val_tiltf = tiltf;    }
void DMX_values::setPTSpeed(uint8_t speed){   this->val_speed = speed;    }
// get/set strobe speed
uint8_t DMX_values::getSTSpeed(){ return this->val_st_speed; }
void DMX_values::setSTSpeed(uint8_t speed){ this->val_st_speed = speed; }
// get sound value
uint8_t DMX_values::getSoundValue(void){ return this->val_mode_sound; }
