#include <iostream>
#include <string>
#include "Noisegate.h"

const uint16_t ZERO = (uint16_t) 32768;
const uint8_t ZERO1 = (uint8_t) 128;

Noisegate::Noisegate(int upperthreshold, int lowerthreshold):upperthreshold(upperthreshold), lowerthreshold(lowerthreshold){

}

void Noisegate::processBuffer(unsigned char* buffer, int bufferSize)// BUFFER IS FULL OF JUNK. NEED APPROPIATE VALUES FOR THIS TO WORK.
{
    //buffer = {};
    Wav wav(8, 16);
    std::cout << wav.getbit_depth() << std::endl;
    /** 
     * If it is 8 bits then run a for loop, setting buffer[i] to zero if it meets a threshold.
     * Same for 16 bit.
     */ 
    if(wav.getbit_depth() == 8) // Always goes to 8 bit for some reason, even if it is 16 bit audio
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
    else if(wav.getbit_depth() == 16){
        std::cout << "In the 16 bit" << std::endl;
        for(int i=0;i<bufferSize;i++)
        {
            short s = ((short*)buffer)[i];  //NOT WORKING. Due to buffer being full of junk values(?).
            if(s > (ZERO - 300) && s < (ZERO + 300)) //help
            {
                s = ZERO;
                
            }
        }

    }
}