/*H**********************************************************************
* FILENAME :        M2D_DMX_PRESETS.cpp            
*
* DESCRIPTION :
*       DMX Presets - spots and address - routines.
*
* NOTES :
*       These functions are a part of the MIDI2DMX application
*       Developped by Villou / LEnsE
**
* AUTHOR :    Julien VILLEMEJANE        START DATE :    22/sept/2022
*
*       LEnsE / Institut d'Optique Graduate School
*H***********************************************************************/

#include    "M2D_DMX_PRESETS.h"
#include    "M2D_DMX_SPOTS.h"
#include <cstdint>

/****************************************************/
/* Global Variables                                 */
/****************************************************/
M2D_DMX_SPOTS       *spots_list;
uint8_t             global_spots_number;
uint8_t             global_spots_dimmer;
uint8_t             global_mode;
uint8_t             global_R;
uint8_t             global_G;
uint8_t             global_B;
uint8_t             global_A;
uint8_t             global_W;
uint8_t             global_UV;

/****************************************************/
/* Functions                                        */  
/****************************************************/

/* Spots List Initialization */
void        initSpots(void){
    global_spots_number = 0;
    global_mode = DMX_MODE_BLACKOUT;
    spots_list = new M2D_DMX_SPOTS[64];
    global_spots_dimmer = 128;
}