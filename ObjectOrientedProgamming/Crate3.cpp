/*
Target practise:
-	Based on the previous target practise, management has new requirements:
o	Engineering department has upgraded all crates to be able to handle up to 2 kinds of any material.
o	Upgrade the application to enable the user to specify 1 or 2 materials  for the crate that the customer has requested for.

Restrictions, assumptions:
-	None
*/

// Bootcamp16.1.2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <iostream> // reading and writing to file
#include <vector>
#include <string>
#include <map> // map to store material and colour and to select multiple colours/materials
#include <cstdio> // Include this header for the rename function

using namespace std;

/// <summary>Weight is an integer variable that determiens the size of the create of 3 sizes: Small (800kg) , Medium (1600 kg) and Large (2400 kg), where the value is in kg..</summary>
enum class MineralWeight
{
    SMALL = 800,
    MEDIUM = 1600,
    LARGE = 2400,
    EXTRA_LARGE = 4000,
    EXTRA_EXTRA_LARGE = 8000
};


/// <summary>ContentsType is an integer variable that determines the type of contents stored in the crates: 0=Toxic waste, 1=General waste, Ore=2, Refined Ore = 3.</summary>
//0=Toxic, 1=General, Ore=2, Refined Ore = 3
enum class ContentsType
{
    TOXIC_WASTE,
    GENERAL_WASTE,
    ORE,
    REFINED_ORE
};

/// <summary>Converts the enum value of contents type to a string representation.</summary>
string getContentsTypeAsString(ContentsType type)
{
    switch (type)
    {
        case ContentsType::TOXIC_WASTE:
            return "Toxic Waste";
        case ContentsType::GENERAL_WASTE:
            return "General Waste";
        case ContentsType::ORE:
            return "Ore";
        case ContentsType::REFINED_ORE:
            return "Refined Ore";
        default:
            return "Unknown";
    }
};

/// <summary>Crate class to store all information about the create</summary>
class CrateBaseClass // indicates inheritance but no inheritance
{
    // private: 
public:
    string colour;                // Crate color associated with materials
    MineralWeight Weight;          // Size of the crate based on the enum MineralWeight
    ContentsType contentsType;   // Type of contents stored in the crate based on enum
    int id;                      // Unique identifier for the crate
    // vector<string> materials;    // Up to 3 materials stored in the crate

    
    void CrateColour() const
    {
        // Create a map of strings to string
        //map<string, string> CrateColourMap =
        map<string, string> CrateColourMap =
        {
            {"Iron", "Red"}, {"Maganese", "Green"}, {"Lead", "Blue"} , {"Gold", "Yellow"},
            {"Copper", "Black"}, {"Aluminium", "Pink"}, {"Chromite", "Orange"}, {"Cinnabar", "Grey"},
            {"Beryl", "Silver"}, {"Galena", "Bronze"}, {"Tin", "White"}, {"Malachite", "Violet"},
            {"Uranium", "DarkGreen"}, {"Barite", "Brown"}
        };

        for (const pair<string, string>& pair : CrateColourMap)
        {
            cout << "Material: " << pair.first << ", Colour: " << pair.second << endl;
        }
    }

    /// <summary>
    /// default constructor to instantiate object later
    /// </summary>
    CrateBaseClass() {}

    // public:
        /// <summary>constructor CrateBaseClass to create and store the base variables of a crate</summary>
        /// <param name="colour">Colour of the crate storing the specific stated mineral</param>
        /// <param name="weight">Weight of the mineral</param>
        /// <param name="contentstype"></param>
        /// <param name="id">each crate has a unique ID</param>
    CrateBaseClass(string colour, MineralWeight weight, ContentsType contentstype, int id)
        : colour(colour), Weight(weight), contentsType(contentstype), id(id) {}


    // maybe should be in GUI class
    /// <summary>Function PrintContainerDetails prints the information of the common properties: ClientName, MineralName, Weight, ContentsType</summary>
    virtual void PrintContainerDetails()
    {
        cout << "Colour: " << colour << endl;
        cout << "Weight: " << static_cast<int>(Weight) << " kg" << endl;
        cout << "Mineral contents: " << getContentsTypeAsString(contentsType) << endl;
        cout << "Crate ID: " << id << endl;

    }

