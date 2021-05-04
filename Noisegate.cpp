#include <iostream>
#include <string>
#include "Noisegate.h"

const int16_t ZERO = (int16_t) 0;
const uint8_t ZERO1 = (uint8_t) 128;

Noisegate::Noisegate(int upperthreshold, int lowerthreshold):upperthreshold(upperthreshold), lowerthreshold(lowerthreshold){

}

void Noisegate::processBuffer(unsigned char* buffer, int bufferSize, wav wavfile)
{
    /** 
     * If it is 8 bits then run a for loop, setting buffer[i] to zero if it meets a threshold.
     * Same for 16 bit.
     */ 
    if(wavfile.getFMT().bit_depth == 8) 
    {
        for(int i=0;i<bufferSize;i++)
        {
            if(buffer[i] > (ZERO1 - 15) && buffer[i]<(ZERO1 + 15))
            {
                buffer[i] = ZERO1;
            }
        }
    }
    else if(wavfile.getFMT().bit_depth == 16){
        for(int i=0;i<bufferSize/2;i++)
        {
            short s = ((short*)buffer)[i];  
            if(s > (ZERO - 3000) && s < (ZERO + 3000))
            {
                ((short*)buffer)[i] = 0;
                
            }
        }

    }
}
