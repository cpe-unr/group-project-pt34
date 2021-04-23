//Author: Seth Lopez
//Date Due:
//Purpose: Group Final Project

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

#include "wav.h"
#include "wavManager.h"

using namespace std;

const string testfile = "testing.wav";



int main() {
	wavManager *wavVar = new wavManager();
	wavVar->readFile(testfile);

	
	ifstream myfile;
	myfile.open(testfile);

	if (myfile)
	{
		
		//cout << "RIFF header                :" << wavVar.getwavHeader().riff_header << endl;
		/*cout << "Number of bits used        :" << wavVar.waveHeader.wav_size << endl;
		cout << "WAVE header                :" << wavVar.waveHeader.wave_header << endl;
        	cout << "FMT                        :" << wavVar.waveHeader.fmt_header << endl;
        	cout << "Data size                  :" << wavVar.waveHeader.fmt_chunk_size << endl;
        	cout << "Audio Format               :" << wavVar.waveHeader.audio_format << endl;
        	cout << "Number of channels         :" << wavVar.waveHeader.num_channels << endl;
        	cout << "Sampling Rate              :" << wavVar.waveHeader.sample_rate << endl;
        	cout << "Number of bytes per second :" << wavVar.waveHeader.byte_rate << endl;
        	cout << "Block align                :" << wavVar.waveHeader.sample_alignment << endl;
		//BIT_DEPTH MISSING        	
		cout << "Data string                :" << wavVar.waveHeader.data_header << endl;
		cout << "Data length                :" << wavVar.waveHeader.data_bytes << endl;*/
    	}
	else
	{
		cout<<"Something went wrong!"<<endl;
	}
}










































/**
 * \brief   The function bar.
 *
 * \details This function does something which is doing nothing. So this text
 *          is totally senseless and you really do not need to read this,
 *          because this text is basically saying nothing.
 *
 * \note    This text shall only show you, how such a \"note\" section
 *          is looking. There is nothing which really needs your notice,
 *          so you do not really need to read this section.
 *
 * \param[in]     a    Description of parameter a.
 * \param[out]    b    Description of the parameter b.
 * \param[in,out] c    Description of the parameter c.
 *
 * \return        The error return code of the function.
 *
 * \retval        ERR_SUCCESS    The function is successfully executed
 * \retval        ERR_FAILURE    An error occurred
 */

//void fn(){}
