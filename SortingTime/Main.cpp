//---------------------------------------------------------------------------------//
// CSCI 203 Data Structures: C++, Fall 2015										   //
// Program #5: Sorting Time: Main CPP File										   //
// Author: Joshua Thibado														   //
// Date Due: Dec. 10, 2015														   //
//																				   //
// PreConditions: The main function creates an object of the Sorts class, mySort   //
// It then reads in from a file called numbers.txt and inserts these items		   //
// (not in any order) into the mySort using a public function of mySort			   //
//																				   //
//																				   //
// PostConditions: The numbers read in will be sorted and information about them   //
// will be displayed to the user of the program.								   //
//																				   //
//---------------------------------------------------------------------------------//

#include <iostream>
#include "Sorts.h"

using namespace std;

void displayPrompt(ofstream &fout);

int main()
{
	int total_number_read = 0;
	int tempInt;
	char inputLetter;

	string OPString;

	ifstream fin;
	ofstream fout;
	fout.open("outputreport.txt");

	cout << "Joshua Thibado" << "\nCSCI 203" << "\nProgram 5" << "\n12/01/2015" << endl << endl; //Displays Name of creator, course name, program name, and prints the date on screen
	fout << "Joshua Thibado" << "\nCSCI 203" << "\nProgram 5" << "\n12/01/2015" << endl << endl; //Displays Name of creator, course name, program name, and prints the date all to file

	Sorts mySort;

	fin.open("numbers.txt");//Open numbers.txt
	if (!fin.fail())//If that name is valid...
	{
		fin >> tempInt;//Fin an int
		while (!fin.eof())//While not end of file
		{
			mySort.insert(tempInt);//Insert into mySort
			fin >> tempInt;//Fin an int
		}
		mySort.insert(tempInt);//Insert into mySort
	}
	fin.close();//Close file


	displayPrompt(fout);//Display Input prompt function
	cin >> inputLetter;//Cin user input
	
	while (inputLetter != 'q' && inputLetter != 'Q')//While not quit character
	{
		inputLetter = toupper(inputLetter);//Uppercase the letter for compare

		switch (inputLetter)
		{
		//Insert Sort
		case 'I':
			cout << "InsertSort: \n";
			fout << "InsertSort: \n";
			OPString = mySort.InsertSort();
			break;
		//Heap Sort
		case 'H':
			cout << "HeapSort: \n";
			fout << "HeapSort: \n";
			OPString = mySort.HeapSort();
			break;
		//Both Sort
		case 'A':
			cout << "AllSort: \n";
			fout << "AllSort: \n";
			OPString = mySort.AllSort();
			break;
		//Invalid Input
		default:
			cout << "Invalid Command, try again!";
			fout << "Invalid Command, try again!";
		}

		cout << OPString;//Ouputs sort info to screen such as time and number
		fout << OPString;//Ouputs sort info to echo file such as time and number

		displayPrompt(fout);//Display input prompt
		cin >> inputLetter;//Cin input letter
	}

	fout.close();//Close fout
	return 0;//Return 0
}

//The following function simply displays text asking for character input regarding 
//what sort the user would like to do to both screen and echo file
void displayPrompt(ofstream &fout)
{
	cout << "\n\nEnter a command. Commands are as follows: \n"
		<< "i - This commands Run the InsertSort\n"
		<< "h - This commands Run the HeapSort\n"
		<< "a - This commands Run the Both of the Sorts\n"
		<< "q - This commands says quits the program\n\n";

	fout << "\n\nEnter a command. Commands are as follows: \n"
		<< "i - This commands Run the InsertSort\n"
		<< "h - This commands Run the HeapSort\n"
		<< "a - This commands Run the Both of the Sorts\n"
		<< "q - This commands says quits the program\n\n";
}