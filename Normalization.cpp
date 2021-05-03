#include <iostream>
#include "Normalization.h"
#include <limits>

template<class T> int numeric_limit;
void Normalization::processBuffer(unsigned char* buffer, int bufferSize, FMT fmt){
    if(fmt.bit_depth == 8){
       
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
        if(fmt.num_channels == 1){
            std::cout << "In the first (8bit) channel" << std::endl;
            for(int i=0;i<bufferSize;i+=2){
                buffer[i] = buffer[i] * (leftmax/128);
            }
        }
        if(fmt.num_channels == 2){
            std::cout << "In the second (8bit) channel" << std::endl;
            for(int i=1;i<bufferSize/2;i+=2){
                buffer[i] = buffer[i] * (rightmax/128);
            }
        }    
    }
    if(fmt.bit_depth == 16){
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
        if(fmt.num_channels == 1){
            std::cout << "In the first (16bit) channel" << std::endl;
            for(int i=0;i<bufferSize/2;i+=2){
                ((short*)buffer)[i] = ((short*)buffer)[i] * (leftmax/32768);
            }
        }
        if(fmt.num_channels == 2){
            std::cout << "In the second (16bit) channel" << std::endl;
            for(int i=1;i<bufferSize/2;i+=2){
                ((short*)buffer)[i] = ((short*)buffer)[i] * (rightmax/32768);
            }
        }    
    }

}