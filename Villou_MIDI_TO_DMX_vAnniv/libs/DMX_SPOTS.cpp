/****************************************************************************/
/*  DMX_SPOTS module library                                                */
/****************************************************************************/
/*  LEnsE / Julien VILLEMEJANE       /   Institut d'Optique Graduate School */
/****************************************************************************/
/*  Library - DMX_SPOTS.cpp file                                            */
/****************************************************************************/
/****************************************************************************/
/*  Debugging on USB @ 115200 bauds                                         */
/****************************************************************************/

#include "DMX_SPOTS.h"
#include <cstdint>

// standard constructor
DMX_spots::DMX_spots(void){
    this->address = 0;
}
// print spot info
void DMX_spots::print(BufferedSerial *s){
    // TO DO
}
// values
DMX_values DMX_spots::getValues(void){  return this->valeurs; }
// address
int DMX_spots::getAdd(){    return this->address; }
void DMX_spots::setAdd(int add){    this->address = add; }

// channel number
uint8_t DMX_spots::getChan(){   return this->chan; }
void DMX_spots::setChan(uint8_t chan){    this->chan = chan; }
// group
uint8_t DMX_spots::getGroup(){    return this->group; }
void DMX_spots::setGroup(uint8_t group){    this->group = group; }
// no function mode
uint8_t DMX_spots::getChanMode(){    return this->ch_mode_on; }
void DMX_spots::setChanNoFuncMode(uint8_t ch, uint8_t val){
    this->ch_mode_on = ch;
    this->mode_no_func = val;
}
void DMX_spots::setChanSoundMode(uint8_t ch, uint8_t inde, uint8_t val_min, uint8_t val_max){
    this->ch_mode_sound = ch;
    this->sound_inde = inde;
    this->mode_sound_min = val_min;
    this->mode_sound_max = val_max;
}
uint8_t DMX_spots::getMode(){    return this->valeurs.getMode(); }
void DMX_spots::setMode(uint8_t val){    this->valeurs.setMode(val); }
void DMX_spots::setModeNoFunc(){
    this->valeurs.setMode(this->mode_no_func); 
    if(this->sound_inde){
        this->valeurs.setModeSound(0);
    }
    if(this->strobe_inde){
        this->valeurs.setModeStrobe(0);
    }
}
void DMX_spots::setModeSound(uint8_t val){
    if(this->sound_inde){
        if(val+mode_sound_min < mode_sound_max){
            this->valeurs.setModeSound(this->mode_sound_min + val);
        }
        else{
            this->valeurs.setModeSound(this->mode_sound_min);
        }
        this->valeurs.setMode(0);
    }
    else{
        this->valeurs.setMode(this->mode_sound_min);
    }  
    if(this->strobe_inde){
        this->valeurs.setModeStrobe(0);
    }
}
uint8_t DMX_spots::getModeSoundValue(void){
    return this->mode_sound_min;
}
bool DMX_spots::isSoundInde(void){  return this->sound_inde; }
// dimmer
uint8_t DMX_spots::getChanDimmer(){    return this->ch_dimmer; }
void DMX_spots::setChanDimmer(uint8_t  ch){    this->ch_dimmer = ch; }
uint8_t DMX_spots::getDimmer(){    return this->valeurs.getDimmer(); }
void DMX_spots::setDimmer(uint8_t val){    this->valeurs.setDimmer(val); }
uint8_t DMX_spots::getDimmerMin(){  return this->dim_min; }
void DMX_spots::setDimmerMin(uint8_t val){  this->dim_min = val; }
uint8_t DMX_spots::getDimmerMax(){  return this->dim_max; }
void DMX_spots::setDimmerMax(uint8_t val){  this->dim_max = val; }
// get/set RGB channels
uint8_t DMX_spots::getChanR(){  return this->ch_r; }
uint8_t DMX_spots::getChanG(){  return this->ch_g; }
uint8_t DMX_spots::getChanB(){  return this->ch_b; }
void DMX_spots::setChanRGB(uint8_t chanR, uint8_t chanG, uint8_t chanB){
    this->ch_r = chanR;
    this->ch_g = chanG;
    this->ch_b = chanB;
}
// get/set W-A-UV channels
uint8_t DMX_spots::getChanW(){  return this->ch_w; }
uint8_t DMX_spots::getChanA(){  return this->ch_a; }
uint8_t DMX_spots::getChanUV(){ return this->ch_uv; }
void DMX_spots::setChanW(uint8_t w){    this->ch_w = w; }
void DMX_spots::setChanA(uint8_t a){    this->ch_a = a; }
void DMX_spots::setChanUV(uint8_t uv){  this->ch_uv = uv; }
// get/set RGB values
uint8_t DMX_spots::getR(){  return this->valeurs.getR(); }
uint8_t DMX_spots::getG(){  return this->valeurs.getG(); }
uint8_t DMX_spots::getB(){  return this->valeurs.getB(); }
void DMX_spots::setR(uint8_t R){    this->valeurs.setR(R); }
void DMX_spots::setG(uint8_t G){    this->valeurs.setG(G); }
void DMX_spots::setB(uint8_t B){    this->valeurs.setB(B); }
void DMX_spots::setRGB(uint8_t R, uint8_t G, uint8_t B){
    this->valeurs.setR(R);
    this->valeurs.setG(G);
    this->valeurs.setB(B);
}
// get/set W-A-UV values
uint8_t DMX_spots::getW(){  return this->valeurs.getW(); }
uint8_t DMX_spots::getA(){  return this->valeurs.getA(); }
uint8_t DMX_spots::getUV(){ return this->valeurs.getUV(); }
void DMX_spots::setW(uint8_t W){    this->valeurs.setW(W); }
void DMX_spots::setA(uint8_t A){    this->valeurs.setA(A); }
void DMX_spots::setUV(uint8_t UV){  this->valeurs.setUV(UV); }
// get/set pan/tilt channels
uint8_t DMX_spots::getChanPan(){    return this->ch_pan; }
uint8_t DMX_spots::getChanPanF(){   return this->ch_panf; }
uint8_t DMX_spots::getChanTilt(){   return this->ch_tilt; }
uint8_t DMX_spots::getChanTiltF(){  return this->ch_tiltf; }
uint8_t DMX_spots::getChanPTSpeed(){    return this->ch_speed; }
void DMX_spots::setChanPan(uint8_t ch_pan){ this->ch_pan = ch_pan; }
void DMX_spots::setChanPanF(uint8_t ch_panf){   this->ch_panf = ch_panf; }
void DMX_spots::setChanTilt(uint8_t ch_tilt){   this->ch_tilt = ch_tilt; }
void DMX_spots::setChanTiltF(uint8_t ch_tiltf){ this->ch_tiltf = ch_tiltf; }
void DMX_spots::setChanPTSpeed(uint8_t ch_speed){   this->ch_speed = ch_speed; }
// get/set pan/tilt values
uint8_t DMX_spots::getPan(){    return this->valeurs.getPan(); }
uint8_t DMX_spots::getPanF(){   return this->valeurs.getPanF(); }
uint8_t DMX_spots::getTilt(){   return this->valeurs.getTilt(); }
uint8_t DMX_spots::getTiltF(){  return this->valeurs.getTiltF(); }
uint8_t DMX_spots::getPTSpeed(){    return this->valeurs.getPTSpeed(); }
void DMX_spots::setPan(uint8_t pan){    this->valeurs.setPan(pan); }
void DMX_spots::setPanF(uint8_t panf){  this->valeurs.setPanF(panf); }
void DMX_spots::setTilt(uint8_t tilt){  this->valeurs.setTilt(tilt); }
void DMX_spots::setTiltF(uint8_t tiltf){    this->valeurs.setTiltF(tiltf); }
void DMX_spots::setPTSpeed(uint8_t speed){  this->valeurs.setPTSpeed(speed); }    
// get/set strobe channels
uint8_t DMX_spots::getChanStrobe(){ return this->ch_strobe; }
uint8_t DMX_spots::getChanStrobeSpeed(){    return this->ch_st_speed; }
void DMX_spots::setChanStrobe(uint8_t ch_str, uint8_t inde, uint8_t val){
    this->ch_strobe = ch_str;
    this->strobe_inde = inde;
    this->mode_strobe = val;
}
void DMX_spots::setChanStrobeSpeed(uint8_t speed){   this->valeurs.setSTSpeed(speed); }
void DMX_spots::setStrobeSpeedMin(uint8_t speed_min){   this->st_min = speed_min; }
void DMX_spots::setStrobeSpeedMax(uint8_t speed_max){   this->st_max = speed_max; }
bool DMX_spots::isStrobeInde(void){ return this->strobe_inde; }
// get/set strobe channels
uint8_t DMX_spots::getStrobeSpeed(){    return this->valeurs.getSTSpeed(); }
uint8_t DMX_spots::getStrobeSpeedMin(){ return this->st_min; }
uint8_t DMX_spots::getStrobeSpeedMax(){ return this->st_max; }
void DMX_spots::setModeStrobe(void){
    if(this->strobe_inde){
        this->valeurs.setModeStrobe(this->mode_strobe);
        this->valeurs.setMode(0);
    }
    else{
        this->valeurs.setMode(this->mode_sound_min);
    }  
    if(this->sound_inde){
        this->valeurs.setModeSound(0);
    }
    
        this->valeurs.setModeStrobe(this->mode_strobe); }
