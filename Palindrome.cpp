/*
Target practise #3:
-	Ask user for input: 1 word
-	Return a result indicating whether a string is a palindrome
o	The result evaluation should ignore case. E.g. ‘APPLE’, ‘apple’ are treated the same
o	Create one (or more, if necessary) functions to perform the check
Restrictions, assumptions:
-	Do not use helper string check functions; if these are needed, write these on your own
-	Assume user will always enter a word
*/

#include <iostream>
#include <string>

using namespace std;

string ToLowerCase(const string& word)
{
    string result = word;
    int difference = ('a' - 'A');
    for (int i = 0; i < result.length(); ++i)
    {
        if (result[i] >= 'A' && result[i] <= 'Z') // check if word is uppercase
        {
            
            result[i] += difference; // convert to lowercase by adding the difference between the ASCII values of a & A
            // result[i] += ('a' - 'A');
        }
    }
    return result;
}

bool IsPalindrome(string word)
{
    word = ToLowerCase(word);

    // check if word is a palindrome
    int left = 0;
    // size_t left = 0;
    // warning as is an unsigned type
    
    int right = (int)word.length() - 1; // same as len() in python
    
    while (left < right) // first position vs last position
    {
        if (word[left] != word[right]) // check first and last letter
        {
            return false; // if not equal, not palindrome
            // a word is less likely to be a palindrome, so return false first
        }
        // if equal, increase the position to compare the next letter,
        // moving towards the centre of the word
        ++left;
        --right;
    }
    return true; // is palindrome
}

int main()
{
    string input;
    while (true) // infinite loop
    {
    std::cout << "Enter any word to check if it's a palindrome: \n";
    cin >> input;

        if (IsPalindrome(input))
        {
            cout << "Yay! The word " << input << " is a palindrome!\n";
        }
        else
        {
            cout << "Nay, the word " << input << " is NOT a palindrome.\n";
        }
    }
    return 0;
}
