Group Members:
Seth Lopez
Jose Torres
Rameen Feda

Responsibilities: 
1)Seth Lopez
Given:
-A directory of audio files in wav format
What to do:
-Read in each file one at a time
-Extract all the technical information (sample rate, etc.) as well as any metadata included
in the file. 
-The object holding the information should be added to an appropriate data
Structure
-The sound file data (sound buffer, etc) should be deleted from the heap (NOT
DISK!)

The data from each file is to be stored using a class that is designed for the type of file. 
The files may be mono or stereo and may be 8, 16, 24, or 32 bit samples.


2) Jose Torres
Given:
-When all the files are read and processed 
What to do:
-The user can choose to modify the metadata of any file. 
-When the modification is complete, the file must be saved with the new metadata. 
-The modifications should override any current metadata, or create the metadata if it didn’t exist previously.

-The user may choose to process a file by choosing one or more processors. -Processors should be applied in sequence. 

3) Rameen Feda
Given:
    All audio input (warning different audio type might require different audio manipulation)
What to do:
-The provided processors should include normalization, noise gating, and echo. 
-After processing, the user should be prompted for a file name and if valid, a
new file is created with the processed audio. 
-The user is not allowed to save the file under the same name as any of the existing files.




4) Jose Torres & Rameen Feda
What to do:
-If the user chooses to do so, a CSV file can be exported listing all the files, their technical information (sample rates, etc.), and the file metadata. 
-If no metadata exists, the phrase “No metadata present” should be included in the description for that file.


Description:

Takes a .wav file and allows user to determine what processing they want to have happen to the files that they pass in.The Files are then passed into the wav class and are edited so that the values goes into the wavHeader class and can be accessed by other parts in the code. Then depending on what processing they choose those values are then passed into the correct class.

Challenges for project:

Absolutely nothing, super ez, 360 no scope, gg no re-, D- max, Ds get degrees
