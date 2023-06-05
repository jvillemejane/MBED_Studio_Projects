#include "DMX_2_MIDI.h"

#define WAIT_TIME_MS 500 

DigitalIn   bp(PC_13);


int main()
{
    int cpt = 0;
    printf("Test\r\n");

    // Initialisation périphériques    
    initMIDI1();
    initMIDI2();
/*
    initMIDI3();
*/ 
    initDMX();

    /* DMX */
    clearDMX();
    updateDMX();

    mode_midi[0] = MODE_CTRL;
    mode_midi[1] = MODE_KEYB;
    mode_midi[2] = MODE_SEQ;

    mode_global_midi = MODE_GLOB_BLACKOUT;
    global_dimmer = 0;
    global_pan = 0;
    global_tilt = 0;
    global_pt_speed = 0;
    global_color = 0;
    global_seq_nb = 0;
    global_delta = 100;

    /* SD Card */    
    //initSPI();
    // Spots adress
    //openNewAddress("000");

    configSpots();

    // Black Out
    for(int k = 0; k < NB_SPOTS; k++){
        spots[k].setModeNoFunc();
        spots[k].setDimmer(0);
    }
    uint8_t c[6];
    getColor(COLOR_N, c);
    setAllColorSpots(0, c);

    thread_sleep_for(10);

    // setAllDimmerSpots(0, 100);

    for(int kk = 0; kk < NB_SPOTS; kk++){
        printf("K=%d - Gpe = %d - DIM = %d\r\n", kk, spots[kk].getGroup(), spots[kk].getChanDimmer());
    }


    // MAIN LOOP
    while(true) { 
        /* MIDI */
        detectNoteMIDI(1);
        detectCCMIDI(1);
        detectNoteMIDI(2);
        detectCCMIDI(2);
        /*
        detectNoteMIDI(3);
        detectCCMIDI(3);
        */
        /* Test */
        //

        /* DMX */
        updateSpots(spots);
        updateDMX();
        thread_sleep_for(10);
    }
}
