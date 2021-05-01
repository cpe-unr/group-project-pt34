#include <iostream>
#include <string>
#include "wav.h"
#include "Processor.h"
#include "Echo.h"
#include "Noisegate.h"
#include "Normalization.h"
#include <fstream>
const std::string testfile = "testing.wav";
const std::string echofile = "echos.wav";
const std::string limitfile = "limit.wav";
const std::string noisefile = "noise.wav";

using namespace std;

int main()
{
/**
* this is the user's first choice of chosing a file
* @choice
*/
	int choice1;
	int Icontinue;
	string fileChoice;

	
	while (choice1 != 3){
		cout << "*******************************\n";
		cout << " 1 - View file choices.\n";
		cout << " 2 - Help.\n";
		cout << " 3 - Exit.\n";
		cout << "Enter your choice and press return: ";

		cin >> choice1;

		switch (choice1)
		{

			/**
			* This is where we will display the file choices.
			* @case1 we will then progress from the file they choose to picking from
			* normalization, noise gating, and echo repeadedly, each time in between asking
			*if they want to add another processor
					*/
			case 1:
				cout << "File choices:\n8-bit\n16-bit\nPick a file\n";
				cin>>fileChoice;
				while(Icontinue == 1)
				{
					cout << "What would you like to do with your file?\n";
					cout << "1 - Echo\n";
					cout << "2 - Normalization\n";
					cout << "3 - Noise Gate\n";
					cout << "4 - Quit\n";

					cin>>choice2;
			
					switch(choice2)
					{
						case 1:
							wav wavfile1;
						    	wavfile1.readFile(testfile);
						   	Processor *processor1 = new Echo(5000);
						   	processor1->processBuffer(wavfile1.getBuffer(),wavfile1.getBufferSize(), wavfile1);
						   	wavfile1.writeFile("echos.wav");

							cout << "You have chosen to echo the file, would you like to add another selection?\n1 for yes, 2 for no:\n";
							cin>>Icontinue;
							break;
							
						case 2:
							wav wavfile2;
							wavfile2.readFile(testfile);
							Processor *processor2 = new Normalization();
							processor2->processBuffer(wavfile2.getBuffer(),wavfile2.getBufferSize(), wavfile2);
							wavfile2.writeFile("normalization.wav");

							cout << "You have chosen to normalize the file, would you like to add another selection?\n1 for yes, 2 for no\n";
							cin>>Icontinue;
							break;
						case 3:
							wav wavfile;
							wavfile.readFile(testfile);
							Processor *processor = new Noisegate();
							processor->processBuffer(wavfile.getBuffer(),wavfile.getBufferSize(), wavfile);
							wavfile.writeFile("noise.wav");

							cout << "You have chosen to Noise Gate the file, would you like to add another selection?\n1 for yes, 2 for no\n";
							cin>>Icontinue;
							break;

						case 4:
							cout<<"Cancelled program\n";
							break;
							
							
					}
				}
				break;

		case 2:
			cout << "\nYou are given the chance to modify the metadata of any file, which will then be saved. This will override current data, or create data if not previously existed. Knowing this, you are free to pick a processor or set of processors, and they shall then be applied in sequence. \n\n";
			
			break;
		
		case 3:
			cout << "End of Program.\n";
			gameOn = false;
			
			break;

	/**
	* @default The user has entered and invalid menu option, and is directed to choose again 
	*/

		default:
			cout << "Not a Valid Choice. \n";
			cout << "Choose again.\n";
			
			break;

		
		}
	}
return 0;
}
