/*H**********************************************************************
* FILENAME :        M2D_FILES.h            
*
* DESCRIPTION :
*       File access on SD card routines.
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

#ifndef     __M2D_FILES_H_INCLUDED
#define     __M2D_FILES_H_INCLUDED

#include    "M2D_LENSE.h"


/************************************/
/* SD CARD                          */
/************************************/
#include <SDBlockDevice.h>
#include <FATFileSystem.h>
extern      SDBlockDevice       sd_card;
extern      FATFileSystem       file_syst;

/* Mount SD Card */
void    mountSDcard(void);
/* Unmount SD Card */
void    unmountSDcard(void);
/* Update setup of the address list of spots - *.adr file */
void    openNewAddress(char* fileName);

/* update the setup of the controls list - *.ctr file */
void    openNewConfig(char* fileName);

#endif