void DMX_spots::setStrobeSpeed(uint8_t speed){  return this->valeurs.setSTSpeed(speed); }

// get/set fade mode
void DMX_spots::setFadeMode(uint8_t val){
    this->mode_fade = val;
}
void    DMX_spots::setModeFade(void){
    this->valeurs.setMode(this->mode_fade);
    if(this->sound_inde){
        this->valeurs.setModeSound(0);
    }
    if(this->strobe_inde){
        this->valeurs.setModeStrobe(0);
    }
}

void DMX_spots::updateData(uint8_t data[]){
    int16_t addDMX = this->getAdd();
    // TO FINISH
    // Mode
    int16_t ch = this->getChanMode();
    int8_t val = this->getMode();
    data[addDMX-1+ch-1] = val;
    // Dimmer
    ch = this->getChanDimmer();
    val = this->getDimmer();
    data[addDMX-1+ch-1] = val;
    // RGBWAUV
    ch = this->getChanR();
    val = this->getR();
    data[addDMX-1+ch-1] = val;
    ch = this->getChanG();
    val = this->getG();
    data[addDMX-1+ch-1] = val;
    ch = this->getChanB();
    val = this->getB();
    data[addDMX-1+ch-1] = val;

    ch = this->getChanA();
    val = this->getA();
    if(ch != 0) data[addDMX-1+ch-1] = val;
    ch = this->getChanW();
    val = this->getW();
    if(ch != 0) data[addDMX-1+ch-1] = val;
    ch = this->getChanUV();
    val = this->getUV();
    if(ch != 0) data[addDMX-1+ch-1] = val;
    // Tilt / Pan
    ch = this->getChanPTSpeed();
    val = this->getPTSpeed();
    if(ch != 0) data[addDMX-1+ch-1] = val;
    ch = this->getChanPan();
    val = this->getPan();
    if(ch != 0) data[addDMX-1+ch-1] = val;
    ch = this->getChanPanF();
    val = this->getPanF();
    if(ch != 0) data[addDMX-1+ch-1] = val;
    ch = this->getChanTilt();
    val = this->getTilt();
    if(ch != 0) data[addDMX-1+ch-1] = val;
    ch = this->getChanTiltF();
    val = this->getTiltF();
    if(ch != 0) data[addDMX-1+ch-1] = val;
}
