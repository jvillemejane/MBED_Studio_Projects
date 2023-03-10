/*H**********************************************************************
* FILENAME :        M2D_DMX_SPOTS.h            
*
* DESCRIPTION :
*       DMX Spots Class.
*
* PUBLIC FUNCTIONS :
*       int     FM_CompressFile( FileHandle )
*
* NOTES :
*       These functions are a part of the MIDI2DMX application
*       Developped by Villou / LEnsE
**
* AUTHOR :    Julien VILLEMEJANE        START DATE :    22/sept/2022
*
*       LEnsE / Institut d'Optique Graduate School
*H***********************************************************************/

#ifndef     __M2D_DMX_SPOTS_H_INCLUDED
#define     __M2D_DMX_SPOTS_H_INCLUDED

#include    "mbed.h"
#include    "M2D_DMX_SPOTS_VALUES.h"

#define     MODE_PAN        'P'
#define     MODE_PAN_F      'Q'
#define     MODE_TILT       'T'
#define     MODE_TILT_F     'U'


// class definition for M2D_DMX_SPOTS
class M2D_DMX_SPOTS
{
public:
    // standard constructor
    M2D_DMX_SPOTS(void);
    // values
    M2D_DMX_SPOTS_VALUES* getValues(void);
    // address
    int getAdd();
    void setAdd(int add);
    // channel number
    uint8_t getChan();
    void setChan(uint8_t chan);
    // group
    uint8_t getGroup();
    void setGroup(uint8_t group);
    // no function mode
    uint8_t getChanMode();
    void setChanNoFuncMode(uint8_t ch, uint8_t val);
    void setChanSoundMode(uint8_t ch, uint8_t inde, uint8_t val_min, uint8_t val_max);
    uint8_t getMode();
    void setMode(uint8_t val);
    void setModeNoFunc();
    void setModeSound(uint8_t val);
    uint8_t getModeSoundValue(void);
    bool isSoundInde(void);
    // dimmer
    uint8_t getChanDimmer();
    void setChanDimmer(uint8_t  ch);
    uint8_t getDimmer();
    void setDimmer(uint8_t val);
    uint8_t getDimmerMin();
    void setDimmerMin(uint8_t val);
    uint8_t getDimmerMax();
    void setDimmerMax(uint8_t val);
    // get/set RGB channels
    uint8_t getChanR();
    uint8_t getChanG();
    uint8_t getChanB();
    void setChanRGB(uint8_t chanR, uint8_t chanG, uint8_t chanB);
    // get/set W-A-UV channels
    uint8_t getChanW();
    uint8_t getChanA();
    uint8_t getChanUV();
    void setChanW(uint8_t w);
    void setChanA(uint8_t a);
    void setChanUV(uint8_t uv);
    // get/set RGB values
    uint8_t getR();
    uint8_t getG();
    uint8_t getB();
    void setR(uint8_t R);
    void setG(uint8_t G);
    void setB(uint8_t B);
    void setRGB(uint8_t R, uint8_t G, uint8_t B);
    // get/set W-A-UV values
    uint8_t getW();
    uint8_t getA();
    uint8_t getUV();
    void setW(uint8_t W);
    void setA(uint8_t A);
    void setUV(uint8_t UV);
    // get/set pan/tilt channels
    uint8_t getChanPan();
    uint8_t getChanPanF();
    uint8_t getChanTilt();
    uint8_t getChanTiltF();
    uint8_t getChanPTSpeed();
    void setChanPan(uint8_t ch_pan);
    void setChanPanF(uint8_t ch_panf);
    void setChanTilt(uint8_t ch_tilt);
    void setChanTiltF(uint8_t ch_tiltf);
    void setChanPTSpeed(uint8_t ch_speed);
    // get/set pan/tilt values
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
    // get/set strobe channels
    uint8_t getChanStrobe();
    uint8_t getChanStrobeSpeed();
    void setChanStrobe(uint8_t ch_pan, uint8_t inde, uint8_t val);
    void setChanStrobeSpeed(uint8_t ch_speed);
    void setStrobeSpeedMin(uint8_t speed_min);
    void setStrobeSpeedMax(uint8_t speed_max);
    bool isStrobeInde(void);
    // get/set strobe channels
    uint8_t getStrobeSpeed();
    uint8_t getStrobeSpeedMin();
    uint8_t getStrobeSpeedMax();
    void setStrobeMode(void);
    void setStrobeSpeed(uint8_t speed);
    
private:
    int     address;
    uint8_t chan;
    uint8_t group;
    // MODE - NO FUNC - SOUND
    uint8_t ch_mode_on;
    uint8_t ch_mode_sound;
    uint8_t sound_inde;
    uint8_t mode_no_func;
    uint8_t mode_sound_min, mode_sound_max;
    // DIM - D_MIN - D_MAX
    uint8_t ch_dimmer, dim_min, dim_max;
    // R - G - B - W - A - UV
    uint8_t ch_r, ch_g, ch_b, ch_a, ch_w, ch_uv;  // colors channels
    // PAN - PANF - TILT - TILTF - SPEED
    uint8_t ch_pan, ch_panf, ch_tilt, ch_tiltf, ch_speed;
    // GOBOS1 - G1NB - GOBOS2 - G2NB - COULEURS - CONB
    // STROBE - ST_MIN - ST_MAX - ST_SPEED
    uint8_t mode_strobe, strobe_inde, ch_strobe, ch_st_speed, st_min, st_max;
    M2D_DMX_SPOTS_VALUES      valeurs;
};


#endif