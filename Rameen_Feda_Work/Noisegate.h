#ifndef NOISEGATE_H
#define NOISEGATE_H
#include "Processor.h"
#include "Wav.h"

class Noisegate: public Processor
{
    public:
    int upperthreshold, lowerthreshold;
    /**
     *Default constructor
     */ 
    Noisegate() = default;
    /**
     * Parameterized constructor
     */
    Noisegate(int upperthreshold, int lowerthreshold);
    /**
     * Override of the buffer
     */
    void processBuffer(unsigned char* buffer, int bufferSize, FMT fmt) override;
    
};


#endif