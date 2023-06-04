/****************************************************************************/
/*  SETUP_CONFIG module library                                             */
/****************************************************************************/
/*  LEnsE / Julien VILLEMEJANE       /   Institut d'Optique Graduate School */
/****************************************************************************/
/*  Library - SETUP_CONFIG.cpp file                                         */
/****************************************************************************/
/*  Tested on Nucleo-L476RG / 11th nov 2021                                 */
/****************************************************************************/
/*  SetUp for CeTI Introduction with KORG Electribe Sampler                 */
/*  Light Type                                                              */
/*      SLS-6 - 7 ch - DIM / STR / R / G / B / PRES / PROG                  */
/*      LVPT12 - 7 ch - MODE(0) / COLOR / SPEED / DIM / R / G / B           */
/*      TMH-46 - 16 ch - PAN / TILT / SPEED / DIM / STR / R / G / B /
                    W / A / UV / SND1 / SPD_M / SND2 / SPD_C / RES          */
/*      LEDPARTY - 7 ch - DIM / R / G / B / W / STR / MODE                  */

#include    "PROCESS_MIDI.h"
#include    "DMX_MIDI.h"
#include <cstdint>

/* Action à réaliser / Controleur / Note Midi */
void    processNoteMidiCtrl(uint8_t chan){
    switch(note_data[chan-1]){
        case 48 :   /* Global BLACKOUT */
            mode_global_midi = MODE_GLOB_BLACKOUT;
            if(DEBUG_MODE)  printf("BLACKOUT\r\n");
            break;
        case 49 :   /* Global RGBWAUV-P-T */
            mode_global_midi = MODE_GLOB_RGB;
            if(DEBUG_MODE)  printf("RGB MODE\r\n");
            /*            
            setAllDimmerSpots(0, global_dimmer);
            setAllGlobalSpots(0);
            */
            break;
        case 50 :   /* Global WHITE */
            mode_global_midi = MODE_GLOB_WHITE;
            if(DEBUG_MODE)  printf("WHITE MODE\r\n");   
            break;
        case 51 :   /* Global UV */
            mode_global_midi = MODE_GLOB_UV;
            if(DEBUG_MODE)  printf("UV MODE\r\n"); 
            break;
        case 52 :   /* Mode KEYB Alone - Channel MIDI 1 */
            mode_global_midi = MODE_GLOB_KEYB_A;
            break;
        case 53 :   /* Mode KEYB Multi */
            mode_global_midi = MODE_GLOB_KEYB_M;
            break;
        case 54 :   /* STROBE */
            mode_global_midi = MODE_GLOB_STROBE;
            setAllStrobeMode(0, 0);
            break;
        case 55 :   /* Sequenceur RGB - Chenillard */
            mode_global_midi = MODE_GLOB_SEQ_RGB;
            if(DEBUG_MODE)  printf("SEQ RGB MODE\r\n"); 
            seq_rgb_cpt = 0;            
            break;
            
        case 58 :   /* Fade MODE */
            ANNIV_mode_fade(0);
            mode_global_midi = MODE_GLOB_FADE;
            break;
        case 59 :   /* Sound MODE */
            ANNIV_mode_sound(0);
            mode_global_midi = MODE_GLOB_SOUND;
            break;
        case 84 :   /* PRINT VALUE RGBAWUV-P-T-S - CC 7 */
            printf("\tR=%d\tG=%d\tB=%d\r\n", spots[0].getR(), spots[0].getG(), spots[0].getB());
            printf("\tA=%d\tW=%d\tU=%d\r\n", spots[0].getA(), spots[0].getW(), spots[0].getUV());
            printf("\tP=%d\tT=%d\tS=%d\r\n\n", spots[0].getPan(), spots[0].getTilt(), spots[0].getPTSpeed());
            break;
        default:
            break;
    }
}
/* Action à réaliser / Clavier / Note Midi */
void    processNoteMidiKeyb(uint8_t chan){
    uint8_t note = note_data[chan-1] % KEY_NB;
    if(mode_global_midi == MODE_GLOB_KEYB_A){
        uint8_t color_nb = key_colors[note*MIDI_CH + 0];
        if(DEBUG_MODE)  printf("NoteMidiKEYB_A - N=%d - %d - %d\r\n", chan, note_data[chan-1], color_nb);
        uint8_t c[6];
        getColor(color_nb, c);
        setAllColorSpots(0, c);
    }
    if(mode_global_midi == MODE_GLOB_KEYB_M){
        // TODO : boucle sur groupe
        uint8_t color_nb = key_colors[note*MIDI_CH + 0];
        if(DEBUG_MODE)  printf("NoteMidiKEYB_M - N=%d - %d - %d\r\n", chan, note_data[chan-1], color_nb);
        uint8_t c[6];
        getColor(color_nb, c);
        setAllColorSpots(0, c);
    }
}
/* Action à réaliser / Séquenceur / Note Midi */
void    processNoteMidiSequ(uint8_t chan){

}
/* Action à réaliser / Controleur / CC Midi */
void    processCCMidiCtrl(uint8_t chan){
    double   bpm;
    if(DEBUG_MODE)  printf("CCMidiCTRL - C=%d - N=%d - V=%d\r\n", chan, CC_data[chan-1], CCvalue_data[chan-1]);
    switch(CC_data[chan-1]){
        case 1 :    /* DIMMER GLOBAL - CC 1 */
            global_dimmer = CCvalue_data[chan-1] << 1;
            break;
        case 2 :    /* R GLOBAL - CC 2 */
            global_r = CCvalue_data[chan-1] << 1;
            break;
        case 3 :    /* G GLOBAL - CC 3 */
            global_g = CCvalue_data[chan-1] << 1;
            break;
        case 4 :    /* B GLOBAL - CC 4 */
            global_b = CCvalue_data[chan-1] << 1;
            break;
        case 5 :    /* A GLOBAL - CC 5 */
            global_a = CCvalue_data[chan-1] << 1;
            break;
        case 6 :    /* W GLOBAL - CC 5 */
            global_w = CCvalue_data[chan-1] << 1;
            break;
        case 11 :    /* UV - CC 11 */
            global_uv = CCvalue_data[chan-1] << 1;
            break;
        case 12 :    /* STROBE SPEED - CC 12 */
            global_strobe_speed = CCvalue_data[chan-1] << 1;
            // TO DO
            break;
        case 13 :    /* BPM - CC 13 */
            global_delta = CCvalue_data[chan-1];
            if(DEBUG_MODE)  printf("\tGB_DELTA=%d \r\n", global_delta);
            
            if(mode_global_midi == MODE_GLOB_SEQ_RGB){
                bpm = (((double)global_delta + 1) + 30);
                printf("\tBPM=%f \r\n", bpm);
                bpm = 60.0/bpm*1000;
                printf("\tinBPM=%d ms\r\n", (int)bpm);
                setMainTimer((int)(bpm));
                startMainTimer();
            }
            else{
                stopMainTimer();
            }
            break;
        case 15 :    /* PAN - CC 15 */
            global_pan = CCvalue_data[chan-1] << 1;
            break;
        case 16 :    /* TILT - CC 16 */
            global_tilt = CCvalue_data[chan-1] << 1;
            break;
        case 14 :    /* SPEED MVT - CC 14 */
            global_pt_speed = CCvalue_data[chan-1] << 1;
            break;
        default:
            break;
    }
}
/* Action à réaliser / Séquenceur / CC Midi */
void    processCCMidiSequ(uint8_t chan){
    
}

