#include <iostream>
#include "Normalization.h"
#include <limits>

/**
*If the audio is 8 bit proceed to read through the buffer and find the largest number and set it equal to right max and left max. If the number of channels is 1, multiply the buffer[i] with the left max divided by 128. If the number of channels is 2, do the same for the right max.
* When the audio is 16 bit, the same process is used with the exception of typecasting the buffer to a short and dividing the left and right max by 32768.
*/
template<class T> int numeric_limit;
void Normalization::processBuffer(unsigned char* buffer, int bufferSize, wav wavfile){
    if(wavfile.getFMT().bit_depth == 8){
       
        unsigned char leftmax=0, rightmax=0;
        for(int i=0;i<bufferSize;i+=2){
            
            if(buffer[i] > std::numeric_limits<int>::max()){
                leftmax = buffer[i];
            }
        }
        for(int i=1;i<bufferSize;i+=2){
            
            if(buffer[i] > std::numeric_limits<int>::max()){
                rightmax = buffer[i];
            }
        }
        if(wavfile.getFMT().num_channels == 1){
            for(int i=0;i<bufferSize;i+=2){
                buffer[i] = buffer[i] * (leftmax/128);
            }
        }
        if(wavfile.getFMT().num_channels == 2){
            for(int i=1;i<bufferSize/2;i+=2){
                buffer[i] = buffer[i] * (rightmax/128);
            }
        }    
    }
    if(wavfile.getFMT().bit_depth == 16){
    short leftmax=0, rightmax=0;
        for(int i=0;i<bufferSize/2;i+=2){
            
            if(buffer[i] > std::numeric_limits<int>::max()){
                leftmax = buffer[i];
            }
        }
        for(int i=1;i<bufferSize/2;i+=2){
            
            if(buffer[i] > std::numeric_limits<int>::max()){
                rightmax = buffer[i];
            }
        }
        if(wavfile.getFMT().num_channels == 1){
            for(int i=0;i<bufferSize/2;i+=2){
                ((short*)buffer)[i] = ((short*)buffer)[i] * (leftmax/32768);
            }
        }
        if(wavfile.getFMT().num_channels == 2){
            for(int i=1;i<bufferSize/2;i+=2){
                ((short*)buffer)[i] = ((short*)buffer)[i] * (rightmax/32768);
            }
        }    
    }

}
