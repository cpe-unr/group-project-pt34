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
    int user_input;
    string file_name;
    cout << "Please choose one or more processes: " << endl;
    cout << "1. Normalization 2. Echo 3. Noisegate ";
    cin >> user_input;
    if(user_input = 3)
    {
        
        wav.readFile(testfile);
        Processor *processor2 = new Noisegate();
        processor2->processBuffer(wav.getBuffer(),wav.getBufferSize());
        wav.writeFile("noise.wav");
    
    }
    /**
     * Asks user for file name. If file does not exist, create it
     * If file already exists, give an error.
     * NOT WORKING 
    */ 
    ifstream file_input(file_name);
    do{
        cout << "Please enter a file name" << endl;
        cin >> file_name;
        if(file_input.fail())
        {
            wav.writeFile(file_name);
        }
        else if(!file_input.fail())
        {
            cout << "Error: File already exists. Please enter a new name";
        }
    }while(!file_input.fail());
    
}