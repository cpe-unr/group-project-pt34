#include <iostream>
#include <string>
#include "Wav.h"
#include "Processor.h"
#include "Echo.h"
#include "Noisegate.h"
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
    Wav wav;
    wav.readFile(testfile);
    Processor *processor = new Noisegate();
    cout << "TEST" << endl;
    processor->processBuffer(wav.getBuffer(),wav.getBufferSize(), wav.getFMT());
    cout << "TEST 2" << endl;
    wav.writeFile("noise.wav");

    Wav wav1;
    wav1.readFile(testfile);
    Processor *processor1 = new Echo(5);
    processor1->processBuffer(wav.getBuffer(),wav.getBufferSize(), wav.getFMT());
    wav.writeFile("echos.wav");

    
    
    
}