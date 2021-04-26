#include <iostream>
#include "Noisegate.h"
#include "Wav.h"
#include <fstream>

const std::string testfile = "testing.wav";

using namespace std;

int main(){
    /**
     * Reads the testfile, creates a new processor object
     * Calls Noisegate(), gets buffer and buffersize and writes to "noise.wav"
     */ 
    Wav wav;
    wav.readFile(testfile);
    Processor *processor2 = new Noisegate();
    processor2->processBuffer(wav.getBuffer(),wav.getBufferSize());
    wav.writeFile("noise.wav");

    /**
     * Lets user pick which processes to use
     * Goes in order from 1 to 3.
     * WORK IN PROGRESS
    */ 
    
    
    
}