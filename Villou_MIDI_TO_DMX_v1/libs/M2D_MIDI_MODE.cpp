/*H**********************************************************************
* FILENAME :        M2D_MIDI_MODE.cpp           
*
* DESCRIPTION :
*       MIDI Mode processing routines.
*
* NOTES :
*       These functions are a part of the MIDI2DMX application
*       Developped by Villou / LEnsE
**
* AUTHOR :    Julien VILLEMEJANE        START DATE :    22/sept/2022
*
*       LEnsE / Institut d'Optique Graduate School
*H***********************************************************************/


#include    "M2D_MIDI_MODE.h"


/* Global Variables */
uint8_t     mode_midi[3] = {0};     // Midi Mode

uint8_t     midi1_note_params[32];
uint8_t     midi1_CC_params[16];   
uint8_t     midi2_note_params[32];
uint8_t     midi2_CC_params[16];
uint8_t     midi3_note_params[32];
uint8_t     midi3_CC_params[16];

/****************************************************/
/* Functions                                        */  
/****************************************************/
/* Note detection - Controller mode */
void detectNoteMidiCTRLMode(uint8_t midi){
    uint8_t     midi_param = 64;
    for(int k = 0; k < 32; k++){
        switch(midi){
            case 1 :
                if(midi1_note_params[k] == note_data[0]){
                    midi_param = k;
                }
                break;
            case 2 :
                if(midi2_note_params[k] == note_data[1]){
                    midi_param = k;
                }
                break;
            case 3 :
                if(midi3_note_params[k] == note_data[2]){
                    midi_param = k;
                }
                break;
            default :
                __nop();
        }
    }
    switch(midi_param){
        case 0 :        // blackout
            for(int k_spot = 0; k_spot < global_spots_number; k_spot++){
                spots_list[k_spot].setDimmer(0);
            }
            global_mode = DMX_MODE_BLACKOUT;     
            LCD_DOG_clear_Line(1);
            LCD_DOG_writeStr((char *)"BlackOut", 1, 1);
            break;
        case 1 :        // allR
            for(int k_spot = 0; k_spot < global_spots_number; k_spot++){
                spots_list[k_spot].setRGB(255, 0, 0);
                spots_list[k_spot].setA(0);
                spots_list[k_spot].setW(0);
                spots_list[k_spot].setUV(0);
                spots_list[k_spot].setDimmer(global_spots_dimmer);
            }
            global_mode = DMX_MODE_NO;
            break;
        case 2 :        // allG
            for(int k_spot = 0; k_spot < global_spots_number; k_spot++){
                spots_list[k_spot].setRGB(0, 255, 0);
                spots_list[k_spot].setA(0);
                spots_list[k_spot].setW(0);
                spots_list[k_spot].setUV(0);
                spots_list[k_spot].setDimmer(global_spots_dimmer);
            }
            global_mode = DMX_MODE_NO;
            break;            
        case 3 :        // allB
            for(int k_spot = 0; k_spot < global_spots_number; k_spot++){
                spots_list[k_spot].setRGB(0, 0, 255);
                spots_list[k_spot].setA(0);
                spots_list[k_spot].setW(0);
                spots_list[k_spot].setUV(0);
                spots_list[k_spot].setDimmer(global_spots_dimmer);
            }
            global_mode = DMX_MODE_NO;
            break;      
        case 4 :        // allA
            for(int k_spot = 0; k_spot < global_spots_number; k_spot++){
                spots_list[k_spot].setRGB(0, 0, 0);
                spots_list[k_spot].setA(255);
                spots_list[k_spot].setW(0);
                spots_list[k_spot].setUV(0);
                spots_list[k_spot].setDimmer(global_spots_dimmer);
            }
            global_mode = DMX_MODE_NO;
            break; 
        case 5 :        // allW
            for(int k_spot = 0; k_spot < global_spots_number; k_spot++){
                spots_list[k_spot].setRGB(0, 0, 0);
                spots_list[k_spot].setA(0);
                spots_list[k_spot].setW(255);
                spots_list[k_spot].setUV(0);
                spots_list[k_spot].setDimmer(global_spots_dimmer);
            }
            global_mode = DMX_MODE_NO;
            break;    
        case 6 :        // allUV
            for(int k_spot = 0; k_spot < global_spots_number; k_spot++){
                spots_list[k_spot].setRGB(0, 0, 0);
                spots_list[k_spot].setA(0);
                spots_list[k_spot].setW(0);
                spots_list[k_spot].setUV(255);
                spots_list[k_spot].setDimmer(global_spots_dimmer);
            }
            global_mode = DMX_MODE_NO;
            break;
        case 7 :        // allRGBAWUV
            for(int k_spot = 0; k_spot < global_spots_number; k_spot++){
                spots_list[k_spot].setRGB(global_R, global_G, global_B);
                spots_list[k_spot].setA(global_A);
                spots_list[k_spot].setW(global_W);
                spots_list[k_spot].setUV(global_UV);
                spots_list[k_spot].setDimmer(global_spots_dimmer);
            }
            global_mode = DMX_MODE_RGBAWUV;
            break;
        default :
            // TO DO
            global_mode = DMX_MODE_NO;
            __nop();
    }
}


