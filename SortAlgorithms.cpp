#include "SortAlgorithms.h"

void SortAlgorithms::Bubble(int Array[], const int Size) {

	if (Size < 1) {

		throw exception("Array must not be empty!");

	} else if (Size == 1) {

		return;
	}

	for (int I = 0; I < Size; ++I) {

		// in inner loop we are comparing sorted element with next element
		for (int J = 0; J < Size - 1 - I; ++J) {

			// if sorted element is higher, swap elements
			if (Array[J] > Array[J + 1]) {

				Swap(Array, J, J + 1);
			}
		}
	}
}


void SortAlgorithms::Selection(int Array[], const int Size) {

	if (Size < 1) {

		throw exception("Array must not be empty!");

	} else if (Size == 1) {

		return;
	}

	int IndexOfMaxElement = 0;

	for (int I = Size - 1; I > 0; --I) {

		IndexOfMaxElement = I;

		// in inner loop we are searching for higher element of array
		for (int J = I - 1; J >= 0; --J) {

			if (Array[J] > Array[IndexOfMaxElement]) {

				IndexOfMaxElement = J;
			}
		}

		// if higher element is not in the top, swap higher and top elements
		if (IndexOfMaxElement != I) {

			Swap(Array, I, IndexOfMaxElement);
		}
	}
}


void SortAlgorithms::Insertion(int Array[], const int Size) {

	if (Size < 1) {

		throw exception("Array must not be empty!");

	} else if (Size == 1) {

		return;
	}

	// begging sort from second element of array
	for (int I = 1; I < Size; ++I) {

		// getting index of higher element of sorted piece of array
		int J = I - 1;

		// comparing sorted element with elements from sorted piece of array
		while (J >= 0) {

			// if element lower than another element of sorted piece, moving down
			if (Array[J] > Array[I]) {

				--J;

			} else {

				// if element higher than another element of sorted piece, breaking the loop
				break;
			}
		}

		// if lower element is not before sorted element, shifting higher elements right
		if (J < (I - 1)) {

			int Temp = Array[I];

			for (int K = I - 1; K > J; --K) {

				Array[K + 1] = Array[K];
			}

			Array[J + 1] = Temp;
		}
	}
}


void SortAlgorithms::Quick(int Array[], const int Size) {

	if (Size < 1) {

		throw exception("Array must not be empty!");

	} else if (Size == 1) {

		return;
	}

	// getting the pivot
	int PivotIndex = Size / 2;
	int Pivot = Array[PivotIndex];

	int LowerThanPivotCount = 0;
	int HigherThanPivotCount = 0;

	// counting, how many elements lower and higher than pivot
	for (int I = 0; I < Size; ++I) {

		if (I == PivotIndex) {

			continue;
		} 
		
		if (Array[I] > Pivot) {

			++HigherThanPivotCount;

		} else {

			++LowerThanPivotCount;
		}
	}

	int* LeftSubarray = new int[LowerThanPivotCount];
	int* RightSubarray = new int [HigherThanPivotCount];

	int LeftSubarrayIndex = 0;
	int RightSubarrayIndex = 0;

	// moving higher than pivot elements to right subarray, lower than pivot to left subarray
	for (int I = 0; I < Size; ++I) {

		if (I == PivotIndex) {

			continue;
		}

		if (Array[I] > Pivot) {

			RightSubarray[RightSubarrayIndex] = Array[I];
			++RightSubarrayIndex;

		} else {

			LeftSubarray[LeftSubarrayIndex] = Array[I];
			++LeftSubarrayIndex;
		}
	}

	// sorting subarrays
	if (LowerThanPivotCount > 1) {

		Quick(LeftSubarray, LowerThanPivotCount);
	}

	if (HigherThanPivotCount > 1) {

		Quick(RightSubarray, HigherThanPivotCount);
	}
	

	// merge subarrays and pivot into origin array
	for (int I = 0; I < LowerThanPivotCount; ++I) {

		Array[I] = LeftSubarray[I];
	}

	Array[LowerThanPivotCount] = Pivot;

	int SortedRightSubarrayIndex = 0;

	for (int I = LowerThanPivotCount + 1; I < Size; ++I) {

		Array[I] = RightSubarray[SortedRightSubarrayIndex];
		++SortedRightSubarrayIndex;
	}

	// deleting dynamic memory
	DeleteArray(LeftSubarray);
	DeleteArray(RightSubarray);
}


/* private methods */

void SortAlgorithms::Swap(int Array[], int FromIndex, int ToIndex) {

	int Temp = 0;

	Temp = Array[ToIndex];
	Array[ToIndex] = Array[FromIndex];
	Array[FromIndex] = Temp;
}


template <typename T>
void SortAlgorithms::DeleteArray(T* Array) {

	if (Array != nullptr) {

		delete[] Array;
	}
}