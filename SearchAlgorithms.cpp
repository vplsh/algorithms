#include "SearchAlgorithms.h"

int SearchAlgorithms::Linear(int Array[], int Size, int Value) {

    if (Size < 1) {

        throw exception("Array must not be empty!");
    }

    for (int I = 0; I < Size; ++I) {

        if (Array[I] == Value) {

            return I;
        }
    }

    return -1;
}

int SearchAlgorithms::Binary(int Array[], int Size, int Value) {

    if (Size < 1) {

        throw exception("Array must not be empty!");

    } else if (Size == 1) {

        if (Array[0] == Value) {

            return 0;

        } else {

            return -1;
        }
    }

    int MiddleElement = 0;

    int LeftBound = 0;
    int RightBound = (Size - 1);

    while (1) {

        MiddleElement = (LeftBound + RightBound) / 2;

        if (Array[MiddleElement] == Value) {

            return MiddleElement;

        } else if (Array[MiddleElement] < Value) {

            LeftBound = MiddleElement + 1;

        } else if (Array[MiddleElement] > Value) {

            RightBound = MiddleElement - 1;
        }

        if (LeftBound > RightBound) {

            return -1;
        }
    }
}
