#include <iostream>
#include <string>
#include "Noisegate.h"

const uint16_t ZERO = (uint16_t) 32768;
const uint8_t ZERO1 = (uint8_t) 128;

Noisegate::Noisegate(int upperthreshold, int lowerthreshold):upperthreshold(upperthreshold), lowerthreshold(lowerthreshold){

}

void Noisegate::processBuffer(unsigned char* buffer, int bufferSize)
{
    int buffer1;
    wav_header wav;
    /** 
     * If it is 8 bits then run a for loop, setting buffer[i] to zero if it meets a threshold.
     * Same for 16 bit.
     */ 
    if(wav.bit_depth = 8)
    {
        for(int i=0;i<bufferSize;i++)
        {
            if(buffer[i] > (ZERO1 - 3) && buffer[i]<(ZERO1 + 3))
            {
                buffer[i] = ZERO1;
            }
        }
    }
    else if(wav.bit_depth = 16){
        for(int i=0;i<bufferSize;i++)
        {
            uint16_t buffer1 = (uint16_t)(buffer[i]); 
            if(buffer1 > (ZERO - 3) && buffer1 < (ZERO + 3))
            {
                //(uint16_t) buffer[i] = ZERO;
                
            }
        }

    }
    
        
}