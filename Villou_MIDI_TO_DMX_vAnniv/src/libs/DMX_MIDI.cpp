/****************************************************************************/
/*  DMX_MIDI module library                                                 */
/****************************************************************************/
/*  LEnsE / Julien VILLEMEJANE       /   Institut d'Optique Graduate School */
/****************************************************************************/
/*  Library - DMX_MIDI.cpp file                                             */
/****************************************************************************/
/****************************************************************************/
/*  Debugging on USB @ 115200 bauds                                         */
/****************************************************************************/
/*  Board Pinout                                                            */
/*      + DMX (output only) : PE_8, PE_7, PE_12, PE_10, PE_14               */
/*              (uart7 - tx, rx, out_tx, start, enable)                     */
/*      + MIDI1 : PB_9, PB_8 (uart5)                                        */
/*      + MIDI2 : PG_14, PG_9 (uart6)                                       */
/*      + MIDI3 (input only) : PE_0, PE_1   (uart8)                         */
/*      + Analog R,G,B : PF_8, PF_7, PF_9                                   */
/*      + Analog Pitch - Volume : PB_1, PC_2                                */
/*      + Analog In 1 & 2 : PA_6, PA_7                                      */
/*      + LCD : PB_5, PB_4, PB_3, PB_13, PF_13                              */
/*              (mosi, miso, sck, cs, rs)                                   */
/*              EA DOG LCD / 3 lines / SPI mode / 5V                        */
/*      + SD : PE_6, PE_5, PE_2, PE_3                                       */
/*              (mosi, miso, sck, cs)                                       */
/*      + nRF module : PB_5, PB_4, PB_3, PB_15, PC_7, PA_15                 */
/*              (mosi, miso, sck, cs, ce, irq)                              */
/*      + MSGEQ7 : PD_14, PD_15, PA_4                                       */
/*              (strobe, reset, analog out)                                 */
/*      + WS2812 led out : PC_8                                             */
/*      + DAC1 out : PA_5                                                   */
/*      + HC-05 BT module : PD_1, PD_0 (uart4)                              */
/*      + Digital In Pull-Down 1 to 4 : PA_7, PF_2, PF_1, PF_0              */
/****************************************************************************/

#include "DMX_MIDI.h"
#include <cstdint>

/* Entrées - Sorties */
DigitalOut      debug_out(D13);
// DMX
UnbufferedSerial    dmx(PE_8, PE_7);
DigitalOut      out_tx(PE_12); 
DigitalOut      start(PE_10);     //envoie des données
DigitalOut      enableDMX(PE_14 );
// MIDI
UnbufferedSerial  midi1(PB_9, PB_8);  // Midi 1
UnbufferedSerial  midi2(PG_14, PG_9);  // Midi 2
UnbufferedSerial  midi3(PE_1, PE_0);  // Midi 3
//BufferedSerial  midi(USBTX, USBRX);
// Analogiques

/* Variables globales */
uint8_t         dmx_data[SAMPLES] = {0};
uint16_t        channels_int_on[3], channels_int_off[3];
int             rgb;
// Midi
uint8_t         cpt_midi[3];
uint8_t         new_data_midi[3], new_note_midi[3], new_CC_midi[3];
uint8_t         midi_data[3][3], channel_data[3];
uint8_t         note_data[3], velocity_data[3];
uint8_t         CC_data[3], CCvalue_data[3];
int8_t          midi_on;
/* Mode de fonctionnement global en MIDI */
uint8_t         mode_global_midi;

/* Variables pour les valeurs globales d'intensités et couleurs */
uint8_t         global_dimmer, global_r, global_g, global_b;
uint8_t         global_a, global_w, global_uv;
uint8_t         global_pan, global_tilt, global_pt_speed;
uint8_t         global_strobe_speed;
uint8_t         global_color;
uint8_t         global_seq_nb, global_seq_nb_cpt;
/* Variable de temps global / BPM */
uint8_t         global_delta;

