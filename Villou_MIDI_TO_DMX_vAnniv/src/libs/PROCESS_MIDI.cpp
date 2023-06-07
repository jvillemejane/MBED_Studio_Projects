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
#include <chrono>
#include <cstdint>
#include <cstdlib>

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
            break;
        case 50 :   /* Global WHITE */
            mode_global_midi = MODE_GLOB_WHITE;
            if(DEBUG_MODE)  printf("WHITE MODE\r\n");   
            break;
        case 51 :   /* Global UV */
            mode_global_midi = MODE_GLOB_UV;
            if(DEBUG_MODE)  printf("UV MODE\r\n"); 
            break;
        case 36 :   /* Couleur 5 */
            if(DEBUG_MODE)  printf("COL MODE\r\n");
            mode_global_midi = MODE_GLOB_COL;
            global_color = color_pads[4];
            break;
        case 37 :   /* Couleur 6 */
            mode_global_midi = MODE_GLOB_COL;
            global_color = color_pads[5];
            break;
        case 38 :   /* Couleur 7 */
            mode_global_midi = MODE_GLOB_COL;
            global_color = color_pads[6];
            break;
        case 39 :   /* Couleur 8 */
            mode_global_midi = MODE_GLOB_COL;
            global_color = color_pads[7];
            break;
        case 40 :   /* Couleur 1 */
            mode_global_midi = MODE_GLOB_COL;
            global_color = color_pads[0];
            break;
        case 41 :   /* Couleur 2 */
            mode_global_midi = MODE_GLOB_COL;
            global_color = color_pads[1];
            break;
        case 42 :   /* Couleur 3 */
            mode_global_midi = MODE_GLOB_COL;
            global_color = color_pads[2];
            break;
        case 43 :   /* Couleur 4 */
            mode_global_midi = MODE_GLOB_COL;
            global_color = color_pads[3];
            break;
        case 56 :   /* Couleur 9 */
            mode_global_midi = MODE_GLOB_COL;
            global_color = color_pads[8];
            break;
        case 57 :   /* Couleur 10 */
            mode_global_midi = MODE_GLOB_COL;
            global_color = color_pads[9];
            break;

        case 44:    /* SEQ1 mode */
            mode_global_midi = MODE_GLOB_SEQ;
            global_seq_nb = 1;
            global_seq_nb_cpt = 0;
            startMainTimer();
            break;
        case 45:    /* SEQ2 mode */
            mode_global_midi = MODE_GLOB_SEQ;
            global_seq_nb = 2;
            global_seq_nb_cpt = 0;
            startMainTimer();
            break;
        case 46:    /* SEQ3 mode */
            mode_global_midi = MODE_GLOB_SEQ;
            global_seq_nb = 3;
            global_seq_nb_cpt = 0;
            startMainTimer();
            break;
        case 47:    /* SEQ4 mode */
            mode_global_midi = MODE_GLOB_SEQ;
            global_seq_nb = 4;
            global_seq_nb_cpt = 0;
            startMainTimer();
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
            startMainTimer();   
            break;
            
        case 58 :   /* Fade MODE */
            mode_global_midi = MODE_GLOB_FADE;
            global_seq_nb_cpt = 0;
            startMainTimer();
            break;
        case 62 :   /* Fade MODE - No Pan */
            mode_global_midi = MODE_GLOB_FADE_NPAN;
            global_seq_nb_cpt = 0;
            startMainTimer();
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
    uint8_t note = note_data[chan-1];
    if(mode_global_midi == MODE_GLOB_KEYB_A){
        uint8_t c[6];
        // Modif Couleurs c[]
        setAllColorSpots(0, c);
    }
    if(mode_global_midi == MODE_GLOB_KEYB_M){
        note = note % KEY_NB;
        // color
        setGpeColorSpots(note);
        // mode strobe
        for(int kk = 0; kk < MIDI_CH; kk++){
            uint8_t strobe_on = key_strobe[note*MIDI_CH + kk];
            if(strobe_on == 1){
                setAllStrobeMode(kk, 0);
            }
            else{
                setAllNoFuncMode(kk);
            }
        }

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
            
            switch(mode_global_midi){
                case MODE_GLOB_SEQ_RGB :
                    bpm = (((double)global_delta + 1) + 30);
                    if(DEBUG_MODE)  printf("\tBPM=%f \r\n", bpm);
                    printf("\tBPM=%f \r\n", bpm);
                    bpm = 60.0/bpm*1000;
                    if(DEBUG_MODE)  printf("\tinBPM=%d ms\r\n", (int)bpm);
                    setMainTimer((int)(bpm));
                    startMainTimer();
                    break;
                case MODE_GLOB_SEQ :
                    bpm = (((double)global_delta + 1)/2.0 + 70);
                    if(DEBUG_MODE)  printf("\tBPM=%f \r\n", bpm);
                    printf("\tBPM=%f \r\n", bpm);
                    bpm = 60.0/bpm*1000;
                    if(DEBUG_MODE)  printf("\tinBPM=%d ms\r\n", (int)bpm);
                    setMainTimer((int)(bpm));
                    startMainTimer();
                    break;
                case MODE_GLOB_FADE :
                case MODE_GLOB_FADE_NPAN :
                    bpm = 1 + 1.0/(global_delta + 1)*100;
                    printf("\tinBPM=%d ms\r\n", (int)bpm);
                    setMainTimer((int)(bpm));
                    startMainTimer();
                    break;
                default:
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
            getColor(COLOR_N, c);
            setAllColorSpots(0, c);
            setAllPan(0, global_pan);
            setAllTilt(0, global_tilt);
            setAllPTSpeed(0, global_pt_speed);
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
            setAllPan(0, global_pan);
            setAllTilt(0, global_tilt);
            setAllPTSpeed(0, global_pt_speed);
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
            setAllPan(0, global_pan);
            setAllTilt(0, global_tilt);
            setAllPTSpeed(0, global_pt_speed);
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
            setAllPan(0, global_pan);
            setAllTilt(0, global_tilt);
            setAllPTSpeed(0, global_pt_speed);
            // TO DO - POS ALEATOIRE PAN/TILT
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
            setAllPan(0, global_pan);
            setAllTilt(0, global_tilt);
            setAllPTSpeed(0, global_pt_speed);
            stopMainTimer();
            break;
        case MODE_GLOB_SOUND :
            setAllSoundMode(0, 0);  
            setAllDimmerSpots(0, global_dimmer);   
            stopMainTimer();
            break;
        case MODE_GLOB_FADE :   
            fade_mode_glob();
            setAllDimmerSpots(0, global_dimmer);
            break;
        case MODE_GLOB_FADE_NPAN :   
            fade_mode_glob();
            setAllDimmerSpots(0, global_dimmer);
            setAllPan(0, global_pan);
            setAllTilt(0, global_tilt);
            setAllPTSpeed(0, global_pt_speed);
            break;
        case MODE_GLOB_KEYB_M:
            setAllNoFuncMode(0);
            // Color / Strobe DONE in processNoteMidiKeyb
            setAllPan(0, global_pan);
            setAllTilt(0, global_tilt);
            stopMainTimer();
            break;
        case MODE_GLOB_KEYB_A :   
            setAllNoFuncMode(0);
            // TO DO
            setAllPan(0, global_pan);
            setAllTilt(0, global_tilt);
            stopMainTimer();
            break;
        case MODE_GLOB_COL:
            setAllNoFuncMode(0);
            setGpeColorSpots(global_color);
            setAllDimmerSpots(0, global_dimmer);
            setAllPan(0, global_pan);
            setAllTilt(0, global_tilt);
            setAllPTSpeed(0, global_pt_speed);
            stopMainTimer();
            break;
        case MODE_GLOB_SEQ:
            seq_nb_glob(global_seq_nb);
            setAllDimmerSpots(0, global_dimmer);
            break;
        case MODE_GLOB_SEQ_RGB:
            seq_rgb_glob();
            setAllDimmerSpots(0, global_dimmer);
            break;
        default:
            break;
    }
}

