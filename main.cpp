#include <iostream>
#include <string>
#include "wav.h"
#include "Processor.h"
#include "Echo.h"
#include "Noisegate.h"
#include "Normalization.h"
#include <fstream>
const std::string testfile = "testing.wav";
const std::string echofile = "echos.wav";
const std::string limitfile = "limit.wav";
const std::string noisefile = "noise.wav";



using namespace std;

int main(){
    /**
     * Reads the testfile, creates a new processor object
     * Calls Noisegate(), gets buffer and buffersize and writes to "noise.wav"
     */ 
    wav wavfile;
    wavfile.readFile(testfile);
    Processor *processor = new Noisegate();
    processor->processBuffer(wavfile.getBuffer(),wavfile.getBufferSize(), wavfile);
    wavfile.writeFile("noise.wav");


    wav wavfile1;
    wavfile1.readFile(testfile);
    Processor *processor1 = new Echo(5000);
    processor1->processBuffer(wavfile1.getBuffer(),wavfile1.getBufferSize(), wavfile1);
    wavfile1.writeFile("echos.wav");

    
    wav wavfile2;
    wavfile2.readFile(testfile);
    Processor *processor2 = new Normalization();
    processor2->processBuffer(wavfile2.getBuffer(),wavfile2.getBufferSize(), wavfile2);
    wavfile2.writeFile("normalization.wav");


    
    
    
}
