#include <iostream>
#include "Normalization.h"

void Normalization::processBuffer(unsigned char* buffer, int bufferSize, wav wavfile){
    std::cout << "1" << std::endl;
    if(wavfile.getFMT().bit_depth == 8){
        std::cout << "1" << std::endl;
        unsigned char leftmax=0, rightmax=0;
        for(int i=0;i<bufferSize;i+=2){
            
            if(buffer[i] > leftmax){
                leftmax = buffer[i];
            }
        }
        for(int i=1;i<bufferSize;i+=2){
            
            if(buffer[i] > rightmax){
                rightmax = buffer[i];
            }
        }
        std::cout << "2" << std::endl;
        if(wavfile.getFMT().num_channels == 1){
            std::cout << "In the first (8bit) channel" << std::endl;
            for(int i=0;i<bufferSize;i+=2){
                buffer[i] = buffer[i] * (leftmax/128);
            }
        }
        if(wavfile.getFMT().num_channels == 2){
            std::cout << "In the second (8bit) channel" << std::endl;
            for(int i=1;i<bufferSize/2;i+=2){
                buffer[i] = buffer[i] * (rightmax/128);
            }
        }    
    }
    if(wavfile.getFMT().bit_depth == 16){
        std::cout << "3" << std::endl;
    short leftmax=0, rightmax=0;
        for(int i=0;i<bufferSize/2;i+=2){
            
            if(buffer[i] > leftmax){
                leftmax = buffer[i];
            }
        }
        for(int i=1;i<bufferSize/2;i+=2){
            
            if(buffer[i] > rightmax){
                rightmax = buffer[i];
            }
        }
        std::cout << "4" << std::endl;
        if(wavfile.getFMT().num_channels == 1){
            std::cout << "In the first (16bit) channel" << std::endl;
            for(int i=0;i<bufferSize/2;i+=2){
                ((short*)buffer)[i] = ((short*)buffer)[i] * (leftmax/32768);
            }
        }
        if(wavfile.getFMT().num_channels == 2){
            std::cout << "In the second (16bit) channel" << std::endl;
            for(int i=1;i<bufferSize/2;i+=2){
                ((short*)buffer)[i] = ((short*)buffer)[i] * (rightmax/32768);
            }
        }    
    }

}
