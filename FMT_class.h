//Author: Seth Lopez
//Date Due:
//Purpose: Group Final Project

#ifndef FMT_CLASS_H
#define FMT_CLASS_H


#include "wavManager.h"
/**
* struct for the FMT data
*
* short audio_format
* short num_channels
* int sample_rate
* int byte_rate
* short sample_alignment
* short bit_depth
*/
struct FMT 
{   
	short audio_format;
	short num_channels;
	int sample_rate;
	int byte_rate;
	short sample_alignment;
	short bit_depth;
};

class FMT_class: public wavManager
{
private:
	FMT fmt; //getters
	int chunkSize;
public:
	FMT_class(int);

	/*
	* int getBufferSize() const used data_bytes variable from wav_header class ***WARNGING NO LONGER WORKS***
	* @return
	*/
	int getBufferSize() override;

	/*
	* void readFile()
	* @param fileName - take file's name to read in values and pass them to the wav_header class
	*/
	void readFile(const std::string &fileName) override;

	/*
	* void writeFile()
	* @param outfileName - take edited file's name to create new .wav file
	*/
	void writeFile(const std::string &outFileName) override;
};

#endif
