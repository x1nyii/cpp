/*
Target practise 1:
-	Ask user for number to input a COUNT
-	Ask user to key in COUNT numbers
-	Return the min, max, sum and average of all entered numbers

Restrictions, assumptions:
-	Do not use an array, or for loop
-	Input is always correct
*/

#include <iostream>

using namespace std;

int main
{
	int count;
	cout << "Please input a COUNT number: ";
	cin >> count;

	int totalCount = count; // store initial count value for average

  	int sum{};
  	int minvalue = numeric_limits < int > ::max();
  	int maxvalue = numeric_limits < int> ::min();

 	 while (count > 0)
  	{
  		cout << "Enter a number : ";
  		int input;
		cin >> input;
		cin.clear();
		// Discards invalid input, but stops the whole function
  		cin.ignore(numeric_limits < streamsize > ::max(), '\n');
  		cout << "Registered: " << input << endl;

  		if (input < minvalue)
	  	{
  			minvalue = input;
		}
  		if (input > maxvalue)
  		{
  			maxvalue = input;
  		}
  		sum += input;

		--count;
	}

	cout << "\nSum of all values: " << sum << endl;
	cout << "Smallest value: " << minvalue << endl;
	cout << "Largest value: " << maxvalue << endl;
	cout << "Average: " << sum / (double)totalCount << endl;

	return 0;
}
