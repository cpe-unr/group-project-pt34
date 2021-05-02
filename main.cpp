#include <iostream>
#include <string>
#include "wav.h"
#include "Processor.h"
#include "Echo.h"
#include "Noisegate.h"
#include "Normalization.h"
#include <fstream>

using namespace std;

const string testfile = "testing.wav"; // inside main
const string echofile = "echos.wav";
const string limitfile = "limit.wav";
const string noisefile = "noise.wav";

int main()//args[]
{
/**
* this is the user's first choice of chosing a file
* @choice
*/
	int choice1;
	int Icontinue = -1;
	int addMods = 0;
	string fileChoice;
	wav wavfile1;
	wav wavfile2;
	wav wavfile3;
	while (choice1 != 3){
		cout << "*******************************\n";
		cout << " 1 - View file choices.\n";
		cout << " 2 - Help.\n";
		cout << " 3 - Exit.\n";
		cout << "Enter your choice and press return: ";

		cin >> choice1;
		//for(int i = 1; i<args.size;i++){  string testFile = args[i]   } ||NOT IN CORRECT PLACE
		switch (choice1)
		{
				/**
				* This is where we will display the file choices.
				* @case1 we will then progress from the file they choose to picking from
				* normalization, noise gating, and echo repeadedly, each time in between asking
				*if they want to add another processor
						*/
			case 1:
				do
				{
					cout << "What would you like to do with your file?\n";
					cout << "1 - Echo\n";
					cout << "2 - Normalization\n";
					cout << "3 - Noise Gate\n";
					cout << "4 - Quit\n";

					cin>>Icontinue;
				
					switch(Icontinue)
					{
						case 1:
							{	
								cout<<"WORKS!"<<endl;
								wavfile1.readFile(testfile); // needs to be correct args[value]
								Processor *processor1 = new Echo(1);
								processor1->processBuffer(wavfile1.getBuffer(),wavfile1.getBufferSize(), wavfile1);
								wavfile1.writeFile(testfile + "_echos.wav"); // LOOK HERE GIVES NEW NAMES FOR EACH FILE
								
								cout << "You have chosen to echo the file, would you like to add another selection?\n1 for yes, 2 for no:\n";
								cin>>addMods;
								
									break;
								
							}	
						case 2:
							{
								wavfile2.readFile(testfile);//args
								Processor *processor2 = new Normalization();
								processor2->processBuffer(wavfile2.getBuffer(),wavfile2.getBufferSize(), wavfile2);
								wavfile2.writeFile("normalization.wav");

								cout << "You have chosen to normalize the file, would you like to add another selection?\n1 for yes, 2 for no\n";
								cin>>addMods;
								break;
							}
						case 3:
							{
								wavfile3.readFile(testfile);//args
								Processor *processor = new Noisegate();
								processor->processBuffer(wavfile3.getBuffer(),wavfile3.getBufferSize(), wavfile3);
								wavfile3.writeFile("noise.wav");

								cout << "You have chosen to Noise Gate the file, would you like to add another selection?\n1 for yes, 2 for no\n";
								cin>>addMods;
								break;
							}

						case 4:
							cout<<"Cancelled program\n";
							choice1 == 3;
							break;

						default:
							cout << "Not a Valid Choice. \n";
							cout << "Choose again.\n";
							break;
								
					}
				}while(Icontinue != 4 &&addMods!=2);
			break;
		case 2:
			cout << "\nYou are given the chance to modify the metadata of any file, which will then be saved. This will override current data, or create data if not previously existed. Knowing this, you are free to pick a processor or set of processors, and they shall then be applied in sequence. \n\n";
			break;
		
		case 3:
			cout << "End of Program.\n";
			choice1 = 3;
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
