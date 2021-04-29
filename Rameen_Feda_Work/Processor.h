#ifndef PROCESSOR_H
#define PROCESSOR_H
#include "waveHeader_Seth.h"

#include <cstdint>
#include <cmath>

class Processor {
public:
/**
 * processBuffer with parameters unsigned char* buffer and int bufferSize
 */ 
    virtual void processBuffer(unsigned char* buffer, int bufferSize, FMT fmt) = 0;
};


#endif