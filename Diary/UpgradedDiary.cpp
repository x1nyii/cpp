/*
Target practise #9:
-	Upgrade the console-based Diary to write data in a binary format to disk

Restrictions, assumptions:
-	The following data structure should be in use:
  o	All diary records comprise of the following fields
    >	Date
      •	Day (1 byte)
      •	Month (1 byte)
      •	Year (2 bytes - short)
    > Subject
      •	Character array [50 bytes]
    >	Entry
      •	Character array [1024 bytes]

-	Data written to disk shall be in binary form, not formatted as ASCII text
*/

// new - delete pairs
// use appropriate functions
// include all previous disciplines

#include <iostream>
#include <fstream>

using namespace std;

enum userAction
{
    entry = 1,
    view = 2,
    leave = 3
};

/// <summary>
/// GetUserInputs() get user to input the count number and numbers to include the count. 
/// The inputs are saved in userCount and userNumbers.
/// </summary>
void GetUserInputs(int& userCount, int*& userNumbers)
// int& userCount is a reference to an integer. The function can modify the value of userCount directly, and the changes will be reflected outside the function.
// int*& userNumbers is a reference to a pointer to an integer. The function can modify the pointer itself (i.e., make it point to a different memory location) and the changes will be reflected outside the function.

{
    cout << "Please enter any COUNT number. Integers only:" << endl;
    // int userCount;
    cin >> userCount;

    // int* userNumbers = new int[userCount]; // initialise a new array to store user numbers
    userNumbers = new int[userCount]; // initialise a new array to store user numbers
    // using loop to move to every array element and then 
    // using either cin to insert the value given by the 
    // user to the array element
    for (int i = 0; i < userCount; ++i)
    {
        // if (sizeof(UserNumbers == userCount))

        cout << "Please enter a whole number: ";
        cin >> userNumbers[i];
    }

    // Print the array elements 
    cout << "The array elements are: ";
    for (int i = 0; i < userCount; ++i)
    {
        cout << userNumbers[i] << " ";
    }
}

/// <summary>
/// Function AddNumericalRecord() opens the file where new entries will be added to the end of file and persist on the disk
/// Modify GetUserInputs to return the array and count of user inputs.
/// </summary>
void AddNumericalRecord()
{
    //string filename = "numerical_records.txt";
    ofstream ostrm("numerical_records.txt", std::ios::app | ios::binary);
    if (ostrm.is_open())
    {
        // DiaryRecord record = GetUserInputs();
        int userCount;
        int* userNumbers;
        // int* userNumbers = nullptr; // do i need to nullptr it? this is superstitious

        GetUserInputs(userCount, userNumbers);

        if (userNumbers != nullptr) // safety check
        {
            ostrm.write(reinterpret_cast<char*>(&userCount), sizeof(userCount));
            ostrm.write(reinterpret_cast<char*>(userNumbers), sizeof(int) * userCount);


            // do i need to free the allocated memory? does it matter? 
            // delete[] userNumbers; 

            ostrm.close();
            cout << "\nRecord numbers added successfully." << endl;
        }
    }
    else
    {
        cerr << "\nError. Unable to open file." << endl;
    }
}

/// <summary>
/// Function DisplayRecords() open files for reading, get and display/print all the numbers from array in the file grouped by count, and then closes the file
/// </summary>
void DisplayRecords()
{
    ifstream file("numerical_records.txt", ios::binary | ios::in);

    if (file.is_open())
    {
        // AddNumericalRecord();
        //GetUserInputs(userCount, userNumbers); // not getting any user inputs, just displaying now


        while (file.peek() != EOF)
        {
            int userCount{};
            file.read(reinterpret_cast<char*>(&userCount), sizeof(userCount));
            int* userNumbers = new int[userCount];
            file.read(reinterpret_cast<char*>(userNumbers), sizeof(int) * userCount);

            
            // Display the record
            cout << "Count: " << (userCount) << endl;
            cout << "Numbers: ";
            for (int i = 0; i < userCount; ++i)
            {
                cout << userNumbers[i] << " ";
            }
            cout << "\n----------Next Entry------------\n" << endl;

            delete[] userNumbers;
        }
            //// Read a DiaryRecord from the file, reading the next line
            //file.read(reinterpret_cast<char*>(&userCount), sizeof(userCount));
            //file.read(reinterpret_cast<char*>(userNumbers), sizeof((int)*userNumbers));
        file.close();
        }

    else
    {
        cerr << "Error. Unable to open file for reading." << endl;
    }
}

int MenuActions()
{
    int userChoice = 0; // store user menu choice

    do
    {
        cout << "Diary Application Menu\n";
        cout << "1. Add a diary record\n";
        cout << "2. Display all diary records\n";
        cout << "3. Exit diary\n";
        cout << "Enter your choice (1-3): ";
        cin >> userChoice;
        switch (userChoice)
        {
            case entry:
                AddNumericalRecord();
                cout << "\n" << endl;
                break;

            case view:
                DisplayRecords();
                cout << "\n" << endl;
                break;

            case leave:
                cout << "Bye! Exiting...\n";
                break;
        }
    } while (userChoice != leave);
    return 0;
}


int main()
{
    MenuActions();

    return 0;
}