void    seq_nb_glob(uint8_t nb){
    uint8_t seq[33];

    if(isMainTimer()){
        switch(nb){
            case 1:
                cpyTab(seq1, seq, 33);
                break;
            case 2:
                cpyTab(seq2, seq, 33);
                break;
            case 3:
                cpyTab(seq3, seq, 33);
                break;
            case 4:
            default:
                cpyTab(seq4, seq, 33);
                break;
        }
        uint8_t nb_steps = seq[0];
        if(mode_global_midi == MODE_GLOB_SEQ){
            setAllGlobalSpots(0);
            setGpeColorSpots(seq[global_seq_nb_cpt+1]);

            // affectation position aleatoire
            uint8_t nb_choice = rand() % POS_NB;            
            setAllPan(0, positions[nb_choice*4 + 0]);
            setAllTilt(0, positions[nb_choice*4 + 1]);
            setAllPTSpeed(0, positions[nb_choice*4 + 2]);

            // mode strobe
            for(int kk = 0; kk < MIDI_CH; kk++){
                uint8_t strobe_on = key_strobe[seq[global_seq_nb_cpt+1]*MIDI_CH + kk];
                if(strobe_on == 1){
                    setAllStrobeMode(kk, 0);
                }
            }

            global_seq_nb_cpt++;
            if(global_seq_nb_cpt == nb_steps)   global_seq_nb_cpt = 0;
        }
    }
}

