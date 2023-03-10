/*H**********************************************************************
* FILENAME :        M2D_DMX_SPOTS.cpp            
*
* DESCRIPTION :
*       DMX Spots Class.
*
* NOTES :
*       These functions are a part of the MIDI2DMX application
*       Developped by Villou / LEnsE
**
* AUTHOR :    Julien VILLEMEJANE        START DATE :    22/sept/2022
*
*       LEnsE / Institut d'Optique Graduate School
*H***********************************************************************/

#include "M2D_DMX_SPOTS.h"


// standard constructor
M2D_DMX_SPOTS::M2D_DMX_SPOTS(void){
    this->address = 0;
    this->chan = 0;
    this->group = 0;
    this->ch_dimmer = 0;
    this->ch_r = 0;
    this->ch_g = 0;
    this->ch_b = 0;
    this->ch_a = 0;
    this->ch_uv = 0;
    this->ch_w = 0;
}

// values
M2D_DMX_SPOTS_VALUES* M2D_DMX_SPOTS::getValues(void){ return &(this->valeurs);   }
// address
int M2D_DMX_SPOTS::getAdd(){    return  this->address; }
void M2D_DMX_SPOTS::setAdd(int add){    this->address = add; }
// channel number
uint8_t M2D_DMX_SPOTS::getChan(){   return  this->chan; }
void M2D_DMX_SPOTS::setChan(uint8_t chan){ this->chan = chan;   }
// group
uint8_t M2D_DMX_SPOTS::getGroup(){   return  this->group; }
void M2D_DMX_SPOTS::setGroup(uint8_t group){ this->group = group;   }

// function mode
uint8_t M2D_DMX_SPOTS::getChanMode(){ return this->ch_mode_on; }
void M2D_DMX_SPOTS::setChanNoFuncMode(uint8_t ch, uint8_t val){  this->ch_mode_on = ch;   this->mode_no_func = val;  } 
void M2D_DMX_SPOTS::setChanSoundMode(uint8_t ch, uint8_t inde, uint8_t val_min, uint8_t val_max){  
    this->ch_mode_sound = ch;  
    this->sound_inde = inde;
    this->mode_sound_min = val_min;
    this->mode_sound_max = val_max;
}  
uint8_t M2D_DMX_SPOTS::getMode(){ return this->valeurs.getMode(); } 
void M2D_DMX_SPOTS::setMode(uint8_t val){  this->valeurs.setMode(val);  }
void M2D_DMX_SPOTS::setModeNoFunc(){ 
    this->valeurs.setMode(this->mode_no_func);
    if(this->sound_inde == 0){  this->valeurs.setModeSound(0);  }
    if(this->strobe_inde == 0){  this->valeurs.setModeStrobe(0); this->valeurs.setSTSpeed(0);  }
}
void M2D_DMX_SPOTS::setModeSound(uint8_t val){ 
    if((val >= this->mode_sound_min) && (val <= this->mode_sound_max))
        this->valeurs.setModeSound(val); 
}
uint8_t M2D_DMX_SPOTS::getModeSoundValue(void){     return this->valeurs.getSoundValue();   }
bool M2D_DMX_SPOTS::isSoundInde(void){  if(this->sound_inde == 1) return true; else return false; }

// dimmer
uint8_t M2D_DMX_SPOTS::getChanDimmer(){ return this->ch_dimmer; }
void M2D_DMX_SPOTS::setChanDimmer(uint8_t ch){  this->ch_dimmer = ch;   }    
uint8_t  M2D_DMX_SPOTS::getDimmer(){    return this->valeurs.getDimmer();    }
void M2D_DMX_SPOTS::setDimmer(uint8_t val){ this->valeurs.setDimmer(val); }    
uint8_t M2D_DMX_SPOTS::getDimmerMin(){ return this->dim_min; }
void M2D_DMX_SPOTS::setDimmerMin(uint8_t val){ this->dim_min = val; }
uint8_t M2D_DMX_SPOTS::getDimmerMax(){ return this->dim_max; }
void M2D_DMX_SPOTS::setDimmerMax(uint8_t val){ this->dim_max = val; }

