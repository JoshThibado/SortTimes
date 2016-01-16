//---------------------------------------------------------------------------------//
// CSCI 203 Data Structures: C++, Fall 2015										   //
// Program #5: Sorting Time: Sorts Header File									   //
// Author: Joshua Thibado														   //
// Date Due: Dec. 10, 2015														   //
//																				   //
// Briefing: This is the header file for the Sorts Class. This class can take in   //
// Integers into a private array using a public Insert Function and then the items //
// In said array will be copied to another array and sorted. Each call of the any  //
// Type of sort will reset the secondary array to the unsorted contents of the	   //
// Original Array.																   //
//																				   //
//---------------------------------------------------------------------------------//

#pragma once

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Sorts
{
public:
	Sorts();//CTOR
	~Sorts();//DTOR

	void insert(int num);//Insert into Array Fxn

	string InsertSort(); //FXN to start Insert Sort
	string HeapSort();	 //FXN to start Heap Sort
	string AllSort();	 //FXN to start both^^


private:
	int	list[1000002];	  //Array to hold the original read in numbers(max 1 Million Plus 1)
	int TMPList[1000002]; //Array to hold the original read in numbers(max 1 Million Plus 1)
						  //For both, position 0 isn't used

	ofstream ISOut;		  //Outstream for InsertSort Out
	ofstream HSOut;		  //Outstream for HeapSort Out

	string SortString;	  //String to hold info after sorts, to be returned
	string AllString;	  //String to hold info after both sorts, to be returned

	int totalread;		  //Total number of items read in
	int totalNumberRead;  //Secondary Holder for number items read in

	int n;				  //Number of items in list[]
	int key;			  //Key, used for InsertSort
	int i;				  //Index var used for sorting 

	//The variables below are used for timing Times and time elapsed
	long starttime, endtime, minutes, seconds, totalseconds;

	void copyArray();	  //Function to copy original array to TMPList[]
	void swap(int p1, int p2);//Function to swap 2 variables

	void ISort();		  //InsertSort Function that does all the work

	void HSort(int n);	  //Heapsort Function that does all the work
	void adjust(int i, int n);//Used in heapsort

	void IsortPrint();	  //Prints contents of InsertSort
	void HsortPrint();	  //Prints contents of HeapSort
};

