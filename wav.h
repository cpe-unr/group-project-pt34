//Author: Seth Lopez
//Date Due:
//Purpose: Group Final Project

#ifndef WAV_H
#define WAV_H

#include "waveHeader.h"
#include <string>
#include <cstring>
#include <vector>

using namespace std;
/*
* class wav main interface class that deals with all audio file types
* 
*/
class wav {

private:
	vector <SubChunkInfo> metadata;
	unsigned char* buffer = NULL;
	int data_bufferSize;
	
public:
	
	wav_header waveHeader;
	chunkInfo chunkinfo;
	FMT fmt;

	/*
	* wav_header getwavHeader() used to get class with values from the wav_header class
	* @return
	*/
	wav_header getwavHeader();

	/*
	* unsigned char *getBuffer() used to get buffer data
	* @return
	*/
	unsigned char *getBuffer(); //NEED TO KNOW BUFFER, BUFFER SIZE, AND METADATA, NEED ALSO STERIO CHANNELS and bits (bit_depth)

	/*
	* virtual int getBufferSize()
	* @return
	*/
	int getBufferSize();

	/*
	* vitual void readFile()
	* @param fileName - take file's name to read in values and pass them to the wav_header class
	*/
	void readFile(const std::string &fileName);

	/*
	* virtual void writeFile()
	* @param outfileName - take edited file's name to create new .wav file
	*/
	void writeFile(const std::string &outFileName);

	/*
	* virtual -wav() used to delete allocated memory of buffer[]
	* 
	*/
	//virtual ~wav();
};


#endif
