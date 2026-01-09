/*
Target practise #2: 
-	Develop an application that allows the user to:
  o	Accept a list of random numbers from the user
  o	As each number is entered, the application will find a suitable position to insert this number such that the result is sorted

Restrictions, assumptions:
  -	Use a suitable container  to address the above scenario
*/

#include <iostream>
#include <list>
// #include <set>
using namespace std;

int main() 
{
    // create a list container to store the numbers
    list<int> sortedList;
    int userNumber;

    cout << "Enter random numbers (type -1 to stop): " << endl;

    // loop to accept numbers from the user
    while (true) 
    {
        cout << "Enter a number: ";
        cin >> userNumber;

        if (userNumber == -1) 
        { // stop the loop when -1 is entered
            break;
        }

        // find the correct position to insert the number
        list<int>::iterator iterateList = sortedList.begin();

        while (iterateList != sortedList.end() && *iterateList < userNumber) 
        {
            ++iterateList; // keep moving the iterator to find the correct spot
        }

        // insert the number at the found position
        sortedList.insert(iterateList, userNumber); // Insertion is O(1) at the found position

        // display the updated sorted list
        cout << "Sorted List: ";
        for (int number : sortedList) 
        {
            cout << number << " ";
        }
        cout << endl;
    }

    return 0;
}
