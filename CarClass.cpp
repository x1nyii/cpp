/*
Target practise #17: 
-	Develop an application that allows the user to:
  o	Enter in a unique ID (e.g. NRIC) and a name
  o	Retrieve a name based on a given unique ID

Restrictions, assumptions:
-	Use a suitable container  to address the above scenario
*/

#include <iostream>
#include <vector>
#include <list>
using namespace std;

int main() 
{
    // Vector
    vector<string> cars = { "Volvo", "BMW", "Ford", "Mazda" };
    cout << cars.empty(); // outputs 1 if the vector is empty, 0 otherwise
    cout << cars.size(); // outputs the number elements of the vector 

    cars.push_back("Tesla");// add an element at the end of the vector
    cars.pop_back(); // removes an element from the end of the vector

    // loop through a vector to print out every element in it
    for (int i = 0; i < cars.size(); ++i) 
    {
        cout << cars[i] << "\n";
    }

    // sample of for-each loop of above
    for (string car : cars) 
    {
        cout << car << "\n";
    }

    // List
    list<string> languages;
    list<string> languages = { "English", "Chinese", "Malay", "Tamil" };

    // print list elements
    for (string language : languages)
    {
        cout << language << endl;
    }

    // cannot access list elements by referring to index numbers like with arrays and vectors
    cout << languages.front(); // get the first element, output: English
    cout << languages.back(); // get the last element, output: Tamil

    languages.front() = "Hindi"; // change the value of the first element
    languages.back() = "Bahasa";

    cout << languages.front();
    cout << languages.back();

    // add list elements
    
    // Add an element at the beginning
    languages.push_front("Tesla");

    // Add an element at the end
    languages.push_back("VW");

    // Remove the first element
    languages.pop_front();

    // Remove the last element
    languages.pop_back();

    cout << languages.size();  // find the size of list

    // check if list is empty
    cout << languages.empty();  // outputs 1 if the vector is empty, 0 otherwise

    for (int i = 0; i < languages.size(); ++i) 
    {
        cout << languages[i] << "\n";
    }

    // for-each loop
    for (string language : languages)
    {
        cout << language << endl;
    }

    return 0;
}
