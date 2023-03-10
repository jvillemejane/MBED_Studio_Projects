#include "M2D_LENSE.h"

#include "testing.h"

#define WAIT_TIME_MS 500 

DigitalIn   bp(PC_13);



int main()
{
    debug_out = 1;
    /* Peripheral Initialization */
    initMIDI1();
    initMIDI2();
    initMIDI3();
    initDMX();
    initSPI();
    
    /* LCD Display Initialization */
    LCD_DOG_init();     // LCD screen / EA DOG 3x16char / 5V
    LCD_DOG_clear();
    LCD_DOG_writeStr((char *)"MIDI2DMX", 1, 1);
    LCD_DOG_writeStr((char *)"   byVillou", 2, 1);

    /* DMX */
    clearDMX();
    updateDMX();

    /* Global Parameters */
    char    setup_nb[4];
    strcpy(setup_nb, "000");    // config file "000" by default
    initSpots();
    /* Spots Presets */
    openNewAddress(setup_nb);

    // Global config
    openNewConfig(setup_nb);
    mode_midi[0] = MODE_CTRL;
        // Ctrl Mode
        midi1_note_params[0] = 48;     // blackout note
        midi1_note_params[1] = 44;     // allR note
        midi1_note_params[2] = 40;     // allG note
        midi1_note_params[3] = 36;     // allB note
        midi1_note_params[7] = 49;     // allRGBAWUV note
        
        midi1_CC_params[0] = 1;        // dimmer CC
        midi1_CC_params[1] = 2;        // allR CC
        midi1_CC_params[2] = 3;        // allG CC
        midi1_CC_params[3] = 4;        // allB CC
        midi1_CC_params[4] = 5;        // allA CC
        midi1_CC_params[5] = 6;        // allW CC

    mode_midi[1] = MODE_SEQ;

    mode_midi[2] = MODE_KEYB;

    /* TEST */
    int k = spots_list[1].getAdd();
    sprintf(temp_string, "k1 = %d", k);
    LCD_DOG_clear_Line(3);
    LCD_DOG_writeStr(temp_string, 3, 1);
    /* END TEST */

    wait_us(10000);

    /********************************/
    /* MAIN LOOP                    */
    /********************************/
    while(true) { 
        /* MIDI */
        detectNoteMidi_test();
        detectContCtlMidi_test();
        /* DMX */
        updateDMXdata();
        updateDMX();
        wait_us(12000);
    }
}
