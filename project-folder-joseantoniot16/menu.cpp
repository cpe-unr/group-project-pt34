#include <iostream>
#include <string>

using namespace std;

int main()
{
/**
* this is the user's first choice of chosing a file
* @choice
*/
	int choice;
	string fileChoice;
/**
* 
* @gameOn is for when the user chooses wrong choice
*/
	bool gameOn = true;

	
	while (gameOn != false){
	cout << "*******************************\n";
	cout << " 1 - View file choices.\n";
	cout << " 2 - Help.\n";
	cout << " 3 - Exit.\n";
	cout << " Enter your choice and press return: ";

	cin >> choice;

	switch (choice)
	{

/**
* This is where we will display the file choices.
* @case1 we will then progress from the file they choose to picking from
* normalization, noise gating, and echo repeadedly, each time in between asking
*if they want to add another processor
		*/
	case 1:
	cout << "File choices:\nPick a file";
	
	cin>>fileChoice;
		break;

		
/**
* @case2 This is simply so they know what this program consists of
*/
	case 2:
		cout << "\nYou are given the chance to modify the metadata of any file, which will then be saved. This will override current data, or create data if not previously existed. Knowing this, you are free to pick a processor or set of processors, and they shall then be applied in sequence. \n\n";
		
		break;

/**
* @case3 This is ends the program
*/		
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
