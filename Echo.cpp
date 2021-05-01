#include <iostream>
#include "Echo.h"

Echo::Echo(int delay): delay(delay) {
    if((delay % 2) != 0){
        delay = delay + 1;
    }
}

void Echo::processBuffer(unsigned char* buffer, int bufferSize, wav wavfile){
    if(wavfile.fmt.bit_depth == 8){
    for(int i=delay;i<bufferSize;i++){
        buffer[i] = buffer[i] + buffer[i-delay]; 
        }
    }
    else if (wavfile.fmt.bit_depth == 16){
    std::cout << "In the 16 bit" << std::endl;
    for(int i=delay;i<bufferSize/2;i++){
        ((short*)buffer)[i] = ((short*)buffer)[i] + ((short*)buffer)[i-delay];
        }
    }
}
