#ifndef ECHO_H
#define ECHO_H
#include "Processor.h"
#include "Wav.h"
using namespace std;

class Echo: public Processor
{
    public:
    int delay;
    Echo() = default;
    Echo(int delay); 
    void processBuffer(unsigned char* buffer, int bufferSize, FMT fmt) override;
    
};


#endif