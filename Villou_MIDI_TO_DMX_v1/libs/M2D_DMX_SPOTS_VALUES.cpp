/*H**********************************************************************
* FILENAME :        M2D_DMX_SPOTS_VALUES.cpp           
*
* DESCRIPTION :
*       DMX Spots Values Class.
*
* NOTES :
*       These functions are a part of the MIDI2DMX application
*       Developped by Villou / LEnsE
**
* AUTHOR :    Julien VILLEMEJANE        START DATE :    22/sept/2022
*
*       LEnsE / Institut d'Optique Graduate School
*H***********************************************************************/

#include    "M2D_DMX_SPOTS_VALUES.h"

// standard constructor
M2D_DMX_SPOTS_VALUES::M2D_DMX_SPOTS_VALUES(void){    
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
void M2D_DMX_SPOTS_VALUES::resetValues(void){
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
uint8_t M2D_DMX_SPOTS_VALUES::getMode(){ return this->val_mode; }
void M2D_DMX_SPOTS_VALUES::setMode(uint8_t val){
    this->val_mode = val;
}
void M2D_DMX_SPOTS_VALUES::setModeSound(uint8_t val){
    this->val_mode_sound = val;
}
void M2D_DMX_SPOTS_VALUES::setModeStrobe(uint8_t val){
    this->val_mode_strobe = val;
}
// get/set dimmer
uint8_t M2D_DMX_SPOTS_VALUES::getDimmer(){ return this->val_dimmer; }
void M2D_DMX_SPOTS_VALUES::setDimmer(uint8_t val){
    this->val_dimmer = val;
}

// get/set RGB values
uint8_t M2D_DMX_SPOTS_VALUES::getR(){ return this->val_r; }
uint8_t M2D_DMX_SPOTS_VALUES::getG(){ return this->val_g; }
uint8_t M2D_DMX_SPOTS_VALUES::getB(){ return this->val_b; }
void M2D_DMX_SPOTS_VALUES::setR(uint8_t R){   this->val_r = R;    }
void M2D_DMX_SPOTS_VALUES::setG(uint8_t G){   this->val_g = G;    }
void M2D_DMX_SPOTS_VALUES::setB(uint8_t B){   this->val_b = B;    }
void M2D_DMX_SPOTS_VALUES::setRGB(uint8_t R, uint8_t G, uint8_t B){
    this->val_r = R;
    this->val_g = G;
    this->val_b = B;
}   

// get/set A-UV-W values
uint8_t M2D_DMX_SPOTS_VALUES::getW(){ return this->val_w; }
uint8_t M2D_DMX_SPOTS_VALUES::getA(){ return this->val_a; }
uint8_t M2D_DMX_SPOTS_VALUES::getUV(){ return this->val_uv; }
void M2D_DMX_SPOTS_VALUES::setW(uint8_t W){   this->val_w = W;    }
void M2D_DMX_SPOTS_VALUES::setA(uint8_t A){   this->val_a = A;    }
void M2D_DMX_SPOTS_VALUES::setUV(uint8_t UV){   this->val_uv = UV;    }

// get/set pan-tilt values
uint8_t M2D_DMX_SPOTS_VALUES::getPan(){ return this->val_pan; }
uint8_t M2D_DMX_SPOTS_VALUES::getPanF(){ return this->val_panf; }
uint8_t M2D_DMX_SPOTS_VALUES::getTilt(){ return this->val_tilt; }
uint8_t M2D_DMX_SPOTS_VALUES::getTiltF(){ return this->val_tiltf; }
uint8_t M2D_DMX_SPOTS_VALUES::getPTSpeed(){ return this->val_speed; }
void M2D_DMX_SPOTS_VALUES::setPan(uint8_t pan){   this->val_pan = pan;    }
void M2D_DMX_SPOTS_VALUES::setPanF(uint8_t panf){   this->val_panf = panf;    }
void M2D_DMX_SPOTS_VALUES::setTilt(uint8_t tilt){   this->val_tilt = tilt;    }
void M2D_DMX_SPOTS_VALUES::setTiltF(uint8_t tiltf){   this->val_tiltf = tiltf;    }
void M2D_DMX_SPOTS_VALUES::setPTSpeed(uint8_t speed){   this->val_speed = speed;    }
// get/set strobe speed
uint8_t M2D_DMX_SPOTS_VALUES::getSTSpeed(){ return this->val_st_speed; }
void M2D_DMX_SPOTS_VALUES::setSTSpeed(uint8_t speed){ this->val_st_speed = speed; }
// get sound value
uint8_t M2D_DMX_SPOTS_VALUES::getSoundValue(void){ return this->val_mode_sound; }
