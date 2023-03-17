/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"
#include "MP3_DFMiniPlayer.h"

#define WAIT_TIME_MS 500 
DigitalOut led1(LED1);

UnbufferedSerial	my_pc(USBTX, USBRX);
char		chStr[128];

UnbufferedSerial	my_serial(A4, A5);
MP3_DFMiniPlayer	my_player(&my_serial);


int main()
{
	my_pc.baud(115200);
	
	sprintf(chStr, "Mbed OS %d.%d.%d.\n", MBED_MAJOR_VERSION, MBED_MINOR_VERSION, MBED_PATCH_VERSION);
	my_pc.write(chStr, strlen(chStr));
	
	// Wait until MP3 Player is ready
	my_player.waitAvailable();	// ATTENTION NON BLOQUANT POUR L'INSTANT !!

	sprintf(chStr, "Player OK.\n");
	my_pc.write(chStr, strlen(chStr));

    while (true)
    {
        led1 = !led1;
        thread_sleep_for(WAIT_TIME_MS);
    }
}
