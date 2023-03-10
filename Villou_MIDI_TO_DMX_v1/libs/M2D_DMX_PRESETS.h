/*H**********************************************************************
* FILENAME :        M2D_DMX_PRESETS.h            
*
* DESCRIPTION :
*       DMX Presets - spots and address - routines.
*
* PUBLIC FUNCTIONS :
*       int     FM_CompressFile( FileHandle )
*
* NOTES :
*       These functions are a part of the MIDI2DMX application
*       Developped by Villou / LEnsE
**
* AUTHOR :    Julien VILLEMEJANE        START DATE :    22/sept/2022
*
*       LEnsE / Institut d'Optique Graduate School
*H***********************************************************************/

#ifndef     __M2D_DMX_PRESETS_H_INCLUDED
#define     __M2D_DMX_PRESETS_H_INCLUDED

#include    "M2D_LENSE.h"
#include    "M2D_DMX_SPOTS.h"
#include    "M2D_DMX_SPOTS_VALUES.h"


/****************************************************/
/* Global Variables                                 */
/****************************************************/
extern      M2D_DMX_SPOTS       *spots_list;
extern      uint8_t             global_spots_number;
extern      uint8_t             global_spots_dimmer;
extern      uint8_t             global_mode;
extern      uint8_t             global_R;
extern      uint8_t             global_G;
extern      uint8_t             global_B;
extern      uint8_t             global_A;
extern      uint8_t             global_W;
extern      uint8_t             global_UV;

/****************************************************/
/* Functions                                        */  
/****************************************************/

/* Spots List Initialization */
void        initSpots(void);

#endif