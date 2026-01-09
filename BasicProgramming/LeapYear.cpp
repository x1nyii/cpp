/*
Target practise #11: 
-	Develop an application that determines if an input year from the user is a leap year 

Restrictions, assumptions:
-	Logic to determine whether a year is a leap year should be in a function
*/

#include <iostream>

using namespace std;

// scoping should be specific but 
// solve problems generically without limits, where it is feasible, don't overkill

//A year is a leap year if it is divisible by 4.
//However, if the year is also divisible by 100, it is not a leap year, unless:
//The year is also divisible by 400, in which case it is a leap year.
bool IsLeapYear(int year)
{
    if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
    {
        return true;
    }
    else
        return false;
}

/// <summary>Check if the provided input (passed by reference) date is valid, with year within a specified range & months with 30 or 31 days</summary>
/// <param name="record">The entry stored as record to be evaluated </param>
/// <returns>True is date is valid; False otherwise</returns>
bool IsValidDate(int year, int month, int day)
{
    if (month < 1 || month > 12)
    {
        cout << "Invalid. Re-enter the entire date. Month must be 1 to 12." << endl;
    }

    if (IsLeapYear(year))
    {
        cout << "This is a leap year, hence the month February has 29 days instead of 28." << endl;

        if (month == 2)
        {
            if (day <= 29)
            {
                cout << "Registered date is: " << year << ", Month: " << month << ", Day: " << day << endl;
                return true;
            }
            else
            {
                cout << "Invalid date. February in a leap year has 29 days." << endl;
                return false;
            }
        }
    }

    else
    {
        if (month == 2)
        {
            if (day <= 28)
            {
                cout << "Registered date is: " << year << ", Month: " << month << ", Day: " << day << endl;
                return true;
            }
            else
            {
                cout << "Invalid date. February has 28 days." << endl;
                return false;
            }
        }
    }

    if (month == 4 || month == 6 || month == 9 || month == 11)
    {
        if (day < 31)
        {
            cout << "Backend diary date registered is: " << year << ", Month: " << month << ", Day: " << day << endl;
            // cout << .month << "-" << day << std::endl;
            return true;
        }
        else
        {
            cout << "These months have less than 31 days!" << endl;
            return false;
        }
        // use switch
        return true;
    }

    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
    {
        if (day < 32)
        {
            cout << "User date registered is: " << year << ", Month: " << month << ", Day: " << day << endl;
            // cout << month << "-" << day << std::endl;
            return true;
        }
        else
        {
            cout << "These months have less than 32 days!" << endl;
            return false;
        }

        return true;
    }
}

int main()
{
    // std::cout << "Hello World!\n";

    /// <summary>Solicit inputs from the user and return the data in the form of a DiaryRecord struct</summary>
    /// <returns>The populated DiaryRecord structure from user input</returns>
    cout << "Enter the date to check if it is a leap year in the format, YYYY MM DD seperated by 1 space. e.g: 2024 08 27" << endl;
    int day, month, year;
    cin >> year >> month >> day;
    cout << year << month << day;

    if (IsLeapYear(year))
    {
        cout << endl << year << " is a leap year." << endl;
    }
    else
    {
        cout << year << " is not a leap year." << endl;
    }

    if (IsValidDate(year, month, day))
    {
        cout << "The date is valid." << endl;
        cout << "Registered date! Year: " << year << ", Month: " << month << ", Day: " << day << endl;
    }
    else
    {
        cout << "Invalid date. Please enter date (YYYY MM DD): " << endl;
    }

    return 0;
}