    /// <summary>Destructor</summary>
    // ~CrateBaseClass() {}
};

class FileManager
{
public:
    void WriteToFile(const CrateBaseClass& crate)
    {
        ofstream outFile("crates.txt", ios::app);
        if (outFile.is_open())
        {
            outFile << "Crate ID: " << crate.id << endl;
            outFile << "Color: " << crate.colour << endl;
            outFile << "Weight: " << static_cast<int>(crate.Weight) << " kg" << endl;
            outFile << "Contents Type: " << getContentsTypeAsString(crate.contentsType) << endl;
            outFile << "------------------------" << endl;
            outFile.close();
        }
        else {
            cout << "Unable to open file for writing." << endl;
        }
    }

    void ReadFile()
    {
        ifstream inFile("crates.txt");
        string line;
        if (inFile.is_open())
        {
            while (getline(inFile, line))
            {
                cout << line << endl;
            }
            inFile.close();
        }
        else
        {
            cout << "Unable to open file for reading." << endl;
        }
    }

    /// <summary>
    /// delete entry from the file
    /// </summary>
    /// <param name="crateId"></param>
    void DeleteEntry(int crateId)
    {
        ifstream inFile("crates.txt"); // Open the input file in read mode
        ofstream tempFile("temp.txt"); // Open a temporary file in write mode
        string line;
        bool skipLine = false; // Flag to indicate whether to skip writing lines to the temp file
        // flag to control whether the lines should be written to temporary files or not
        // intialise false to allow writing lines be default
        // when crate ID is found, flag will be true to skip lines

        /// Check if both files are open
        if (inFile.is_open() && tempFile.is_open())
        {
            while (getline(inFile, line)) // Read the input file line by line
            {
                // If the line contains the crate ID, set the skip flag to true
                if (line.find("Crate ID: " + to_string(crateId)) != string::npos) // npos is position not found
                {
                    skipLine = true;
                }
                // If skip flag is false, write the line to the temp file
                if (!skipLine)
                {
                    tempFile << line << endl;
                }
                // If the line contains the separator, reset the skip flag to false
                if (line.find("------------------------") != string::npos)
                {
                    skipLine = false;
                }
            }
            inFile.close();
            tempFile.close();
            remove("crates.txt"); // Remove the original file

            const char* oldname = "crates.txt";
            const char* newname = "temp.txt";
            // Attempt to rename the file
            if (rename(oldname, newname) != 0) //  returns 0 if the renaming is successful
            {
                perror("Error renaming file");
            }
            else
            {
                cout << "File rename success" << endl;
            }
            // rename("temp.txt", "crates.txt"); // Rename the temp file to the original file name
        }
        else
        {
            cout << "Unable to open file for deleting entry." << endl;
        }
    }
};

