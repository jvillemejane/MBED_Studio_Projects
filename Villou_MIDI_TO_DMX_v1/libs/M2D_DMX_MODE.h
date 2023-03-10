/*H**********************************************************************
* FILENAME :        M2D_DMX_MODE.h          
*
* DESCRIPTION :
*       DMX Mode processing routines.
*
* NOTES :
*       These functions are a part of the MIDI2DMX application
*       Developped by Villou / LEnsE
**
* AUTHOR :    Julien VILLEMEJANE        START DATE :    22/sept/2022
*
*       LEnsE / Institut d'Optique Graduate School
*H***********************************************************************/

#include    "M2D_LENSE.h"

/************************************/
/* Global Parameters                */
/************************************/
extern      uint8_t     dmx_data[];

/****************************************************/
/* Functions                                        */  
/****************************************************/
/* DMX output initialization */
void initDMX(void);
/* Clear internal values for DMX output */
void clearDMX();
/* Updating DMX output with internal values */
void updateDMX();

/* update internal DMX data */
void    updateDMXdata(void);