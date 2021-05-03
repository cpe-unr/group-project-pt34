#ifndef NORMALIZATION_H
#define NORMALIZATION_H
#include "Processor.h"
#include "Wav.h"

template<class T> int numeric_limit;
class Normalization: public Processor
{
    public:
    /**
     *Default constructor
     */ 
    Normalization() = default;
    /**
     * Override of the buffer
     */
    void processBuffer(unsigned char* buffer, int bufferSize, FMT fmt) override;
    
};

#endif