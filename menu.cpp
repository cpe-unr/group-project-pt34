#include <iostream>
#include <string>

using namespace std;

int main()
{
/**
* this is the user's first choice of chosing a file
* @choice
*/
	int choice1;
	int choice2;
	int choice3;
	string fileChoice;
	int Icontinue;
	
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
	gameOn = false;
	cin>>fileChoice;
	
	cout << "What would you like to do with your file?\n";
	cout << "1 - Echo\n";
	cout << "2 - Normalization\n";
	cout << "3 - Noise Gate\n";
	cout << "4 - Quit\n";

	cin>>choice2;
	
/**
* switch acts as another menu for picking what to do
* @choice2 already picked the file they want to work with and what to do first
* now they chose if they want to add more changes
*/
		switch(choice2)
		{
			case 1:
			cout << "You have chosen to echo the file, would you like to add another selection?\n1 for yes, 2 for no:\n";
			cin>>Icontinue;

				if (Icontinue == 1){
					cout << "What would you like to do with your file?\n";
					cout << "1 - Echo\n";
					cout << "2 - Normalization\n";
					cout << "3 - Noise Gate\n";
					cout << "4 - Quit";
		
					cin>>choice3;
					break;
					}
				else if (Icontinue ==2){
					cout<< "Thanks for making my life easy\n";
				 	break;
				}
				case 2:
			cout << "You have chosen to normalize the file, would you like to add another selection?\n1 for yes, 2 for no\n";
			cin>>Icontinue;

				if (Icontinue == 1) {
					cout << "What would you like to do with your file?\n";
					cout << "1 - Echo\n";
					cout << "2 - Normalization\n";
					cout << "3 - Noise Gate\n";
					cout << "4 - Quit\n";
				
					cin>>choice3;

					}
				if (Icontinue ==2){
					cout<< "Thanks for making my life easy\n";}
				 	break;
				
				case 3:
			cout << "You have chosen to Noise Gate the file, would you like to add another selection?\n1 for yes, 2 for no\n";
			cin>>Icontinue;

				if (Icontinue == 1) {
					cout << "What would you like to do with your file?\n";
					cout << "1 - Echo\n";
					cout << "2 - Normalization\n";
					cout << "3 - Noise Gate\n";
					cout << "4 - Quit\n";
				
					cin>>choice3;
					}
				if (Icontinue ==2){
					cout<< "Thanks for making my life easy\n";
				}
				 	break;

				case 4:
					cout<<"Cancelled program\n";
					break;
				
				
		}
			
				
							
			
			

	
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
