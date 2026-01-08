/*
Target practise #6:
-	Ask the user to key in any set of numbers, minimum 2, maximum 5
-	Parse the input and feed the input into a Sum function that you will write
-	Return the sum of all numbers entered

Restrictions, assumptions:
-	There will be only one Sum function definition, with 2 mandatory and 3 optional parameters
*/

//-Functions
// recursion functions
//o	Typical naming conventions
//- Overloads and templates
//- Arrays, strings, string manipulations
//o	Ascii vs Unicode(UTF8, 16, 32)
//o	wcout vs cout
//o	string tokenisation, substring, concatenation
//- Dynamic Memory allocation, deallocation
//o(C++ camp) New, delete pairs
//o(C# camp) Garbage collection
//- Structures(struct)

#include <iostream>
using namespace std;

int sum(int k)
{
    if (k > 0)
    {
        int result = k + sum(k - 1);
        cout << "Value " << k << " is " << result << endl;
        return result;
        // --k;
        // return k + sum(k - 1);
    }
    else
    {
        return 0;
    }
}

int main()
{
    // for-each loop: loop through elements in an array or other data sets
    // for (type variableName : arrayName){ // code block to be executed }

    int testNumbers[5] = { 10, 20, 30, 40, 50 };
    for (int i : testNumbers)
    {
        cout << i << endl;
    }

    // recursion example
    int totalValue = sum(10);
    cout << totalValue;

    return 0;
}
