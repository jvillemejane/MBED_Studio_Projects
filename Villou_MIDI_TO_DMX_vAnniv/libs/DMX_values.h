/****************************************************************************/
/*  Test DMX512             + MIDI extension                       */
/****************************************************************************/
/*  LEnsE / Julien VILLEMEJANE       /   Institut d'Optique Graduate School */
/****************************************************************************/
/*  DMX_values / Library                                                    */
/****************************************************************************/
/*  Tested on Nucleo-L476RG                                                 */
/****************************************************************************/

#ifndef     __DMX_VALUES_H_INCLUDED__
#define     __DMX_VALUES_H_INCLUDED__

#include "mbed.h"

class DMX_values{
public :
    // standard constructor
    DMX_values(void);
    // reset values
    void resetValues(void);
    // function mode
    uint8_t getMode();
    void setMode(uint8_t val);
    void setModeSound(uint8_t val);
    void setModeStrobe(uint8_t val);
    // get/set dimmer
    uint8_t getDimmer();
    void setDimmer(uint8_t val);
    // get/set RGB values
    uint8_t getR();
    uint8_t getG();
    uint8_t getB();
    void setR(uint8_t R);
    void setG(uint8_t G);
    void setB(uint8_t B);
    void setRGB(uint8_t R, uint8_t G, uint8_t B);
    // get/set A-UV-W values
    uint8_t getW();
    uint8_t getA();
    uint8_t getUV();
    void setW(uint8_t W);
    void setA(uint8_t A);
    void setUV(uint8_t UV);
    // get/set pan-tilt values
    uint8_t getPan();
    uint8_t getPanF();
    uint8_t getTilt();
    uint8_t getTiltF();
    uint8_t getPTSpeed();
    void setPan(uint8_t pan);
    void setPanF(uint8_t panf);
    void setTilt(uint8_t tilt);
    void setTiltF(uint8_t tiltf);
    void setPTSpeed(uint8_t speed);
    // get/set strobe speed
    uint8_t getSTSpeed();
    void setSTSpeed(uint8_t speed);
    // get sound value
    uint8_t getSoundValue(void);
private :
    // MODE
    uint8_t val_mode;
    uint8_t val_mode_sound;
    uint8_t val_mode_strobe;
    // DIMMER
    uint8_t val_dimmer;
    // R - G - B - W - A - UV
    uint8_t val_r, val_g, val_b, val_a, val_w, val_uv;  // colors channels
    // PAN - PANF - TILT - TILTF - SPEED
    uint8_t val_pan, val_panf, val_tilt, val_tiltf, val_speed;
    // GOBOS1 - G1NB - GOBOS2 - G2NB - COULEURS - CONB
    // STROBE
    uint8_t val_st_speed;
};

#endif