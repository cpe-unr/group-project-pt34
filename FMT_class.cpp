//Author: Seth Lopez
//Date Due:
//Purpose: Group Final Project

#include <string>
#include <fstream>
#include <iostream>
#include "FMT_class.h"

FMT_class::FMT_class(int chunkSize): chunkSize(chunkSize){}

int FMT_class::getBufferSize()
{
	return fmt.byte_rate;
}

void FMT_class::readFile(const std::string &fileName) 
{
	std::ifstream file(fileName, std::ios::binary | std::ios::in); 
   
	if(file.is_open())
	{
		file.read((char*)&waveHeader, sizeof(wav_header));
		file.read((char*)&chunkinfo, sizeof(chunkInfo));
		file.read((char*)&fmt, sizeof(FMT));
		buffer = new unsigned char[fmt.byte_rate];// Number of bytes in data. Number of samples * num_channels * sample byte size
		file.read((char*)buffer, fmt.byte_rate);
		file.close();
	}
}

void FMT_class::writeFile(const std::string &outFileName)
{
	std::ofstream outFile(outFileName, std::ios::out | std::ios::binary);
	outFile.write((char*)&waveHeader,sizeof(wav_header));
	outFile.write((char*)&chunkinfo,sizeof(chunkInfo));
	outFile.write((char*)&fmt,sizeof(FMT));
	outFile.write((char*)buffer, fmt.byte_rate);
	outFile.close();
}






/*

    char data_header[4]; // Contains "data"
    int data_bytes; // Number of bytes in data. Number of samples * num_channels * sample byte size


struct FMT 

struct METADATA 

struct DATA 

struct MYSTERY
*/
