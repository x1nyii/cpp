/*
  Target practise #7:
-	Ask the user for two numbers
-	Ask the user for an operation: plus, minus, multiplication, division, power
-	Return a result depending on the user input

Restrictions, assumptions:
-	Define 5 separate functions for plus, minus, multiplication, division, power
-	Use a function pointer/delegate and assign to it the correct function, before execution; do not call the function directly
*/

#include <iostream>
#include <string>
#include <sstream>
// have not learnt vector so use array atp
// #include <vector>

using namespace std;

int Sum(int a, int b, int c = 0, int d = 0, int e = 0) // optional parameters
{
	return a + b + c + d + e;
}

int main()
{
	// declare an array for user inputs
	// array can take in maximum 5 inputs
	// array index is from 0
	int arrayNumbers[5] = { 0 }; // initialize all array elements to 0

	// for-each loop to print out all elements in array
	for (int i : arrayNumbers)
	{
		cout << i << endl;
	}

	int count = 0;

	// sizeof() operator returns the size of a type in bytes
	// int is 4bytes, so 4 bytes x 5 elements = 20 bytes
	int getArrayLength = sizeof(arrayNumbers) / sizeof(int);
	cout << getArrayLength << endl;
	// OR
	cout << "Current array size: " << sizeof(arrayNumbers) / sizeof(int) << endl;;

	// get user input
	cout << "Please input any set of numbers, minimum 2 sets of numbers and maximum 5 sets of numbers, separated by spaces: \n";
	string inputNumbers;
	getline(cin, inputNumbers);
	// cin >> inputNumbers;

	stringstream ss(inputNumbers); // creates an object named 'ss' and intialize with contents of the input string
	int num; // declares a variable to temporarily hold the numbers extracted the from the stream to store in array

	while (ss >> num) // populate array
	{
		// if (sizeof(arrayNumbers) >= 1 && sizeof(arrayNumbers) < 5)
		if (count < 5)
		{
			// arrayNumbers[count++] = num;
			arrayNumbers[count] = num;
			// cout << "Numbers registered: " << inputNumbers << endl; - ignore
			// cout << "Numbers registered (into array): " << arrayNumbers[i] << endl;
		}
		++count;
	}
	if (count < 2 || count > 5)
	{
		cout << "Error, you must enter between 2 and 5 sets of numbers, separated by spaces! Please re-run: " << endl;
		return 0;
	}

	// calculate sum based on number of inputs
	int result = 0;
	switch (count)
	{
	case 2:
		result = Sum(arrayNumbers[0], arrayNumbers[1]);
		break;
	case 3:
		result = Sum(arrayNumbers[0], arrayNumbers[1], arrayNumbers[2]);
		break;
	case 4:
		result = Sum(arrayNumbers[0], arrayNumbers[1], arrayNumbers[2], arrayNumbers[3]);
		break;
	case 5:
		result = Sum(arrayNumbers[0], arrayNumbers[1], arrayNumbers[2], arrayNumbers[3], arrayNumbers[4]);
		break;
	}

	cout << "The sum of the entered numbers is: " << result << endl;

	return 0;
}