/* CC detection - Controller mode */
void detectCCMidiCTRLMode(uint8_t midi){
    uint8_t     midi_param = 64;

    for(int k = 0; k < 16; k++){
        switch(midi){
            case 1 :
                if(midi1_CC_params[k] == note_data[0]){
                    midi_param = k;
                }
                break;
            case 2 :
                if(midi2_CC_params[k] == note_data[1]){
                    midi_param = k;
                }
                break;
            case 3 :
                if(midi3_CC_params[k] == note_data[2]){
                    midi_param = k;
                }
                break;
            default :
                __nop();
        }
    }

    switch(midi_param){
        case 0 :        // dimmer
            global_spots_dimmer = 2*velocity_data[midi-1];
            if(global_mode != DMX_MODE_BLACKOUT){
                for(int k_spot = 0; k_spot < global_spots_number; k_spot++){
                    spots_list[k_spot].setDimmer(global_spots_dimmer);
                }                 
            }
            else{
                for(int k_spot = 0; k_spot < global_spots_number; k_spot++){
                    spots_list[k_spot].setDimmer(0);
                }                 
            }
            LCD_DOG_clear_Line(1);
            LCD_DOG_writeStr((char *)" Global Dimmer", 1, 1);
            break;
        case 1 :        // allR
            global_R = 2*velocity_data[midi-1];
            switch(global_mode){
                case DMX_MODE_RGBAWUV :
                    for(int k_spot = 0; k_spot < global_spots_number; k_spot++){
                        spots_list[k_spot].setR(global_R);
                        spots_list[k_spot].setDimmer(global_spots_dimmer);
                    }
                    break;
                case DMX_MODE_BLACKOUT :
                    for(int k_spot = 0; k_spot < global_spots_number; k_spot++){
                        spots_list[k_spot].setDimmer(0);
                    }
                    break;                
                default :
                    __nop();
            }
            break;
        case 2 :        // allG
            global_G = 2*velocity_data[midi-1];
            if(global_mode == DMX_MODE_NO){
                for(int k_spot = 0; k_spot < global_spots_number; k_spot++){
                    spots_list[k_spot].setG(global_G);
                    spots_list[k_spot].setDimmer(global_spots_dimmer);
                }                 
            }
            else{
                for(int k_spot = 0; k_spot < global_spots_number; k_spot++){
                    spots_list[k_spot].setDimmer(0);
                }                 
            }
            LCD_DOG_clear_Line(1);
            LCD_DOG_writeStr((char *)" Global G", 1, 1);
            break;
        case 3 :        // allB
            global_B = 2*velocity_data[midi-1];
            if(global_mode == DMX_MODE_NO){
                for(int k_spot = 0; k_spot < global_spots_number; k_spot++){
                    spots_list[k_spot].setB(global_B);
                    spots_list[k_spot].setDimmer(global_spots_dimmer);
                }                 
            }
            else{
                for(int k_spot = 0; k_spot < global_spots_number; k_spot++){
                    spots_list[k_spot].setDimmer(0);
                }                 
            }
            LCD_DOG_clear_Line(1);
            LCD_DOG_writeStr((char *)" Global B", 1, 1);
            break;
        default :
            __nop();
    }
}


