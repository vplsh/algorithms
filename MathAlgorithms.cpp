#include "MathAlgorithms.h"

double MathAlgorithms::Min(double Array[], const int Size) {

	if (Size < 1) {

		throw exception("Array must not be empty!");

	} else if (Size == 1) {

		return Array[0];
	}

	double Min = Array[0];

	for (int I = 1; I < Size; ++I) {

		if (Array[I] < Min) {

			Min = Array[I];
		}
	}

	return Min;
}


double MathAlgorithms::Max(double Array[], const int Size) {

	if (Size < 1) {

		throw exception("Array must not be empty!");

	} else if (Size == 1) {

		return Array[0];
	}

	double Max = Array[0];

	for (int I = 1; I < Size; ++I) {

		if (Array[I] > Max) {

			Max = Array[I];
		}
	}

	return Max;
}


double MathAlgorithms::Sum(double Array[], const int Size) {

	if (Size < 1) {

		throw exception("Array must not be empty!");

	} else if (Size == 1) {

		return Array[0];
	}

	double Sum = 0;

	for (int I = 0; I < Size; ++I) {

		Sum += Array[I];
	}

	return Sum;
}


double MathAlgorithms::Average(double Array[], const int Size) {

	if (Size < 1) {

		throw exception("Array must not be empty!");

	} else if (Size == 1) {

		return Array[0];
	}

	double DoubleSum = Sum(Array, Size);

	return (DoubleSum / Size);
}