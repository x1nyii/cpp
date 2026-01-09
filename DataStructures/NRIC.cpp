/*
Target practise #15:
-Develop an application that allows the user to :
  o	Enter in a unique ID (e.g.NRIC) and a name
  o	Retrieve a name based on a given unique ID

Restrictions, assumptions :
-Use a suitable container  to address the above scenario
*/

#include <iostream>
#include <map>

using namespace std;

// map<key_type, value_type> map_name = {{key1, value1},{key2, value2}, ...};

int main()
{
    cout << "Hello World!\n";
    // create a map with integer keys and string values
    map<string, string> idNameMap;
    string userID, name;

    // getline(name)

    int choice;

    while (true) {
        cout << "Menu:\n";
        cout << "1. Enter a your NRIC ID and name. (ID is case sensitive)\n";
        cout << "2. Retrieve a name based on a unique NRIC ID. (ID is case sensitive)\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) 
        {
            case 1: // for user entry
                cout << "Enter unique ID: ";
                cin >> userID;
                cout << "Enter name: ";
                cin >> name;
                idNameMap[userID] = name; // add ID and name to the map
                cout << "Entry added successfully!\n";
                cout << "Entry: " << userID << name << endl;
                break;

            case 2:
                cout << "Enter unique ID: ";
                cin >> userID;
                if (idNameMap.find(userID) != idNameMap.end()) // check if ID exists in the map, standard template for consistency for .find & .end
                    // .find will return an iterator and point to .end if cannot be found, so it is comparing positions and value at that given position
                {
                    cout << "Name: " << idNameMap[userID] << "\n"; // if yes, display the name associated with the ID
                    break;
                }
                else 
                {
                    cout << "ID not found!\n";
                }
                break;

            case 3:
                cout << "Exiting...\n";
                return 0;

            default:

                cout << "Invalid choice! Please try again.\n";
        }
    }

    // list out all the names only if you have integer key provided the keys are in sequence
    //for (int i = 1; i <= idNameMap.size(); ++i) 
    //{
    //    cout << "Name[" << i << "]: " << idNameMap[i] << endl;
    //}

    // declare map iterator to access keys and values of our map
    map<string, string>::iterator iter;

    // use iterator to display map elements
    for (iter = idNameMap.begin(); iter != idNameMap.end(); ++iter) // iter is a component of map class
    {
        cout << iter->first << " - " << iter->second << endl;
    }

    //iter = idNameMap.find(userID);
    return 0;
}
