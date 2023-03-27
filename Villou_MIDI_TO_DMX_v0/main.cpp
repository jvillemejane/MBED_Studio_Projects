/****************************************************************************/
/*  Test DMX512 on F767ZI Nucleo board                                      */
/****************************************************************************/
/*  LEnsE / Julien VILLEMEJANE       /   Institut d'Optique Graduate School */
/****************************************************************************/
/*  Pinout based on F767ZI DMX extension Board                                                                */
/*      @see : https://github.com/jvillemejane/LEnsE_IOGS_Maquettes/tree/main/Maquettes/Elec_Num_Emb/MIDI_DMX_F767
                                                                            */
/****************************************************************************/
/*  Tested on STM Nucleo-F767ZI                                             */
/****************************************************************************/


#include "mbed.h"
#include "DMX_MIDI.h"

#define WAIT_TIME_MS 500 

UnbufferedSerial    debug_pc(USBTX, USBRX);
char            debugMsg[64];
DigitalOut          debug_out(D13);
DigitalIn           bp(PC_13);

int main()
{
    debug_pc.baud(115200);
    sprintf(debugMsg, "Test\r\n");
    debug_pc.write(debugMsg, strlen(debugMsg));

    debug_out = 1;
    
    /* Peripheral Initialization */
    initMIDI(1);
    initMIDI(2);
    initDMX();

    /* DMX */
    clearDMX();
    updateDMX();
    
    // LVPT12 Led Spot channel at address 1
    dmx_data[0] = 0;
    dmx_data[3] = 255;
    dmx_data[4] = 255;
    dmx_data[5] = 100;
    dmx_data[6] = 50;

    while(1) { 
        /* MIDI */
        
        if(isNoteMIDIdetected(1)){
            if(note_data[0] == 0x3C){
                dmx_data[4] = 2*velocity_data[0];
                dmx_data[5] = 0;
                dmx_data[6] = 0;
            }
            if(note_data[0] == 0x3E){
                dmx_data[4] = 0;
                dmx_data[5] = velocity_data[0];
                dmx_data[6] = 0;
            }                
            resetNoteMIDI(1);
        }
        
        if(isCCMIDIdetected(1)){
            if(control_ch[0] == 1){
                dmx_data[4] = 2 * control_value[0];
                dmx_data[12] = 2 * control_value[0];
            }
            resetCCMIDI(1);
        }
        
        updateDMX();
        wait_us(10000);
        
    }
}