/* Action globale */
void    processAllTime(void){
    uint8_t c[6];
    switch(mode_global_midi){
        case MODE_GLOB_BLACKOUT :
            setAllNoFuncMode(0);
            getColor(COLOR_BLACK, c);
            setAllColorSpots(0, c);
            stopMainTimer();
            break;
        case MODE_GLOB_WHITE :  
            setAllNoFuncMode(0);         
            setAllDimmerSpots(0, global_dimmer);
            setAllRSpots(0, global_w);
            setAllGSpots(0, global_w);
            setAllBSpots(0, global_w);
            setAllASpots(0, 0);
            setAllWSpots(0, global_w);
            setAllUVSpots(0, 0);
            stopMainTimer();
            break;
        case MODE_GLOB_UV :        
            setAllNoFuncMode(0);   
            setAllDimmerSpots(0, global_dimmer);
            setAllRSpots(0, 0);
            setAllGSpots(0, 0);
            setAllBSpots(0, 0);
            setAllASpots(0, 0);
            setAllWSpots(0, 0);
            setAllUVSpots(0, global_uv);
            stopMainTimer();
            break;
        case MODE_GLOB_STROBE :
            setAllSpeedStrobeSpots(0, global_strobe_speed);
            setAllDimmerSpots(0, global_dimmer);
            setAllRSpots(0, global_r);
            setAllGSpots(0, global_g);
            setAllBSpots(0, global_b);
            setAllASpots(0, global_a);
            setAllWSpots(0, global_w);
            setAllUVSpots(0, global_uv);
            stopMainTimer();
            break;
        case MODE_GLOB_RGB :
            if(DEBUG_MODE)  printf("GD = %d \r\n", global_dimmer);
            setAllNoFuncMode(0);
            setAllDimmerSpots(0, global_dimmer);
            setAllRSpots(0, global_r);
            setAllGSpots(0, global_g);
            setAllBSpots(0, global_b);
            setAllASpots(0, global_a);
            setAllWSpots(0, global_w);
            setAllUVSpots(0, global_uv);
            stopMainTimer();
            break;
        case MODE_GLOB_SOUND :
            setAllSoundMode(0, 0);  
            setAllDimmerSpots(0, global_dimmer);   
            stopMainTimer();
            break;
        case MODE_GLOB_FADE :   
            setAllNoFuncMode(0);
            setAllDimmerSpots(0, global_dimmer);
            setAllFadeSpots(0);  
            stopMainTimer();
            break;
        default:
            break;
    }
    setAllPan(0, global_pan);
    setAllTilt(0, global_tilt);
    setAllPTSpeed(0, global_pt_speed);
}


void    seq_rgb_glob(void){
    if(isMainTimer()){
        if(mode_global_midi == MODE_GLOB_SEQ_RGB){
            setAllGlobalSpots(0);
            for(int k = 0; k < SEQ_RGB_SPOTS; k++){
                uint8_t step = seq_rgb_cpt % SEQ_RGB_STEPS;
                for(int kk = 0; kk < NB_SPOTS; kk++){
                    if(spots[kk].getGroup() == k+1){
                        setAllDimmerSpots(kk, (global_dimmer/2) * seq_rgb_steps[SEQ_RGB_SPOTS*step + k]);
                    }
                }
            }
            seq_rgb_cpt++;
        }
    }
}