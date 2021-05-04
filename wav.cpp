//Author: Seth Lopez
//Date Due: 5/4/21
//Purpose: Group Final Project

#include <string>
#include <fstream>
#include <iostream>
#include "wav.h"


wav_header wav::getwavHeader()
{
	return waveHeader;
}
chunkInfo wav::getchunkInfo()
{
	return chunkinfo;
}
FMT wav::getFMT()
{
	return fmt;
}
vector<SubChunkInfo> wav::getMetaData()
{
	return metadata;
}
unsigned char *wav::getBuffer()
{
	return buffer;
}

int wav::getBufferSize()
{
	return data_bufferSize;
}
void wav::readFile(const std::string &fileName) 
{
	std::ifstream file(fileName, std::ios::binary | std::ios::in); 
   
	if(file.is_open())
	{
		file.read((char*)&waveHeader, sizeof(wav_header));
		while(file)
		{
			file.read((char*)&chunkinfo, sizeof(chunkInfo));

			string header_word = chunkinfo.fmt_header;
			int chunkSize = chunkinfo.fmt_chunk_size;

			if(header_word == "FMT ") 
			{
				file.read((char*)&fmt, sizeof(FMT));
			}
			else if(header_word == "LIST")
			{
				int count = 0;
				char trash[4]; 
				file.read(trash, 4);
				while(count < chunkSize)
				{
					SubChunkInfo subchunk;
					file.read((char*)&subchunk, sizeof(chunkInfo));
					subchunk.buffer = new char [subchunk.fmt_chunk_size];
					file.read(subchunk.buffer, subchunk.fmt_chunk_size);
					metadata.push_back(subchunk);
					count += (sizeof(chunkInfo) + subchunk.fmt_chunk_size);
				}
			}
			else if(header_word == "DATA")
			{
				data_bufferSize = chunkSize;
				buffer = new unsigned char [chunkSize];
				file.read((char*)&buffer, chunkSize);
			}
			else
			{
				file.seekg(chunkSize, ios::cur);
			}
		}
	}
file.close();
}

void wav::writeFile(const std::string &outFileName)
{
	int totalSize = waveHeader.wav_size;
	int total;
	std::ofstream outFile(outFileName, std::ios::out | std::ios::binary);
	outFile.write((char*)&waveHeader,sizeof(wav_header));
	
	//FMT
	outFile.write("fmt ", 4);
	int size = sizeof(FMT);
	outFile.write((char*)&size, sizeof(size));
	cout<<fmt.audio_format<<"||"<<fmt.num_channels<<"||"<<fmt.sample_rate<<"||"<<fmt.byte_rate<<"||"<<fmt.sample_alignment<<"||"<<fmt.bit_depth<<"||"<<" ::: This is inside FMT"<<endl;
	outFile.write((char*)&fmt,sizeof(FMT));
	//*****************************************
	//MEDATADA
	int count = 0;
	for(SubChunkInfo s: metadata)
	{
		if(count ==0)
		{
			outFile.write("LIST", 4);
			size = 4;
			count ++;
		}
		size += (sizeof(chunkInfo) + s.fmt_chunk_size);
	}
	total = size;
	outFile.write((char*)&size, sizeof(size));
	outFile.write("INFO", 4);
	for(SubChunkInfo s: metadata)
	{
		outFile.write((char*)&s, sizeof(chunkInfo));
		outFile.write((char*)&s.buffer, sizeof(s.fmt_chunk_size));
	}
	//*****************************************
	//DATA
	outFile.write("DATA", 4);
	outFile.write((char*)&data_bufferSize, sizeof(data_bufferSize));
	outFile.write((char*)&buffer, data_bufferSize);
	total += sizeof(wav_header) + sizeof(FMT) + sizeof(data_bufferSize);
	totalSize -= total;
	outFile.write((char*)&totalSize, sizeof(totalSize));
	outFile.close();
}

wav::~wav()
{
	if(buffer != NULL)
	{
		delete[] buffer;
	}
}





