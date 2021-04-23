//Author: Seth Lopez
//Date Due:
//Purpose: Group Final Project

#ifndef WAVMANAGER_H
#define WAVMANAGER_H

#include "wav.h"
//#include "FMT_class.h"

using namespace std;

class wavManager:public wav
{
protected:
	
public:
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

	~wavManager();
};

#endif
