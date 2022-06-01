#include <cassert>
#include <iostream>
#include <string>

#include "SortAlgorithms.h"
#include "SearchAlgorithms.h"
#include "MathAlgorithms.h"
#include "StringAlgorithms.h"

using namespace std;

void AssertEquals(int CheckedValue, int ExpectedValue);
void AssertEquals(char CheckedValue, char ExpectedValue);
void AssertEquals(double CheckedValue, double ExpectedValue);
void AssertSorted(int SortedArray[], int CheckedArray[], const int Size, string SortType);

int main() {

	const int ArraySize = 4;


	/* SearchAlgorithms class testing */

	SearchAlgorithms Search;

	int SortedArrayForSearch[ArraySize] = { 14, 19, 37, 51 };

	int SearchedValue = 37;


	// Linear search test case
	int LinearIndex = Search.Linear(SortedArrayForSearch, ArraySize, SearchedValue);

	AssertEquals(LinearIndex, 2);


	// Binary search test case
	int BinaryIndex = Search.Binary(SortedArrayForSearch, ArraySize, SearchedValue);

	AssertEquals(BinaryIndex, 2);


	/* SortAlgorithms class testing */

	SortAlgorithms Sort;

	int SortedArray[ArraySize] = { 11, 17, 23, 76 };


	// Bubble sort test case
	int UnsortedArrayForBubble[ArraySize] = { 23, 17, 76, 11 };

	Sort.Bubble(UnsortedArrayForBubble, ArraySize);

	AssertSorted(SortedArray, UnsortedArrayForBubble, ArraySize, "bubble");


	// Selection sort test case
	int UnsortedArrayForSelection[ArraySize] = { 23, 17, 76, 11 };

	Sort.Selection(UnsortedArrayForSelection, ArraySize);

	AssertSorted(SortedArray, UnsortedArrayForSelection, ArraySize, "selection");


	// Insertion sort test case
	int UnsortedArrayForInsertion[ArraySize] = { 23, 17, 76, 11 };

	Sort.Insertion(UnsortedArrayForInsertion, ArraySize);

	AssertSorted(SortedArray, UnsortedArrayForInsertion, ArraySize, "insertion");


	// Quick sort test case
	int UnsortedArrayForQuick[ArraySize] = { 23, 17, 76, 11 };

	Sort.Quick(UnsortedArrayForQuick, ArraySize);

	AssertSorted(SortedArray, UnsortedArrayForQuick, ArraySize, "quick");


	/* MathAlgorithms class testing */

	MathAlgorithms Math;

	double Array[ArraySize] = { 23.4, 71.2, 98.6, 45.7 };


	// Min test case
	double Min = Math.Min(Array, ArraySize);

	AssertEquals(23.4, Min);


	// Max test case
	double Max = Math.Max(Array, ArraySize);

	AssertEquals(98.6, Max);


	// Sum test case
	double Sum = Math.Sum(Array, ArraySize);


	// Average test case
	double Average = Math.Average(Array, ArraySize);


	/* StringAlgorithms class testing */

	StringAlgorithms String;

	char CStyleString[] = { 'H', 'e', 'l', 'l', 'o', ',', ' ', 'w', 'o', 'r', 'l', 'd', '!', '\0'};


	// Length test case
	int Length = String.Length(CStyleString);

	AssertEquals(Length, 13);


	// Reverse test case
	String.Reverse(CStyleString);

	AssertEquals(CStyleString[0], '!');


	return 0;
}


/* Functions for tests */

void AssertEquals(char CheckedValue, char ExpectedValue) {

	assert(ExpectedValue == CheckedValue);

	cout << CheckedValue << " value is equal to " << ExpectedValue << endl;
}

void AssertEquals(int CheckedValue, int ExpectedValue) {

	assert(ExpectedValue == CheckedValue);

	cout << CheckedValue << " value is equal to " << ExpectedValue << endl;
}

void AssertEquals(double CheckedValue, double ExpectedValue) {

	assert(ExpectedValue == CheckedValue);

	cout << CheckedValue << " value is equal to " << ExpectedValue << endl;
}

void AssertSorted(int SortedArray[], int CheckedArray[], const int Size, string SortType) {

	for (int I = 0; I < Size; ++I) {

		assert(SortedArray[I] == CheckedArray[I]);
	}

	cout << "Array had been successfully sorted with " << SortType << " sort method!" << endl;
}