#ifndef PROCESSOR_H
#define PROCESSOR_H
#include "waveHeader.h"
#include "wav.h"
#include <cstdint>
#include <cmath>

class Processor {
public:
/**
 * processBuffer with parameters unsigned char* buffer and int bufferSize
 */ 
    virtual void processBuffer(unsigned char* buffer, int bufferSize, wav wavfile) = 0;
};


#endif
