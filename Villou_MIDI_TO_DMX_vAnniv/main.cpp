#include "DMX_2_MIDI.h"
#include "DMX_MIDI.h"
#include <string.h>
#include "CONFIG_SPOT_MIDI.h"

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
    initMIDI3();
    initDMX();

    /* DMX */
    clearDMX();
    updateDMX();

    mode_midi[0] = MODE_CTRL;
    mode_midi[1] = MODE_KEYB;
    mode_midi[2] = MODE_SEQ;

    /* SD Card */    
    //initSPI();
    // Spots adress
    //openNewAddress("000");

    configSpots();

    // Black Out
    for(int k = 0; k < NB_SPOTS; k++){
        spots[k].setModeNoFunc();
        spots[k].setDimmer(200);
        spots[k].blackOut();
    }

    wait_us(10000);
    // MAIN LOOP
    while(true) { 
        cpt++;
        /* MIDI */
        detectNoteMIDI(1);
        detectCCMIDI(1);
        detectNoteMIDI(2);
        detectCCMIDI(2);
        detectNoteMIDI(3);
        detectCCMIDI(3);
        /* Test */
        testConfigSpots();
        /* DMX */
        printf("%d\r\n", cpt);
        updateSpots(spots);
        updateDMX();
        wait_us(12000);
    }
}