static void UserAddNewCrate()
{
    cout << "Please select how many minerals to store in this crate (1 or 2): " << endl;
    int numberOfMinerals = 0;
    cin >> numberOfMinerals;

    cout << "\nPlease select the index for the mineral you want to store in the crate: " << endl;
    // Check if input is valid
    if (numberOfMinerals < 1 || numberOfMinerals > 2)
    {
        cout << "Invalid number of minerals. Please select either 1 or 2." << endl;
        return;
    }

    // should use maps from base class
    //CrateBaseClass::CrateColour();

    // create an instance of the class
    CrateBaseClass crateBaseClass;
    cout << "Display the crate colours and materails: " << endl;
    crateBaseClass.CrateColour();

    vector<string> minerals =
    {
        "Iron", "Maganese", "Lead", "Gold", "Copper", "Aluminium", "Chromite",
        "Cinnabar", "Cinnabar+Chromite", "Beryl", "Galena", "Tin",
        "Malachite", "Uranium", "Barite", "Lead+Maganese"
    };

    // Display the list of minerals
    for (size_t i = 0; i < minerals.size(); ++i)
    {
        cout << i + 1 << ". " << minerals[i] << endl;  // Fixed index display
    }

    // Store selected mineral IDs
    vector<int> selectedMinerals;
    for (int i = 0; i < numberOfMinerals; ++i)
    {
        int mineralID = 0;
        cout << "Please select mineral " << i + 1 << ": ";
        cin >> mineralID;

        // Validate the mineral selection
        if (mineralID < 1 || mineralID > minerals.size())
        {
            cout << "Invalid mineral selection." << endl;
            return;
        }

        // Add selected mineral to the list
        selectedMinerals.push_back(mineralID);
    }

    // use enum
    cout << "\n1. Small" << endl;
    cout << "2. Medium" << endl;
    cout << "3. Large" << endl;
    cout << "4. Extra Large" << endl;
    cout << "5. Extra Extra Large" << endl;
    cout << "Please enter the size option: ";
    int sizeID = 0;
    cin >> sizeID;

    // Create a new crate
    // CrateBase& newCrate = *CreateCrate(selectedMinerals[0], sizeID);  // Use the first mineral

    // If there is a second mineral, store that information (if needed)
    if (numberOfMinerals == 2)
    {
        // Handle second mineral logic if necessary for your program
        // For example, you might want to add a field to store the second mineral
        cout << "Crate contains two minerals: " << minerals[selectedMinerals[0] - 1]
            << " and " << minerals[selectedMinerals[1] - 1] << endl;
    }

    cout << "\nPlease enter client name: " << endl;
    cin.ignore();  // Clear the newline left in the input stream
    // getline(cin, newCrate.ClientName);

    cout << "\n1. Toxic waste" << endl;
    cout << "2. General waste" << endl;
    cout << "3. Ore" << endl;
    cout << "4. Refined Ore" << endl;
    cout << "Please enter the storage type: " << endl;
    int ContentsType = 0;
    cin >> ContentsType;
    // newCrate.ContentsType = ContentsType - 1;
    cout << endl;

    // Add the crate to the list and save the contents to file
    // ClientRecords.push_back(newCrate);
    // WriteRecordsToFile(ClientRecords);


    return;
}

int main()
{
    std::cout << "Hello World!\n";

    //Continually get user input
    int option;
    cout << "Container Management Program Options" << endl;
    cout << "====================================" << endl;
    cout << "1. View client records" << endl;
    cout << "2. Add client records" << endl;
    cout << "3. Delete client records" << endl;
    cout << "4. Exit" << endl;
    FileManager fileManager; // create an object
    // read up on static functions

    do
    {
        cout << "\nPlease enter your option: ";
        cin >> option;
        cout << endl << endl;

        switch (option)
        {
            case 1: //View client records
                {
                    cout << "Client records" << endl;
                    cout << "--------------" << endl;
                    int Counter = 1;
                    fileManager.ReadFile();
                    
                    // FileManager::ReadFile();
                    cout << endl << endl;
                }
                break;

            case 2: //Add a record
                {
                    UserAddNewCrate();
                }
                break;

            case 3: //Delete client records
                {
                    int recordID = 0;
                    cout << "\nPlease enter record number to delete: " << endl;
                    cin >> recordID;

                    FileManager fileManager; // create an object
                    fileManager.DeleteEntry(recordID);

                    //Delete and save the changes
                    //if (recordID > 0 && recordID <= (int)ClientRecords.size())
                    //{
                    //    ClientRecords.erase(ClientRecords.begin() + recordID - 1);
                    //    WriteRecordsToFile(ClientRecords);
                    //    cout << "Delete successful\n";
                    //}
                    //else
                    //    cout << "Invalid #ID\n";
                }
                break;
        }

        if (option != 4)
        {
            cout << "Container Management Program Options" << endl;
            cout << "====================================" << endl;
            cout << "1. View client records" << endl;
            cout << "2. Add client records" << endl;
            cout << "3. Delete client records" << endl;
            cout << "4. Exit" << endl;
        }

    } while (option != 4);


    cout << endl << endl;
    system("pause");

	return 0;
}


