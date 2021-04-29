//
// Created by Keith Lancaster on 3/13/21.
//

#ifndef PROGRAMMING_ASSIGNMENT_3KL_WAV_H
#define PROGRAMMING_ASSIGNMENT_3KL_WAV_H

/*
 * This class is designed to work with PCM 8-bit mono wavefiles.
 * It makes many assumptions about the format of the wave as a result.
 * It will NOT work with stereo files or any other bit-depth than 8 bits.
 */
#include "Waveheader.h"
#include "waveHeader_Seth.h"
#include <string>

class Wav {
public:
/** 
 * Reads and writes files
*/ 
    void readFile(const std::string &fileName);
    void writeFile(const std::string &outFileName);
private:
    
    unsigned char* buffer = NULL;
    /**
     * Composition of wav_header class
     */ 
    wav_header waveHeader;
public:
/** Destructor
 */ 
    virtual ~Wav();

public:
    Wav()= default;
    unsigned char *getBuffer();
    int getBufferSize() const;
    FMT getFMT();
};


#endif //PROGRAMMING_ASSIGNMENT_3KL_WAV_H
