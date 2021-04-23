//Author: Seth Lopez
//Date Due:
//Purpose: Group Final Project

//#include "FMT_class.h"

#include <fstream>
#include <iostream>
#include <string>

#include "wavManager.h"

int wavManager::getBufferSize()
{
	return sizeof(buffer);
}

void wavManager::readFile(const std::string &fileName) 
{
	std::ifstream file(fileName, std::ios::binary | std::ios::in); 
   
	if(file.is_open())
	{
		file.read((char*)&waveHeader, sizeof(wav_header));
		file.read((char*)&chunkinfo, sizeof(chunkInfo));
		file.close();
	}

	string header_word;
	int chunkSize = chunkinfo.fmt_chunk_size;

	for(int i = 0; i < 4; i++)
	{
		header_word += chunkinfo.fmt_header[i];
	}

	if(header_word == "FMT ")
	{
		file.read((char*)&fmt, sizeof(FMT));
		buffer = new unsigned char[fmt.byte_rate];// Number of bytes in data. Number of samples * num_channels * sample byte size
		file.read((char*)buffer, fmt.byte_rate);
	}

}

void wavManager::writeFile(const std::string &outFileName)
{
	std::ofstream outFile(outFileName, std::ios::out | std::ios::binary);
	outFile.write((char*)&waveHeader,sizeof(wav_header));
	outFile.write((char*)&chunkinfo,sizeof(chunkInfo));
	outFile.close();
}




/*
struct chunkInfo
{
	char fmt_header[4];	
	int fmt_chunk_size;
};


struct FMT 

struct METADATA 

struct DATA 

struct MYSTERY
*/
