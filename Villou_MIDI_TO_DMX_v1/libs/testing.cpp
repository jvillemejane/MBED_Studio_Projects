#include    "M2D_LENSE.h"

/* ************* */
/* FUNCTION TEST */
/* ************* */



void detectContCtlMidi_test(void){
    for(int k = 0; k < 3; k++){
        if(new_CC_midi[k] == 1){
            
            LCD_DOG_clear_Line(1);
            LCD_DOG_writeStr((char *)"OK_CC", 1, 1);

            switch(mode_midi[k]){
                case MODE_CTRL :
                    if(DEBUG){
                        LCD_DOG_clear_Line(3);
                        sprintf(temp_string, "MD%d-CTRL-%2d", k+1, note_data[k]);
                        LCD_DOG_writeStr(temp_string, 3, 1);
                    }
                    detectCCMidiCTRLMode(k+1);
                    break;
                case MODE_KEYB :
                    if(DEBUG){
                        LCD_DOG_clear_Line(3);
                        sprintf(temp_string, "MD%d-KEYB-%2d", k+1, note_data[k]);
                        LCD_DOG_writeStr(temp_string, 3, 1);
                    }
                    // detectCCMidiKEYBMode(k+1);
                    break;
                case MODE_SEQ :
                    if(DEBUG){
                        LCD_DOG_clear_Line(3);
                        sprintf(temp_string, "MD%d- SEQ-%2d", k+1, note_data[k]);
                        LCD_DOG_writeStr(temp_string, 3, 1);
                    }
                    break;
                    // detectCCMidiSEQMode(k+1);
                default:
                    if(DEBUG){
                        LCD_DOG_clear_Line(3);
                        sprintf(temp_string, "MD%d-NoMode", k+1);
                        LCD_DOG_writeStr(temp_string, 3, 1);
                    }
            }
        
            new_CC_midi[k] = 0;
        }
    }
}

/* ************* */
void detectNoteMidi_test(void){
    uint8_t     temp_cpt;
    short       adr;

    for(int k = 0; k < 3; k++){
        if(new_note_midi[k] == 1){         // NOTE_ON
        
            LCD_DOG_clear_Line(1);
            LCD_DOG_writeStr((char *)"OK_NOTE", 1, 1);

            switch(mode_midi[k]){
                case MODE_CTRL :
                    if(DEBUG){
                        LCD_DOG_clear_Line(3);
                        sprintf(temp_string, "MD%d-CTRL-%2d", k+1, note_data[k]);
                        LCD_DOG_writeStr(temp_string, 3, 1);
                    }
                    detectNoteMidiCTRLMode(k+1);
                    break;
                case MODE_KEYB :
                    if(DEBUG){
                        LCD_DOG_clear_Line(3);
                        sprintf(temp_string, "MD%d-KEYB-%2d", k+1, note_data[k]);
                        LCD_DOG_writeStr(temp_string, 3, 1);
                    }
                    // detectNoteMidiKEYBMode(k+1);
                    break;
                case MODE_SEQ :
                    if(DEBUG){
                        LCD_DOG_clear_Line(3);
                        sprintf(temp_string, "MD%d- SEQ-%2d", k+1, note_data[k]);
                        LCD_DOG_writeStr(temp_string, 3, 1);
                    }
                    // detectNoteMidiSEQMode(k+1);
                    break;
                default:
                    if(DEBUG){
                        LCD_DOG_clear_Line(3);
                        LCD_DOG_writeStr((char *)"MIDI1 - No Mode", 3, 1);
                    }
            }
            
            /*
            for(uint8_t channel = 0; channel < 16; channel++){
                if((channels_int_on[0] & ((0b1) << channel)) != 0){
                    for(temp_cpt = 0; temp_cpt < channel_ad_nb[channel][1]; temp_cpt++){
                        adr = channel_ad_nb[channel][0];
                        if(temp_cpt < 8){
                            if(temp_cpt != channel_dim[channel][0] - 1){      // All channels except Dimmer channel
                                dmx_data[adr + temp_cpt] = channel_dmxConfig[channel][temp_cpt];
                            }
                        }    
                    }
                }
            }
            */
            channels_int_on[k] = 0;
        }
        if(new_note_midi[k] == 2){        // NOTE_OFF

            /*
            for(uint8_t channel = 0; channel < 16; channel++){
                if((channels_int_off[0] & ((0b1) << channel)) != 0){
                    for(temp_cpt = 0; temp_cpt < channel_ad_nb[channel][1]; temp_cpt++){
                        adr = channel_ad_nb[channel][0];
                        if(temp_cpt != channel_dim[channel][0] - 1){      // All channels except Dimmer channel
                            if(temp_cpt < 8)    dmx_data[adr + temp_cpt] = 0;
                        }
                    }
                }
            }
            */
            channels_int_off[k] = 0;    
        }
        if(new_note_midi[k] != 0){
            new_note_midi[k] = 0;  
        }
    }
}
/* ***************** */
/* END FUNCTION TEST */
/* ***************** */