/* MIDI1 Initialization Routine */
void initMIDI1(void){
    midi1.set_baud(31250);
    midi1.set_format(8, SerialBase::None, 1);
    midi1.sigio(callback(ISR_midi1_in));
    channels_int_on[0] = 0;
    channels_int_off[0] = 0;
}

/* MIDI2 Initialization Routine */
void initMIDI2(void){
    midi2.set_baud(31250);
    midi2.set_format(8, SerialBase::None, 1);
    midi2.sigio(callback(ISR_midi2_in));
    channels_int_on[1] = 0;
    channels_int_off[1] = 0;
}

/* MIDI3 Initialization Routine */
void initMIDI3(void){
    midi3.set_baud(31250);
    midi3.set_format(8, SerialBase::None, 1);
    midi3.sigio(callback(ISR_midi2_in));
    channels_int_on[2] = 0;
    channels_int_off[2] = 0;
}


/* MIDI1 Interrupt Subroutine */
void ISR_midi1_in(void){
    debug_out = !debug_out;
    char data;
    if(midi1.readable()) midi1.read(&data, 1); 
    if(data >= 128)
        cpt_midi = 0;
    else
        cpt_midi++;
    midi_data[0][cpt_midi] = data;
    
    if(cpt_midi == 2){
        cpt_midi = 0;

        switch(midi_data[0][0] & 0xF0){
            case    MIDI_NOTE_ON:
                new_note_midi[0] = 1;
                channel_data[0] = midi_data[0][0] & 0x0F;
                channels_int_on[0] += ((0b1) << channel_data[0]);
                note_data[0] = midi_data[0][1];
                velocity_data[0] = midi_data[0][2];
                if(velocity_data[0] == 0){ new_note_midi[0] = 2;}        // equivalent to note off if velocity is equal to 0
                break;
            case    MIDI_NOTE_OFF:
                new_note_midi[0] = 2;
                channel_data[0] = midi_data[0][0] & 0x0F;
                channels_int_off[0] += ((0b1) << channel_data[0]);
                note_data[0] = midi_data[0][1];
                velocity_data[0] = midi_data[0][2];
                break;
            case    MIDI_CONTINUOUS_CTL :
                new_CC_midi[0] = 1;   
                channel_data[0] = midi_data[0][0] & 0x0F;
                note_data[0] = midi_data[0][1];
                velocity_data[0] = midi_data[0][2];
                break;                            
            default:
                new_data_midi[0] = 1;
        }
    }
}


/* MIDI2 Interrupt Subroutine */
void ISR_midi2_in(void){
    debug_out = !debug_out;
    char data;
    if(midi2.readable()) midi2.read(&data, 1); 
    if(data >= 128)
        cpt_midi = 0;
    else
        cpt_midi++;
    midi_data[1][cpt_midi] = data;
    
    if(cpt_midi == 2){
        cpt_midi = 0;

        switch(midi_data[1][0] & 0xF0){
            case    MIDI_NOTE_ON:
                new_note_midi[1] = 1;
                channel_data[1] = midi_data[1][0] & 0x0F;
                channels_int_on[1] += ((0b1) << channel_data[1]);
                note_data[1] = midi_data[1][1];
                velocity_data[1] = midi_data[1][2];
                if(velocity_data[1] == 0){ new_note_midi[1] = 2;}        // equivalent to note off if velocity is equal to 0
                break;
            case    MIDI_NOTE_OFF:
                new_note_midi[1] = 2;
                channel_data[1] = midi_data[1][0] & 0x0F;
                channels_int_off[1] += ((0b1) << channel_data[1]);
                note_data[1] = midi_data[1][1];
                velocity_data[1] = midi_data[1][2];
                break;
            case    MIDI_CONTINUOUS_CTL :
                new_CC_midi[1] = 1;   
                channel_data[1] = midi_data[1][0] & 0x0F;
                note_data[1] = midi_data[1][1];
                velocity_data[1] = midi_data[1][2];
                break;                            
            default:
                new_data_midi[1] = 1;
        }
    }
}