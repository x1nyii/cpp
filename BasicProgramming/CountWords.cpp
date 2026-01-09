/*
Target practise #5:
-	Ask the user for a sentence
-	Return a result indicating the number of words in the sentence.

Restrictions, assumptions:
-	Assume the user will use punctuation.
-	Can use the string.Split() [C#] or strtok [C++] function
	o	Warning: strtok is a deprecated function. Use of strtok is purely for exposure and target-practice purposes and shall not be used in the field
*/

// Bootcamp3.3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// Return a result indicating the number of words in the sentence. (ONLY WORDS)

#pragma warning(disable : 4996)
#include <iostream> 
#include <string>
#include <cstring>   // include the cstring library for strtok function
// strtok used to tokenize stings
// modifies the original string by inserting null characters (\0) at the delimiter positions
// not thread-safe
// #include <sstream>

using namespace std;

int main() 
{
    // declare a character array to store the user's sentence
    // in C++, cannot directly assign a string to a character array using the = operator
    // character arrays require special handling for input and assignment
    char sentence[1024];

    // prompt the user to enter a sentence
    cout << "Please enter a sentence: ";
    cin.getline(sentence, 1024);  // read the entire line of input including spaces into the sentence array

    char* token; // declare a pointer to a character for tokenization

    // Comprehensive set of delimiters
    // const char* delimiters = " ,.!?;:@&#$%^&*()-_=+[]{}|\\;:'\"<>,./?`~";

    // use strtok to split the sentence into words based on spaces and punctuation
    token = strtok(sentence, " ,.!?;:@&#$");

    // char* token = strtok(sentence, delimiters);

    int wordCount = 0; // initialize a counter for the number of words

    while (token != nullptr) // loop through all tokens (words) in the sentence
    {
        ++wordCount;  // increment the word count for each token found
        token = strtok(nullptr, " ,.!?;:@");  // get the next token
    }

    // output the number of words in the sentence
    cout << "The number of words in the sentence is: " << wordCount << endl;

    return 0;
}
