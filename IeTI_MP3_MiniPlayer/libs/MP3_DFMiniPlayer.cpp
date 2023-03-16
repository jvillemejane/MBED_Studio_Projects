/**
 * FILENAME :        MP3_DFMiniPlayer.cpp          
 *
 * DESCRIPTION :
 *       MP3 DF Mini Player module library.
 *
 * NOTES :
 *       Developped by Villou / LEnsE
 **
 * AUTHOR :    Julien VILLEMEJANE        START DATE :    16/mar/2023
 *
 *       LEnsE / Institut d'Optique Graduate School
 * @see https://github.com/DFRobot/DFRobotDFPlayerMini/blob/master/doc/FN-M16P%2BEmbedded%2BMP3%2BAudio%2BModule%2BDatasheet.pdf
 */

#include "MP3_DFMiniPlayer.h"
#include <cstdint>

MP3_DFMiniPlayer::MP3_DFMiniPlayer(UnbufferedSerial *link){
    this->_receivedIndex = 0;
    this->_dataIsReady = false;
    this->_dataCnt = 0;
    this->_playerReady = false;

    /* Initialisation of enable output */
    if (link){ delete this->_serial; }
    this->_serial = link;
    this->_serial->baud(9600);      // 9600 bauds default value
    this->_serial->attach(callback(this, &MP3_DFMiniPlayer::ISR_MP3_data), UnbufferedSerial::RxIrq);

}

void MP3_DFMiniPlayer::ISR_MP3_data(void){
    uint8_t data = 0;
    this->_serial->read(&data, 1);

    if(data == START_BYTE){ this->_receivedIndex = 0;   }
    else{   this->_receivedIndex++; }
    this->_receivedBuffer[this->_receivedIndex] = data;
    if((data == END_BYTE) && (this->_receivedIndex == 10)){
        this->_dataIsReady = true;
        this->_dataCnt++;
    }
}

uint16_t    MP3_DFMiniPlayer::calculateCheckSum(uint8_t *buffer){
    uint16_t sum = 0;
    for (int i = START_CHKSUM; i <=  END_CHKSUM; i++) {
        sum += buffer[i];
    }
    return -sum;
}


bool        MP3_DFMiniPlayer::checkCheckSum(uint8_t *buffer){
    uint16_t chS = calculateCheckSum(buffer);
    uint16_t chSR = (buffer[7] << 8) + buffer[8];
    return (chS == chSR);
}


/*
* @return  1 if USB, 2 if SD Card, 3 if both, 4 if computer
*/
uint8_t    MP3_DFMiniPlayer::waitAvailable(void){
    if((this->_dataIsReady) && (this->_dataCnt == 1)){
        if(checkCheckSum(this->_receivedBuffer)){
            if(this->_receivedBuffer[3] == QUERY_ONLINE){
                this->_playerReady = true;
                return this->_receivedBuffer[6];
            }
            else{
                return -1;
            }
        }
        return -2;
    }
    return -3;
}