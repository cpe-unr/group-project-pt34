#ifndef NORMALIZATION_H
#define NORMALIZATION_H
#include "Processor.h"
#include "wav.h"

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
    void processBuffer(unsigned char* buffer, int bufferSize, wav wavfile) override;
    
};

#endif