// get/set RGB channels
uint8_t M2D_DMX_SPOTS::getChanR(){  return this->ch_r;  }
uint8_t M2D_DMX_SPOTS::getChanG(){  return this->ch_g;  }
uint8_t M2D_DMX_SPOTS::getChanB(){  return this->ch_b;  }
void M2D_DMX_SPOTS::setChanRGB(uint8_t chanR, uint8_t chanG, uint8_t chanB){
    this->ch_r = chanR;
    this->ch_g = chanG;
    this->ch_b = chanB;
}
// get/set W-A-UV channels
uint8_t M2D_DMX_SPOTS::getChanW(){  return this->ch_w;  }
uint8_t M2D_DMX_SPOTS::getChanA(){  return this->ch_a;  }
uint8_t M2D_DMX_SPOTS::getChanUV(){  return this->ch_uv;  }
void M2D_DMX_SPOTS::setChanW(uint8_t w){   this->ch_w = w; }
void M2D_DMX_SPOTS::setChanA(uint8_t a){   this->ch_a = a; }
void M2D_DMX_SPOTS::setChanUV(uint8_t uv){   this->ch_uv = uv; }
// get/set RGB values
uint8_t M2D_DMX_SPOTS::getR(){ return this->valeurs.getR(); }
uint8_t M2D_DMX_SPOTS::getG(){ return this->valeurs.getG(); }
uint8_t M2D_DMX_SPOTS::getB(){ return this->valeurs.getB(); }
void M2D_DMX_SPOTS::setR(uint8_t R){    this->valeurs.setR(R);  }
void M2D_DMX_SPOTS::setG(uint8_t G){    this->valeurs.setG(G);  }
void M2D_DMX_SPOTS::setB(uint8_t B){    this->valeurs.setB(B);  }
void M2D_DMX_SPOTS::setRGB(uint8_t R, uint8_t G, uint8_t B){
    this->valeurs.setR(R);
    this->valeurs.setG(G);
    this->valeurs.setB(B);
}   
// get/set W-A-UV values
uint8_t M2D_DMX_SPOTS::getW(){ return this->valeurs.getW(); }
uint8_t M2D_DMX_SPOTS::getA(){ return this->valeurs.getA(); }
uint8_t M2D_DMX_SPOTS::getUV(){ return this->valeurs.getUV(); }
void M2D_DMX_SPOTS::setW(uint8_t W){    this->valeurs.setW(W);  }
void M2D_DMX_SPOTS::setA(uint8_t A){    this->valeurs.setA(A);  }
void M2D_DMX_SPOTS::setUV(uint8_t UV){    this->valeurs.setUV(UV);  }
// get/set pan/tilt channels
uint8_t M2D_DMX_SPOTS::getChanPan(){  return this->ch_pan;  }
uint8_t M2D_DMX_SPOTS::getChanPanF(){  return this->ch_panf;  }
uint8_t M2D_DMX_SPOTS::getChanTilt(){  return this->ch_tilt;  }
uint8_t M2D_DMX_SPOTS::getChanTiltF(){  return this->ch_tiltf;  }
uint8_t M2D_DMX_SPOTS::getChanPTSpeed(){  return this->ch_speed;  }
void M2D_DMX_SPOTS::setChanPan(uint8_t ch_pan){   this->ch_pan = ch_pan; }
void M2D_DMX_SPOTS::setChanPanF(uint8_t ch_panf){   this->ch_panf = ch_panf; }
void M2D_DMX_SPOTS::setChanTilt(uint8_t ch_tilt){   this->ch_tilt = ch_tilt; }
void M2D_DMX_SPOTS::setChanTiltF(uint8_t ch_tiltf){   this->ch_tiltf = ch_tiltf; }
void M2D_DMX_SPOTS::setChanPTSpeed(uint8_t ch_speed){   this->ch_speed = ch_speed; }

// get/set pan/tilt values
uint8_t M2D_DMX_SPOTS::getPan(){  return this->valeurs.getPan();  }
uint8_t M2D_DMX_SPOTS::getPanF(){  return this->valeurs.getPanF();  }
uint8_t M2D_DMX_SPOTS::getTilt(){  return this->valeurs.getTilt();  }
uint8_t M2D_DMX_SPOTS::getTiltF(){  return this->valeurs.getTiltF();  }
uint8_t M2D_DMX_SPOTS::getPTSpeed(){  return this->valeurs.getPTSpeed();  }
void M2D_DMX_SPOTS::setPan(uint8_t pan){    this->valeurs.setPan(pan);  }
void M2D_DMX_SPOTS::setPanF(uint8_t panf){    this->valeurs.setPanF(panf);  }
void M2D_DMX_SPOTS::setTilt(uint8_t tilt){    this->valeurs.setTilt(tilt);  }
void M2D_DMX_SPOTS::setTiltF(uint8_t tiltf){    this->valeurs.setTiltF(tiltf);  }
void M2D_DMX_SPOTS::setPTSpeed(uint8_t speed){    this->valeurs.setPTSpeed(speed);  }

// get/set strobe channels
uint8_t M2D_DMX_SPOTS::getChanStrobe(){  return this->ch_strobe;  }
uint8_t M2D_DMX_SPOTS::getChanStrobeSpeed(){  return this->ch_st_speed;  }
void M2D_DMX_SPOTS::setChanStrobe(uint8_t ch_strobe, uint8_t inde, uint8_t val){ 
    this->ch_strobe = ch_strobe;
    this->strobe_inde = inde;
    this->mode_strobe = val;
}
void M2D_DMX_SPOTS::setChanStrobeSpeed(uint8_t ch_speed){  this->ch_st_speed = ch_speed;   }
void M2D_DMX_SPOTS::setStrobeSpeedMin(uint8_t speed_min){  this->st_min = speed_min;   }
void M2D_DMX_SPOTS::setStrobeSpeedMax(uint8_t speed_max){  this->st_max = speed_max;   }
// get/set strobe channels
uint8_t M2D_DMX_SPOTS::getStrobeSpeed(){    return this->valeurs.getSTSpeed();  }
uint8_t M2D_DMX_SPOTS::getStrobeSpeedMin(){    return this->st_min;  }
uint8_t M2D_DMX_SPOTS::getStrobeSpeedMax(){    return this->st_max;  }
void M2D_DMX_SPOTS::setStrobeMode(void){
    if(this->ch_strobe != 0)
        this->valeurs.setModeStrobe(this->mode_strobe);
}
void M2D_DMX_SPOTS::setStrobeSpeed(uint8_t speed){
    if(this->ch_st_speed != 0)
        if((speed >= this->st_min) && (speed <= this->st_max))
            this->valeurs.setSTSpeed(speed);
}
bool M2D_DMX_SPOTS::isStrobeInde(void){  if(this->strobe_inde == 1) return true; else return false; }