#include <iostream>
#include "Echo.h"

 Echo::Echo(int delay): delay(delay) {
       
}

void Echo::processBuffer(unsigned char* buffer, int bufferSize, FMT fmt){
      
    if(fmt.bit_depth == 8){
    for(int i=0;i<bufferSize;i++){
        buffer[i] = buffer[i] + buffer[i-delay]; 
        }
    }
    else if (fmt.bit_depth == 16){
    std::cout << "In the 16 bit" << std::endl;
    for(int i=0;i<bufferSize;i++){
        short s = ((short*)buffer)[i];
        s = s + s-delay; 
        }
    }
}