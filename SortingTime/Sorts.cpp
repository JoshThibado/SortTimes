//---------------------------------------------------------------------------------//
// CSCI 203 Data Structures: C++, Fall 2015										   //
// Program #5: Sorting Time: Sorts CPP File										   //
// Author: Joshua Thibado														   //
// Date Due: Dec. 10, 2015														   //
//																				   //
// PreConditions: This class takes integers into arrays contained within it		   //
// using a public Insert() function. The items can come in any order and may	   //
// be sorted																	   //
//																				   //
// PostConditions: The numbers read in will be sorted and information about them   //
// will be displayed to the user of the program.								   //
//																				   //
// NOTE: Let IS = InsertSort, Let HS = HeapSort									   //
//																				   //
//---------------------------------------------------------------------------------//
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include "Sorts.h"


Sorts::Sorts()
{
	totalread = 0;

	ISOut.open("ISSorted.txt");//Opens IS OutStream
	HSOut.open("HSSorted.txt");//Opens HS Outstream

}


Sorts::~Sorts()
{
	ISOut.close();			   //Closes IS OStream
	HSOut.close();			   //Closes HS OStream
}

//The following function inserts integers passed to it into an array
//This array will remain unaltered throughout the program
void Sorts::insert(int num)
{
	list[totalread + 1] = num;	//Sets List at total read+1 to be passed in int
	totalread++;				//Increments TotalRead
	n = totalread;				//number read = total read
}

//This function copies every number from original read in array to the new array
//That will be sorted in
void Sorts::copyArray()
{
	totalNumberRead = totalread; //Total = Total2
	n = totalread;				 //number read = total read
	

	for (int c = 1; c <= n; c++)//For every number in array, copy to new array
	{
		TMPList[c] = list[c];//TMPList = list
	}

}

//This function swaps two values at a particular position in the array
// Using the Method Below
void Sorts::swap(int p1, int p2)
{
	TMPList[p1] = TMPList[p1] + TMPList[p2];//A = A + B
	TMPList[p2] = TMPList[p1] - TMPList[p2];//B = A - B
	TMPList[p1] = TMPList[p1] - TMPList[p2];//A = A - B
}


//---------------------------------------Insert Sort Functions-------------------------------

//This function is called to begin the insertion sort
//It first copies the original array to the manipulation array and also resets the sortString
string Sorts::InsertSort()
{
	copyArray();					//Copies Original Array to the array that will be sorted
	SortString = "";				//Empty the string

	starttime = (long)time(NULL);	//Record Start time

	ISort();						//Perform the Sort

	endtime = (long)time(NULL);		//Record the endtime
	totalseconds = endtime - starttime;//Calculate seconds elapsed
	minutes = totalseconds / 60;	// seconds in a minute
	seconds = totalseconds % 60;	// the rest are the seconds

	//-----The code below appends necessary data to the SortString
	SortString.append("Sort Type: InsertSort()\n");
	SortString.append("Number Sorted : ");
	SortString.append(to_string(n-1));
	SortString.append("\n");

	SortString.append("End Time      : ");
	SortString.append(to_string(endtime));
	SortString.append("\n");
	
	SortString.append("Start Time    : ");
	SortString.append(to_string(starttime));
	SortString.append("\n");

	SortString.append("Elapsed Time  : ");
	SortString.append(to_string(minutes));
	SortString.append(" Minutes, ");
	SortString.append(to_string(seconds));
	SortString.append(" Seconds");
	//------End sortString appendage code

	IsortPrint();//prints sortString to the ISSorted.txt file

	return SortString;
}

//This Function performs an insertSort on the elements of TMPList
//When it is done, TMPList will be in order
void Sorts::ISort()
{

	for (int j = 2; j <= n; j++)//For every element in list start with second element
	{
		key = TMPList[j];//Item being examined = item at position j

		i = j - 1;		//i Is one position before j

		while (i > 0 && TMPList[i] > key)//While i > 0 and value at i is less than value at key
		{
			TMPList[i + 1] = TMPList[i];//Element at i=1th position = item at i position
			i--;						//Decrement i

		}
		//Found spot!
		TMPList[i + 1] = key;//position i+1 = key
	}
}

//This function simply prints out information about the IS that took place
//Such as time and also every 50,000 Number
void Sorts::IsortPrint()
{
	int k = 1;

	ISOut << endl;				//Newline for formatting
	for (k = 1; k <= n; k += 50000)
	{
		ISOut << k << ": " << TMPList[k] << endl;//Print number every 50K
	}
	ISOut << SortString;//Prints Sortstring to HS output file
}


