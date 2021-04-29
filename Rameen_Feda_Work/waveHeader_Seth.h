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
struct wav__header 
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
struct METADATA 
{   
	char info[4];

	char metadata_sub_1[4];
	int num_characters;
	char actual_data;

	char metadata_sub_2;
	int num_characters_2;
	char actual_data_2;

	char metadata_sub_n;
	int num_characters_n;
	char actual_data_n;
};
/**
* struct for DATA skippable data (must read size to skip)
*
* char data[]
* int size
*/
struct DATA 
{   
	char data[4];
	int size;
	//MISSING- depends on bitdepth and whether the file is mono/stereo
};
/**
* struct MYSTERY skippable data (must read size to skip)
*
* char data[]
* int size
*/
struct MYSTERY
{   
	char data[4];
	int size; // skip over this
	//MISSING- depends on bitdepth and whether the file is mono/stereo
};


/*
	short audio_format;
	short num_channels;	// make getter //
	int sample_rate; 	// make getter //
	int byte_rate;
	short sample_alignment;
	short bit_depth;	// make getter //
	char data_header[4];
	int data_bytes;
	// char bytes[];
*/


#endif




















