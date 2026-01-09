/*
Target practise #13:
-	Develop a string compression function that compresses strings entered by the user: 
  o	Enter a string: aaabbbbcccd…
  o	Compressed string: a3b4c3d1.3

Restrictions, assumptions:
-	Comment on this data compression algorithm
- Allowed to use #include <string>
*/

#include <iostream>
#include <string>

using namespace std;

string compressString(const string& str) 
{
    string compressed;
    int count = 1;

    // loop through the string
    for (size_t i = 0; i < str.length(); ++i) // if the current character is the same as the previous one, increment the count
    {
        if (i + 1 < str.length() && str[i] == str[i + 1]) // append the character and its count to the result
        {
            ++count;
        }
        else 
        {
            compressed += str[i];
            compressed += to_string(count);
            count = 1; // reset the count
        }
    }
    return compressed;
}

int main() 
{
    cout << "Hello user!" << endl;
    cout << "Enter a string: ";
    string input;
    cin >> input;

    string result = compressString(input);
    cout << "Compressed string: " << result << endl;

    return 0;
}
