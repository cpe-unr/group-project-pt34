#include <iostream>
#include <string>
#include "Noisegate.h"

const int16_t ZERO = (int16_t) 0;
const uint8_t ZERO1 = (uint8_t) 128;

Noisegate::Noisegate(int upperthreshold, int lowerthreshold):upperthreshold(upperthreshold), lowerthreshold(lowerthreshold){

}

void Noisegate::processBuffer(unsigned char* buffer, int bufferSize, FMT fmt)
{
    /** 
     * If it is 8 bits then run a for loop, setting buffer[i] to zero if it meets a threshold.
     * Same for 16 bit.
     */ 
    if(fmt.bit_depth == 8) 
    {
        std::cout << "In the 8 bit" << std::endl;
        for(int i=0;i<bufferSize;i++)
        {
            if(buffer[i] > (ZERO1 - 3) && buffer[i]<(ZERO1 + 3))
            {
                buffer[i] = ZERO1;
            }
        }
    }
    else if(fmt.bit_depth == 16){
        std::cout << "In the 16 bit" << std::endl;
        for(int i=0;i<bufferSize;i++)
        {
            short s = ((short*)buffer)[i];  
            if(s > (ZERO - 300) && s < (ZERO + 300))
            {
                s = ZERO;
                
            }
        }

    }
}