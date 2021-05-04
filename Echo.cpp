#include <iostream>
#include "Echo.h"
/**
*If the remainder of the delay is not a multiple of 2, then add 1. Makes it so that it can work with stereo format audio.
*/
Echo::Echo(int delay): delay(delay) {
    if((delay % 2) != 0){
        delay = delay + 1;
    }
}

/**
*If the audio is 8 bit, enter the first for loop and process it. If it is 16 bit, enter the second for loop, typecast the buffer and proceed to process it.
*/
void Echo::processBuffer(unsigned char* buffer, int bufferSize, wav wavfile){
    if(wavfile.getFMT().bit_depth == 8){
    for(int i=delay;i<bufferSize;i++){
        buffer[i] = buffer[i] + buffer[i-delay]; 
        }
    }
    else if (wavfile.getFMT().bit_depth == 16){
    for(int i=delay;i<bufferSize/2;i++){
        ((short*)buffer)[i] = ((short*)buffer)[i] + ((short*)buffer)[i-delay];
        }
    }
}
