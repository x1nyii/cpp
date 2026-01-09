/*
Target practise #8:
-	Develop a console-based Diary application with the following menu entries:
	o	Add a diary record
	o	Display all diary records
	o	Exit
-	Records should persist on disk
Restrictions, assumptions:
-	All diary records comprise of the following fields
	o	Date
	o	Subject
	o	Entry
-	Use struct to hold the above data
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
// #include <stdint.h> // to use uint8_t which is same as 1 byte, 8 bits
// a type of unsigned integer of length 8 bits
// #include <regex>

using namespace std;

/// <summary>
/// The struct represents all the diary records: 
/// day & month must be 1 byte, year must be 2 bytes, 
/// subject & entry must be a char array of the specified size
/// </summary>
struct DiaryRecord
{
    unsigned char day;
    unsigned char month;
    unsigned short year;
    char subject[50];
    char entry[1024];

    DiaryRecord()
    {
        for (int i = 0; i < 50; ++i)
        {
            subject[i] = 0;
        }
        for (int i = 0; i < 1024; ++i)
        {
            entry[i] = 0;
        }
    }

    /*DiaryRecord() 
	{
        memset(subject, 0, sizeof(subject));
        memset(entry, 0, sizeof(entry));
    }*/ 
    // c style function
};

/// <summary>Check if the provided input (passed by reference) date is valid, with year within a specified range & months with 30 or 31 days</summary>
/// <param name="record">The entry stored as record to be evaluated </param>
/// <returns>True is date is valid; False otherwise</returns>
bool IsValidDate(const DiaryRecord& record)
{
    // cin >> record.year >> record.month >> record.day;
    if (record.year < 1900 || record.year > 2030)
    {
        cout << "Invalid year, please re-enter the entire date with a year between 1900 and 2030" << endl;
        return false;
    }
    if (record.month == 2 || record.month == 4 || record.month == 6 || record.month == 9 || record.month == 11)
    {
        if (record.day < 31)
        {
            cout << "Backend diary date registered is: " << record.year << (int)record.month << (int)record.day << endl;
            // cout << (int)record.month << "-" << (int)record.day << std::endl;
        }
        else
        {
            cout << "These months have less than 31 days!" << endl;
            return false;
        }
        // use switch
        return true;
    }
    if (record.month == 1 || record.month == 3 || record.month == 5 || record.month == 7 || record.month == 8 || record.month == 10 || record.month == 12)
    {
        if (record.day < 32)
        {
            cout << "Backend diary date registered is: " << record.year << (int)record.month << (int)record.day << endl;
            // cout << (int)record.month << "-" << (int)record.day << std::endl;
        }
        else
        {
            cout << "These months have less than 32 days!" << endl;
            return false;
        }

        return true;
    }

    return false;
}

/// <summary>Check if the provided input character array is not empty, and does not contain only whitespace</summary>
/// <param name="input">The string to be evaluated</param>
/// <returns>True if the value is valid; False otherwise</returns>
bool IsValidSubject(const char* input)
{
    // check if the input is not empty and does not contain only whitespace
    return strlen(input) > 0 && strspn(input, " ") != strlen(input);
    // strlen = length of string
    // strrspn = function returns the lengt);h of initial substring of the string pointed to by str1 that is made up of only those character contained in the string pointed to by str2
    // size_t strspn( const char* dest, const char* src 
}

//bool isValidInput(const string& input, size_t maxLength) {
//    return !input.empty() && input.find_first_not_of(' ') != string::npos && input.length() < maxLength;
//    // npos is a static member constant value with the greatest possible value for an element of type size_t
//}

/// <summary>Solicit inputs from the user and return the data in the form of a DiaryRecord struct</summary>
/// <returns>The populated DiaryRecord structure from user input</returns>
DiaryRecord GetUserInputs()
{
    DiaryRecord record; // variable record, an instance of struct
    cout << "Enter the date of your diary in the format, YYYY MM DD seperated by 1 space. e.g: 2024 08 27" << endl;
    int day, month;
    cin >> record.year >> month >> day;
    record.month = (unsigned char)month;
    record.day = (unsigned char)day;

    // can use do-while loop to reduce repetition in function :)
    while (!IsValidDate(record))
    {
        cout << "Invalid date. Please enter date (YYYY MM DD): " << endl;
        int dayBuffer, monthBuffer;
        cin >> record.year >> monthBuffer >> dayBuffer;
        record.month = (unsigned char)month;
        record.day = (unsigned char)day;
    }
    cout << "Registered diary date! Year: " << record.year << ", Month: " << (int)record.month << ", Day: " << (int)record.day << endl;

    // cin.getline() preferred
    // cin.getline(char_array, size)

    cout << "Enter diary subject: " << endl;
    cin.ignore();
    cin.getline(record.subject, 50);

    while (!IsValidSubject(record.subject))
    {
        cout << "Invalid subject. Please enter a valid diary subject: " << endl;
        cin.getline(record.subject, 50);
    }

    cout << "Enter diary entry: " << endl;
    cin.ignore();
    cin.getline(record.entry, 1024);

    while (!IsValidSubject(record.entry))
    {
        cout << "Invalid entry. Please enter a valid diary entry: " << endl;
        cin.getline(record.entry, 1024);
    }
    return record;
}

