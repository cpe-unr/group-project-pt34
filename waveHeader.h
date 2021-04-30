//Author: Seth Lopez
//Date Due:
//Purpose: Group Final Project

#ifndef WAVEHEADER_H
#define WAVEHEADER_H

/**
* struct used to get the first 3 common attributes on all audio files
*
* char riff_header[]
* int wav_size
* char wave_header[]
*/
struct wav_header 
{
	char riff_header[4];
	int wav_size; 
	char wave_header[4];
};
/**
* struct use to gather common chunk info to read all other data
*
* char fmt_header[]
* int fmt_chunk_size
*/
struct chunkInfo
{
	char fmt_header[4];	
	int fmt_chunk_size;
};

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

/**
* struct for METADATA data
*
* char info[]
* char metadata_sub_1[]
* int num_characters
* char actual_data
* char metadata_sub_2
* int num_characters_2
* char actual_data_2
* char metadata_sub_n
* int num_characters_n
* char actual_data_n
*/

struct SubChunkInfo:public chunkInfo
{
	char *buffer;
};


#endif




