/* Compteur pour le mode séquenceur RGB */
uint8_t         seq_rgb_cpt;

/* DMX output initialization */
void initDMX(void){
    dmx.baud(250000);
    dmx.format(8, SerialBase::None, 2);
    enableDMX = 0;
    // Initialisation canaux DMX
    clearDMX();
    updateDMX();
} 

/* Clear internal values for DMX output */
void clearDMX(){
    for(int k = 0; k < SAMPLES; k++){
        dmx_data[k] = 0;
    }
}

/* Updating DMX output with internal values */
void updateDMX(){
    enableDMX = 1;
    
    wait_us(5); 
    start = 1;      // /start
    out_tx = 0;     // break
    wait_us(88);    
    out_tx = 1;     // mb
    wait_us(8);     
    out_tx = 0;     // break
    start = 0;
    uint8_t     temp_data = 0;
    dmx.write(&temp_data, 1);     // Start
    for(int i = 0; i < SAMPLES; i++){
        dmx.write(&dmx_data[i], 1);     // data
        wait_us(5);
    }
    wait_us(5); 
    enableDMX = 0;
    thread_sleep_for(2); // time between frame
}

/* Fonction d'initialisation de la liaison MIDI */
void initMIDI1(void){
    midi_on = 0;
    midi1.baud(31250);
    midi1.format(8, SerialBase::None, 1);
    //midi1.sigio(callback(ISR_midi_in));
    midi1.attach(&ISR_midi_in);
    channels_int_on[0] = 0;
    channels_int_off[0] = 0;
}

/* Fonction d'initialisation de la liaison MIDI */
void initMIDI2(void){
    midi_on = 0;
    midi2.baud(31250);
    midi2.format(8, SerialBase::None, 1);
    //midi2.sigio(callback(ISR_midi_in));
    midi2.attach(&ISR_midi_in);
    channels_int_on[1] = 0;
    channels_int_off[1] = 0;
}
/* Fonction d'initialisation de la liaison MIDI */
void initMIDI3(void){
    midi_on = 0;
    midi3.baud(31250);
    midi3.format(8, SerialBase::None, 1);
    //midi3.sigio(callback(ISR_midi_in));
    midi3.attach(&ISR_midi_in);
    channels_int_on[2] = 0;
    channels_int_off[2] = 0;
}
/* Detection d'une note reçue en MIDI - entrée MIDI 1 */
void detectNoteMIDI(uint8_t chan){
    if(new_note_midi[chan-1] == 1){
        switch(mode_midi[chan-1]){
            case MODE_CTRL:
                processNoteMidiCtrl(chan);
                break;
            case MODE_KEYB:
                processNoteMidiKeyb(chan);
                break;
            case MODE_SEQ:
                processNoteMidiSequ(chan);
                break;
            default:
                processNoteMidiCtrl(chan);
        }
        new_note_midi[chan-1] = 0;
        if(DEBUG_MODE) printf("MIDI%d - %x - %d %d \r\n", chan, midi_data[chan-1][0], note_data[chan-1], velocity_data[chan-1]);
    }
}
/* Detection d'une note reçue en MIDI - entrée MIDI 1 */
void resetNoteMIDI(uint8_t chan){
    if(new_note_midi[chan-1] == 1){
        new_note_midi[chan-1] = 0;
    }
}

/* Detection d'un CC reçu en MIDI */
void detectCCMIDI(uint8_t chan){
    if(new_CC_midi[chan-1] == 1){
        switch(mode_midi[chan-1]){
            case MODE_CTRL:
                processCCMidiCtrl(chan);
                break;
            case MODE_KEYB:
                break;
            case MODE_SEQ:
                processCCMidiSequ(chan);
                break;
            default:
                processCCMidiCtrl(chan);
        }
        new_CC_midi[chan-1] = 0;
        if(DEBUG_MODE) printf("MIDI%d - %x - %d %d \r\n", chan, midi_data[chan-1][0], note_data[chan-1], velocity_data[chan-1]);
    }    
}
/* Remise à zéro d'un CC reçu en MIDI */
void resetCCMIDI(uint8_t chan){
    if(new_CC_midi[chan-1] == 1){
        new_CC_midi[chan-1] = 0;
    }    
}