/// <summary>
/// Function AddDiaryRecord() opens the file where new entries will be added to the end of file and persist on the disk
/// </summary>
void AddDiaryRecord()
{
    DiaryRecord record = GetUserInputs();
    //string filename = "diary_records.txt";
    ofstream ostrm("diary_records.txt", std::ios::app);
    if (ostrm.is_open())
    {
        // string buffer[2000];

        //ostrm << "Date: " << (int)record.day << "/"
        //    << (int)record.month << "/"
        //    << (int)record.year << "\n";
        //ostrm << "Subject: " << record.subject << "\n";
        //ostrm << "Entry: " << record.entry << "\n";

        ostrm.write(reinterpret_cast<char*>(&record), sizeof(record));
        // ostrm << record;

        ostrm.close();
        cout << "Record added successfully." << endl;
    }
    else
    {
        cerr << "Error. Unable to open file." << endl;
    }
}

/// <summary>
/// Function DisplayRecords() open files for reading, get and display/print all the lines in the file, and then closes the file
/// </summary>
void DisplayRecords()
{
    //ifstream file("diary_records.txt", ios::binary); // open file for reading
    //if (file.is_open())
    //    
    //// (!file.is_open()) // check if file was successfully opened
    //{
    //    cerr << "Unable to open file." << endl;
    //    return; // exit function
    //}

    ifstream file("diary_records.txt", ios::binary | ios::in);

    if (file.is_open())
    {
        DiaryRecord record;

        file.read(reinterpret_cast<char*>(&record), sizeof(record));
        while (file.gcount() == 0)
        {
            // Display the record
            cout << "Date: " << static_cast<int>(record.day) << "/" << static_cast<int>(record.month) << "/" << record.year << endl;
            cout << "Subject: " << record.subject << endl;
            cout << "Entry: " << record.entry << endl;
            cout << "----------Next Entry------------\n" << endl;

            // Read a DiaryRecord from the file, reading the next line
            file.read(reinterpret_cast<char*>(&record), sizeof(record));
        }

        file.close();
    }
    else
    {
        cerr << "Error. Unable to open file for reading." << endl;
    }

//    while (true)
//    {
//        cout << record.year << ", Month: " << (int)record.month << ", Day: " << (int)record.day << endl;
//
//        cout << "Date: " << record.year << "/" << static_cast<int>(record.month) << static_cast<int>(record.day)  << endl;
//
//        cout << "Subject: " << record.subject << "\n";
//        cout << "Entry: " << record.entry << "\n";
//        break;
//    }
//    file.close();
//}
//else
//{
//    cerr << "Error. Unable to open file." << endl;
//}
}

/// <summary>
/// stores user choice from the menu and contains a while loop for user inputs choice, linked to the switch for excuting the action
/// </summary>
/// <returns>action that the user selects: add, display or exit the diary record</returns>
int main()
{
    // ios::app - append mode, opens file for writing and appends data at the end of the file
    // ios::in - read mode, open file for reading
    // ios::out - write mode, open file for writing (overwrites if the file already exists)
    int userChoice = 0; // store user menu choice

    while (userChoice != 3)
    {
        cout << "Diary Application Menu\n";
        cout << "1. Add a diary record\n";
        cout << "2. Display all diary records\n";
        cout << "3. Exit diary\n";
        cout << "Enter your choice (1-3): ";
        cin >> userChoice;
        cin.ignore(); // Ignore the newline character left in the buffer

        // f10 to run line by line
        switch (userChoice)
        {
            case 1:
                AddDiaryRecord();
                break;

            case 2:
                DisplayRecords();
                break;

            case 3:
                cout << "Bye! Exiting...\n";
                break;

            default:
                cout << "Invalid choice. Please enter a number between 1 and 3.\n";
                break;
        }
    }

    return 0;
}