//------------------------Heapsort Functions---------------------------------
string Sorts::HeapSort()
{
	copyArray();						//Copies Original Array to the array that will be sorted
	SortString = "";					//Empty the string

	starttime = (long)time(NULL);		//Record Start time
			
	HSort(n);							//Perform the Sort

	endtime = (long)time(NULL);
	totalseconds = endtime - starttime;	//Record the endtime
	minutes = totalseconds / 60;		// seconds in a minute
	seconds = totalseconds % 60;		// the rest are the seconds

	//-----The code below appends necessary data to the SortString
	SortString.append("Sort Type: HeapSort()\n");
	SortString.append("Number Sorted : ");
	SortString.append(to_string(n-1));
	SortString.append("\n");

	SortString.append("End Time      : ");
	SortString.append(to_string(endtime));
	SortString.append("\n");

	SortString.append("Start Time    : ");
	SortString.append(to_string(starttime));
	SortString.append("\n");

	SortString.append("Elapsed Time  : ");
	SortString.append(to_string(minutes));
	SortString.append(" Minutes, ");
	SortString.append(to_string(seconds));
	SortString.append(" Seconds");
	//------End sortString appendage code

	HsortPrint();//prints HeapString to the HSSorted.txt file

	return SortString;
}

//This Function performs an HeapSort on the elements of TMPList
//When it is done, TMPList will be in order
void Sorts::HSort(int n)
{
	int i, j;

	//This for loop heapifies the TMPList
	//For item not a leaf(n/2), I > 0, decrement i
	for (i = n / 2; i > 0; i--)
	{
		adjust(i, n);//Adjusts the heap
	}

	//This for loop sorts the heap by swapping the first and ith item
	//Then adjusting the new heap and making it so the imaginary new heap
	//Is 1 item smaller on the right. In the end the List will be 
	//in non-decreasing order
	for (i = n - 1; i > 0; i--)
	{
		swap(1, i + 1);//Swap the first and last items
		adjust(1, i);//Adjust the heap to make it a heap again
	}

}

//The adjust function makes sure that any item in the tree is larger than all
//Of its children
void Sorts::adjust(int i, int n)
{
	int lchild, rchild, larger;

	lchild = 2 * i;//Left child's spot = Left child's spot in array
	larger = lchild;//Larger is set to left child by default

	if (lchild <= n)
	{
		//root not a leaf
		rchild = lchild + 1;

		//if root has rchild, find larger child
		if ((rchild <= n) && (TMPList[rchild] > TMPList[lchild]))
		{
			larger = rchild;//Then rchild is larger of the children
		}

		//If root value smaller than larger child, swap root and larger child
		if (TMPList[i] < TMPList[larger])
		{
			swap(i, larger);  //Swap i and larger child
			adjust(larger, n);//Adjusts list recursively from larger 
							  //until all children are in heap
		}

	}//End if lchild <=n


}//Adjust

//This function simply prints out information about the HS that took place
//Such as time and also every 50,000 Number
void Sorts::HsortPrint()
{
	int p = 1;
	HSOut << endl;				//Newline for formatting
	for (p = 1; p <= n; p += 50000)
	{
		HSOut << p << ": " << TMPList[p] << endl;//Print number every 50K
	}
	HSOut << SortString;//Prints Sortstring to HS output file

}


//-------------------------Allsort Functions----------------------------------
string Sorts::AllSort()
{
	AllString = "";
	AllString.append("Sorting Times\n*************\nNumber Sorted: ");
	AllString.append(to_string(n-1));

	//HEAP SORT PART
	starttime = (long)time(NULL);		//Record Start time
	HeapSort();							//Perform the Sort
	endtime = (long)time(NULL);

	totalseconds = endtime - starttime;	//Record the endtime
	minutes = totalseconds / 60;		// seconds in a minute
	seconds = totalseconds % 60;		// the rest are the seconds

	//The code below simply appends info about the heapsort to Allstring
	AllString.append("\nHeapSort()   : ");
	AllString.append(to_string(minutes));
	AllString.append(" Minutes, ");
	AllString.append(to_string(seconds));
	AllString.append(" Seconds\n");
	//--

	//INSERT SORT PART
	starttime = (long)time(NULL);	//Record Start time
	InsertSort();						//Perform the Sort
	endtime = (long)time(NULL);		//Record the endtime

	totalseconds = endtime - starttime;//Calculate seconds elapsed
	minutes = totalseconds / 60;	// seconds in a minute
	seconds = totalseconds % 60;	// the rest are the seconds
	
	//The code below simply appends info about the insertsort to Allstring
	AllString.append("\nInsertSort() : ");
	AllString.append(to_string(minutes));
	AllString.append(" Minutes, ");
	AllString.append(to_string(seconds));
	AllString.append(" Seconds\n");
	

	return AllString; //Returns AllString
}