/* Joue une note sur la liaison MIDI */
void playNote(char midi_nb, char note, char velocity){
    uint8_t     temp_data[3];
    temp_data[0] = MIDI_NOTE_ON;
    temp_data[1] = note;
    temp_data[2] = velocity;
    switch(midi_nb){
        case 1:
            midi1.write(temp_data, 3);
            break;
        case 2:
            midi2.write(temp_data, 3);
            break;   
        default:
            midi3.write(temp_data, 3);
            break;           
    }
    
}

/* Stoppe une note sur la liaison MIDI */
void stopNote(char midi_nb, char note, char velocity){
    uint8_t     temp_data[3];
    temp_data[0] = MIDI_NOTE_OFF;
    temp_data[1] = note;
    temp_data[2] = velocity;   
    switch(midi_nb){
        case 1:
            midi1.write(temp_data, 3);
            break;
        case 2:
            midi2.write(temp_data, 3);
            break;   
        default:
            midi3.write(temp_data, 3);
            break;           
    }
}

/* Fonction d'interruption sur MIDI */
void ISR_midi_in(void){
    uint8_t data;
    if(midi1.readable()){
        midi1.read(&data, 1);
        midi_on = 1;
    }
    if(midi2.readable()){
        midi2.read(&data, 1);
        midi_on = 2;
    }
    if(midi3.readable()){
        midi3.read(&data, 1);
        midi_on = 3;
    }
    
    midi_on = midi_on-1;
    if(midi_on >= 0){
        if(data >= 128)
            cpt_midi[midi_on] = 0;
        else
            cpt_midi[midi_on]++;
        midi_data[midi_on][cpt_midi[midi_on]] = data;

        if(cpt_midi[midi_on] == 2){
            cpt_midi[midi_on] = 0;

            switch(midi_data[midi_on][0] & 0xF0){
                case    MIDI_NOTE_ON:
                    new_note_midi[midi_on] = 1;
                    channel_data[midi_on] = midi_data[midi_on][0] & 0x0F;
                    channels_int_on[midi_on] += ((0b1) << channel_data[midi_on]);
                    note_data[midi_on] = midi_data[midi_on][1];
                    velocity_data[midi_on] = midi_data[midi_on][2];
                    if(velocity_data[midi_on] == 0){ new_note_midi[midi_on] = 2;}        // equivalent to note off if velocity is equal to 0
                    break;
                case    MIDI_NOTE_OFF:
                    new_note_midi[midi_on] = 2;
                    channel_data[midi_on] = midi_data[midi_on][0] & 0x0F;
                    channels_int_off[midi_on] += ((0b1) << channel_data[midi_on]);
                    note_data[midi_on] = midi_data[midi_on][1];
                    velocity_data[midi_on] = midi_data[midi_on][2];
                    break;
                case    MIDI_CONTINUOUS_CTL :
                    new_CC_midi[midi_on] = 1;   
                    channel_data[midi_on] = midi_data[midi_on][0] & 0x0F;
                    channels_int_off[midi_on] += ((0b1) << channel_data[midi_on]);
                    CC_data[midi_on] = midi_data[midi_on][1];
                    CCvalue_data[midi_on] = midi_data[midi_on][2];
                    break;             
                default:
                    new_data_midi[midi_on] = 1;
            }
            
            midi_on = -1;
        }
    }
}

/* Mise à jour tableau data */
void updateSpots(DMX_spots spots[]){
    processAllTime();
    for(int k = 0; k < NB_SPOTS; k++){
        spots[k].updateData(dmx_data);
    }
}