#include <iostream>
#include <fstream>
#include "CSV.h"


void CSV::processBuffer(unsigned char* buffer, int bufferSize, wav wavfile){
    std::ofstream myfile;
    myfile.open("data.csv");
    myfile << wavfile.getFMT().audio_format << endl;
    myfile << wavfile.getFMT().bit_depth << endl;
    myfile << wavfile.getFMT().byte_rate << endl;
    myfile << wavfile.getFMT().num_channels << endl;
    myfile << wavfile.getFMT().sample_rate << endl;
    myfile.close();
    
}
