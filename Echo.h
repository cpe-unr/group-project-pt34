#ifndef ECHO_H
#define ECHO_H
#include "Processor.h"
#include "wav.h"
using namespace std;

class Echo: public Processor
{

public:
    /**
    *Paramterized constructor with int delay. Buffer override will get data from the file and process it with an echo
    */
    int delay;
    Echo(int delay); 
    void processBuffer(unsigned char* buffer, int bufferSize, wav wavfile) override;
    
};


#endif
