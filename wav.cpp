//Author: Seth Lopez
//Date Due:
//Purpose: Group Final Project

#include <string>
#include <fstream>
#include <iostream>
#include "wav.h"

wav_header wav::getwavHeader()
{
	return waveHeader;
}

unsigned char *wav::getBuffer()
{
	return buffer;
}

wav::~wav()
{
	if(buffer != NULL)
	{
		delete[] buffer;
	}
}