void    seq_rgb_glob(void){
    // TO FINISH
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
            
            // affectation position aleatoire
            uint8_t nb_choice = rand() % POS_NB;            
            setAllPan(0, positions[nb_choice*4 + 0]);
            setAllTilt(0, positions[nb_choice*4 + 1]);
            setAllPTSpeed(0, positions[nb_choice*4 + 2]);
            seq_rgb_cpt++;
        }
    }
}

void    fade_mode_glob(void){
    if(isMainTimer()){
        if((mode_global_midi == MODE_GLOB_FADE) || (mode_global_midi == MODE_GLOB_FADE_NPAN)){
            setAllGlobalSpots(0);
            uint8_t     c[6];
            c[3] = 0;
            c[4] = 0;
            c[5] = 0;
            for(int k = 0; k < MIDI_CH; k++){   // parcourt des 16 groupes de spots
                // choix couleurs
                c[0] = fade_ramp[((global_seq_nb_cpt + (0 * FADE_STEPS / 3)) + k * FADE_STEPS/MIDI_CH)% FADE_STEPS ];
                c[1] = fade_ramp[((global_seq_nb_cpt + (1 * FADE_STEPS / 3)) + k * FADE_STEPS/MIDI_CH)% FADE_STEPS ];
                c[2] = fade_ramp[((global_seq_nb_cpt + (2 * FADE_STEPS / 3)) + k * FADE_STEPS/MIDI_CH)% FADE_STEPS ];
                uint8_t pan = fade_ramp[global_seq_nb_cpt % FADE_STEPS ];
                uint8_t tilt = fade_ramp[global_seq_nb_cpt % FADE_STEPS ];
                // affectation couleurs par groupe
                setAllColorSpots(k+1, c);
                if(mode_global_midi == MODE_GLOB_FADE){
                    setAllPan(k+1, pan);
                    setAllTilt(k+1, tilt);
                    setAllPTSpeed(k+1, 100+(global_delta/32));
                }
            }
            global_seq_nb_cpt++;
            if(global_seq_nb_cpt == FADE_STEPS)   global_seq_nb_cpt = 0;
        }
    }
}