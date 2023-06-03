#include "DMX_2_MIDI.h"
#include "DMX_MIDI.h"
#include <cstdint>
#include <string.h>
#include "CONFIG_SPOT_MIDI.h"
#include "CONFIG_PRESETS.h"

#define WAIT_TIME_MS 500 

DigitalIn   bp(PC_13);


int main()
{
    int cpt = 0;
    printf("Test\r\n");
    debug_out = 1;
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

    /* SD Card */    
    //initSPI();
    // Spots adress
    //openNewAddress("000");


    configSpots();

    /* Main Timer */
    setMainTimer(5000);
    //startMainTimer();

    // Black Out
    for(int k = 0; k < NB_SPOTS; k++){
        spots[k].setModeNoFunc();
        spots[k].setDimmer(0);
        spots[k].blackOut();
    }

    wait_us(10000);

    setAllDimmerSpots(0, 100);
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
        if(isMainTimer()){
            cpt++;
            printf("%d\r\n", cpt);
            /*
            if(cpt % 2 == 0){
                uint8_t c[6];
                getColor(COLOR_WHITE, c);
                 
                setAllColorSpots(5, c);
                setAllPosition(5, 250, 200 << 8, 200 << 8);
                setAllDimmerSpots(5, 50);
            }
            else{
                setAllColorRGBSpots(5, 0, 0, 255);
                setAllColorAWUVSpots(5, 0, 100, 0);
                setAllPosition(5, 10, 100 << 8, 150 << 8);
                setAllDimmerSpots(5, 20);
            }
            */
        }

        /* DMX */
        updateSpots(spots);
        updateDMX();
        wait_us(10000);
    }
}
