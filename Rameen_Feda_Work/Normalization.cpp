#include <iostream>
#include "Normalization.h"

void Normalization::processBuffer(unsigned char* buffer, int bufferSize, FMT fmt){
    int max=0;
    for(int i=0;i<bufferSize;i++){
        if(buffer[i] = max){
            max = buffer[i];
        }
    }
    int ratio = 32768/max;
    if(fmt.num_channels == 1){
        for(int i=0;i<bufferSize;i+=2){
            buffer[i] = buffer[i] * ratio;
        }
    }
    if(fmt.num_channels == 2){
        for(int i=1;i<bufferSize;i+=2){
            short s = ((short*)buffer)[i];
            s = s * ratio;
        }
    }

    //ask about how the channel plays a role in this
    
}