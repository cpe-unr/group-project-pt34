#ifndef CSV_H
#define CSV_H
#include "Processor.h"
#include "waveheader.h"
#include "wav.h"
using namespace std;


class CSV: public Processor
{
    public:
    CSV() = default;
    void processBuffer(unsigned char* buffer, int bufferSize, wav wavfile) override;
    ~CSV(){}
};


#endif