#include <iostream>
#include "Normalization.h"

void Normalization::processBuffer(unsigned char* buffer, int bufferSize){
    int max=0;
    for(int i=0;i<bufferSize;i++){
        if(buffer[i] = max){
            max = buffer[i];
        }
    }
    int ratio = 32768/max;
    //ask about how the channel plays a role in this
    
}