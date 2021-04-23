//Author: Seth Lopez
//Date Due:
//Purpose: Group Final Project

#ifndef WAV_H
#define WAV_H

#include "waveHeader.h"
#include <string>

using namespace std;
/*
* class wav main interface class that deals with all audio file types
* 
*/
class wav {

protected:
	unsigned char* buffer = NULL;
	wav_header waveHeader;
	chunkInfo chunkinfo;
	FMT fmt;
	
public:
	/*
	* wav_header getwavHeader() used to get class with values from the wav_header class
	* @return
	*/
	wav_header getwavHeader();

	/*
	* unsigned char *getBuffer() used to get buffer data
	* @return
	*/
	unsigned char *getBuffer();

	/*
	* virtual int getBufferSize()
	* @return
	*/
	virtual int getBufferSize()=0;

	/*
	* vitual void readFile()
	* @param fileName - take file's name to read in values and pass them to the wav_header class
	*/
	virtual void readFile(const std::string &fileName)=0;

	/*
	* virtual void writeFile()
	* @param outfileName - take edited file's name to create new .wav file
	*/
	virtual void writeFile(const std::string &outFileName)=0;

	/*
	* virtual -wav() used to delete allocated memory of buffer[]
	* 
	*/
	~wav();
};


#endif
