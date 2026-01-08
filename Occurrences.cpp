/*
Target practise #2:
  -	Ask the user for input: one paragraph of words
  -	Return a result indicating the number of occurrences of each number, letter, upper case and lower case, and punctuation (‘APPLE’ => A=1 P=2 L=1 E=1)
    o	Letters, numbers and punctuation that is not used should not be reported
    o	Spaces should not be reported
Restrictions, assumptions:
-	none
*/

#include <iostream>
#include <map> // provide a data structure to store key-value pairs
// can also help to count occurrences of each character
#include <cctype> // character handling library
#include <string>

using namespace std;

int main()
{
	while (true)
	{
		// create maps to store counts for each type of character
		//map<char, int> letterCount; // store letters
		//map<char, int> numberCount // store numbers
		//map<char, int> punctuationCount; // store punctuation

		// [0,0,0,...,0] - array of size 256, storing type int, values are all 0 (Mapping of ascii table/characters to count)
		// Accessing letterCount's value using character's ascii value
		/*
			NUL = letterCount[0]
			SOH = letterCount[1]
			STX = letterCount[2]
			...
			A = letterCount[65]
			...
		*/

		int letterCount[256] = {0}; // letterCount is the array which stores the count of occurance of a letter

		string input; // string variable, can take in numbers
		cout << "Please enter a paragraph of words: \n";
		getline(cin, input); // read the input and store in input string

		// iterate over each character in the input string - for range loop
		for (char character : input)
		{
			++letterCount[(int)character]; // increments the count for the letter
			//std::cout << character << ": " << letterCount[(int)character] << std::endl;
		}

		for (int i = 0; i < 256; ++i)
		{
			// if value range is within number / lowercase / uppercase / punctuation
			if (letterCount[i] > 0) // conditional expression

				if (i >= 'a' && i <= 'z' || i >= 'A' && i <= 'Z' ||
					i >= '0' && i <= '9' || i == '!' || i == '.' || i == ',' || i == '?')
					// punctuations considered: .,!?"
					std::cout << (char)i << " = " << letterCount[i] << std::endl;
		}
	}
	return 0;
}
