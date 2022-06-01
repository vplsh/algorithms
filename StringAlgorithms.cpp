#include "StringAlgorithms.h"

int StringAlgorithms::Length(char String[]) {

	int Size = 0;

	for (int I = 0; String[I] != '\0'; ++I) {

		++Size;

		// if string size more than 1 mb, stopping counting
		if (Size >= 1048576) {

			break;
		}
	}

	return Size;
}


void StringAlgorithms::Reverse(char String[]) {

	int StringLength = Length(String);

	int FirstCharIndex = 0;
	int LastCharIndex = StringLength - 1;

	int MiddleOfStringIndex = LastCharIndex / 2;

	while (FirstCharIndex <= MiddleOfStringIndex) {

		char Temp = String[FirstCharIndex];
		String[FirstCharIndex] = String[LastCharIndex];
		String[LastCharIndex] = Temp;

		++FirstCharIndex;
		--LastCharIndex;
	}
}