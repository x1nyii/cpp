/*
Problem: Recursive Sum Calculation

You are given a positive integer k. Implement a recursive function that returns the sum of all integers from 1 to k (inclusive). 
The function should also print the intermediate sums as it calculates the result.
Your task is to implement the recursive function sum(int k) that calculates the sum of integers from 1 to k. 
You must ensure that the function behaves as follows:
    - The sum should be calculated recursively.
    - The function should print the intermediate result at each step of the recursion in the following format:
        > Value {current value} is {current sum}

Example:
int result = sum(5);
cout << result;

Input:
A single integer k (1 ≤ k ≤ 1000).

Output:
Return the sum of integers from 1 to k.

The program should print intermediate sums.
*/

//Functions
//- Recursion functions
//    o	Typical naming conventions
//- Overloads and templates
//- Arrays, strings, string manipulations
//    o	Ascii vs Unicode(UTF8, 16, 32)
//    o	wcout vs cout
//    o	string tokenisation, substring, concatenation
//- Dynamic Memory allocation, deallocation
//    o (C++ camp) New, delete pairs
//    o (C# camp) Garbage collection
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
