#ifndef NORMALIZATION_H
#define NORMALIZATION_H
#include "Processor.h"
#include "Wav.h"

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
    void processBuffer(unsigned char* buffer, int bufferSize) override;
    
};

#endif