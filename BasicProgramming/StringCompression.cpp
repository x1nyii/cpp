/*
Target practise #13:
-	Develop a string compression function that compresses strings entered by the user: 
  o	Enter a string: aaabbbbcccd…
  o	Compressed string: a3b4c3d1.3

Restrictions, assumptions:
-	Comment on this data compression algorithm
*/

#include <iostream>
#include <sstream> // try to use this

// loop through string and then count repeated, if it's same, then continue counting, o/w flush out the count/result

using namespace std;

/// <summary>
/// To compress a string by replacing consecutive repeating characters with the character followed by the count of repetitions
/// </summary>
/// <param name="userInput"></param>
/// <returns>The compressed string</returns>

string stringCompression(string userInput) 
{
    int index = 0; 
    // initialise a variable that holds the value of the current character in the string so that the code can count how many times it repeats consecutively
    char character = ' '; // used to store the current character being processed from the input string
    int count = 1; // occurrences of current character
    string convertInt = ""; // an empty string that will store the count of characters as a string

    // initialize initial_index to store the starting index of a sequence of characters, and length to store the length of the input string
    int initial_index = 0, length = userInput.length();
    cout << length << endl;

    // loop through each index of the input string
    while (index < userInput.length()) 
    {
        character = userInput[index]; // set the current character to the character at the current index
        initial_index = index; // store the starting index of the current sequence of characters
        ++index; // move to the next character

        while (index <= userInput.length() && userInput[index] == character) // checks if the next character is the same as the current character
        {
            // if it is the same, then do:
            ++count; // increment the count
            ++index; // move to the next character
            // this loop continues until a different character is found or the end of the string is reached
        }

        // performs the compression
        if (count >= 1) // if count more than or equal to 1, then do:
        {
            convertInt = to_string(count); // convert the count of characters to a string
            userInput.erase((initial_index + 1), count - 1); // remove the repeated characters from the input string, leaving only the first occurrence
            userInput.insert(initial_index + 1, convertInt); // insert the count string after the first occurrence of the character
            index = initial_index + convertInt.length() + 1; // update the index to the position after the inserted count string
            count = 1; // Reset the count for the next sequence of characters
        }
    }
    return userInput;
}

int main()
{
    std::cout << "Hello User, please enter any string you want (e.g. aaabbbbb..) and i will compress it for you!\n";
    string userInput;
    cin >> userInput;
    cout << stringCompression(userInput) << endl;
    // use string builder as string can be quite expensive
    return 0;
}
