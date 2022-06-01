#pragma once

#include <exception>

using namespace std;

class SortAlgorithms {

public:

	void Bubble(int Array[], const int Size);
	void Selection(int Array[], const int Size);
	void Insertion(int Array[], const int Size);
	void Quick(int Array[], const int Size);

private:

	template <typename T>
	void DeleteArray(T* Array);
	void Swap(int Array[], int FromIndex, int ToIndex);
};