/*
Target practise #16.1: 
-	A developer hands over his code to you on his last day of work
-	Required tasks on handover:
    o	Extend the required 4 crates that the company is going to manage:

Colour Code	      Material of Crate Contents
Violet	          Malachite
Dark Green	      Uranium
Brown	            Barite
Blue + Green	    Lead + Maganese

-	Repeated reminders that the current software has been in use for very long by users. Do not change anything that will break the software. “If it ain’t broken, don’t fix it.”

Restrictions, assumptions:
-	None
*/

#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;


//This application allows our Storage Company to provide crates and storage to Ore Companies who are our customers

//1. Customer may own a number of crates, of differing colours.
//2. Crates are specifically tailored to contain Toxic waste, General Waste, Ore, or Refined Ore
//3. A crate colour indicates a specific mineral type (not defined here).
//4. There are 3 sizes for each crate type. Small (800kg) , Medium (1600 kg) and Large (2400 kg)


/// <summary>class CrateBase is the base class for the crates which have common properties: ClientName, MineralName, Weight, ContentsType.</summary>
class CrateBase
{
public:
    /// <summary>ClientName is a string variable that shows the name of the client who owns the crate.</summary>
    string ClientName = "";
    /// <summary>MineralName is a string variable that shows the type/name of mineral stored in the crate.</summary>
    string MineralName = "";
    /// <summary>Weight is an integer variable that determiens the size of the create of 3 sizes: Small (800kg) , Medium (1600 kg) and Large (2400 kg).</summary>
    int Weight = 0;

    /// <summary>ContentsType is an integer variable that determines the type of contents stored in the crates: 0=Toxic waste, 1=General waste, Ore=2, Refined Ore = 3.</summary>
    int ContentsType = 0;   //0=Toxic, 1=General, Ore=2, Refined Ore = 3

    /// <summary>constructor CrateBase to store the base variables of a crate</summary>
    /// <param name="mineralName">Name of the mineral</param>
    /// <param name="weight">Weight of the mineral</param>
    CrateBase(string mineralName, int weight)
    {
        MineralName = mineralName;
        Weight = weight;
    }

    /// <summary>Function PrintContainerDetails prints the information of the common properties: ClientName, MineralName, Weight, ContentsType</summary>
    virtual void PrintContainerDetails()
    {
        cout << "Container Client name: " << ClientName <<
            "\nMineral contents: " << MineralName <<
            "\nWeight: " << Weight << " kg" << endl;

        switch (ContentsType)
        {
            case 0: cout << "Mineral type = Toxic waste" << endl;
                break;
            case 1: cout << "Mineral type = General waste" << endl;
                break;
            case 2: cout << "Mineral type = Ore" << endl;
                break;
            case 3: cout << "Mineral type = Refined Ore" << endl;
                break;
        }
    }
};

//class Crate : public CrateBase
//{
//    public:
//        Crate(string colour, string mineralName, Weight Weight) : CrateBase(mineralName, )
//            cout << "Crate created.\n";
//}

class RedCrateSmall : public CrateBase
{
public:
    RedCrateSmall()
        : CrateBase("Iron", 800) { }
};
class RedCrateMedium : public CrateBase
{
public:
    RedCrateMedium()
        : CrateBase("Iron", 1600) { }
};
class RedCrateLarge : public CrateBase
{
public:
    RedCrateLarge()
        : CrateBase("Iron", 2400) { }
};

class GreenCrateSmall : public CrateBase
{
public:
    GreenCrateSmall()
        : CrateBase("Maganese", 800) { }
};
class GreenCrateMedium : public CrateBase
{
public:
    GreenCrateMedium()
        : CrateBase("Maganese", 1600) { }
};
class GreenCrateLarge : public CrateBase
{
public:
    GreenCrateLarge()
        : CrateBase("Maganese", 2400) { }
};

class BlueCrateSmall : public CrateBase
{
public:
    BlueCrateSmall()
        : CrateBase("Lead", 800) { }
};
class BlueCrateMedium : public CrateBase
{
public:
    BlueCrateMedium()
        : CrateBase("Lead", 1600) { }
};
class BlueCrateLarge : public CrateBase
{
public:
    BlueCrateLarge()
        : CrateBase("Lead", 2400) { }
};

class YellowCrateSmall : public CrateBase
{
public:
    YellowCrateSmall()
        : CrateBase("Gold", 800) { }
};
class YellowCrateMedium : public CrateBase
{
public:
    YellowCrateMedium()
        : CrateBase("Gold", 1600) { }
};
class YellowCrateLarge : public CrateBase
{
public:
    YellowCrateLarge()
        : CrateBase("Gold", 2400) { }
};

class BlackCrateSmall : public CrateBase
{
public:
    BlackCrateSmall()
        : CrateBase("Copper", 800) { }
};
class BlackCrateMedium : public CrateBase
{
public:
    BlackCrateMedium()
        : CrateBase("Copper", 1600) { }
};
class BlackCrateLarge : public CrateBase
{
public:
    BlackCrateLarge()
        : CrateBase("Copper", 2400) { }
};

class PinkCrateSmall : public CrateBase
{
public:
    PinkCrateSmall()
        : CrateBase("Aluminium", 800) { }
};
class PinkCrateMedium : public CrateBase
{
public:
    PinkCrateMedium()
        : CrateBase("Aluminium", 1600) { }
};
class PinkCrateLarge : public CrateBase
{
public:
    PinkCrateLarge()
        : CrateBase("Aluminium", 2400) { }
};

class OrangeCrateSmall : public CrateBase
{
public:
    OrangeCrateSmall()
        : CrateBase("Chromite", 800) { }
};
class OrangeCrateMedium : public CrateBase
{
public:
    OrangeCrateMedium()
        : CrateBase("Chromite", 1600) { }
};
class OrangeCrateLarge : public CrateBase
{
public:
    OrangeCrateLarge()
        : CrateBase("Chromite", 2400) { }
};

class GreyCrateSmall :public CrateBase
{
public:
    GreyCrateSmall()
        : CrateBase("Cinnabar", 800) { }
};
class GreyCrateMedium : public CrateBase
{
public:
    GreyCrateMedium()
        : CrateBase("Cinnabar", 1600) { }
};
class GreyCrateLarge : public CrateBase
{
public:
    GreyCrateLarge()
        : CrateBase("Cinnabar", 2400) { }
};



//14 May 2015: New crate type added that can handle two half-loads of cinnabar and chromite
class GreyOrangeCrateSmall : public CrateBase
{
public:
    GreyOrangeCrateSmall()
        : CrateBase("Cinnabar+Chromite", 800) { }

    void PrintContainerDetails() override
    {
        cout << "Container Client name: " + ClientName + ", mineral contents: Cinnabar and Chromite, weight: " << Weight << " kg" << endl;
        switch (ContentsType)
        {
            case 0: cout << ", Mineral type = Toxic waste" << endl;
                break;
            case 1: cout << ", Mineral type = General waste" << endl;
                break;
            case 2: cout << ", Mineral type = Ore" << endl;
                break;
            case 3: cout << ", Mineral type = Refined Ore" << endl;
                break;
        }
    }
};
class GreyOrangeCrateMedium : public CrateBase
{
public:
    GreyOrangeCrateMedium()
        : CrateBase("Cinnabar+Chromite", 1600) { }

    void PrintContainerDetails() override
    {
        cout << "Container Client name: " << ClientName << ", mineral contents: Cinnabar and Chromite, weight: " << Weight << " kg" << endl;
        switch (ContentsType)
        {
            case 0: cout << ", Mineral type = Toxic waste" << endl;
                break;
            case 1: cout << ", Mineral type = General waste" << endl;
                break;
            case 2: cout << ", Mineral type = Ore" << endl;
                break;
            case 3: cout << ", Mineral type = Refined Ore" << endl;
                break;
        }
    }
};
class GreyOrangeCrateLarge : public CrateBase
{
public:
    GreyOrangeCrateLarge()
        : CrateBase("Cinnabar+Chromite", 2400) { }

    void PrintContainerDetails() override
    {
        cout << "Container Client name: " << ClientName << ", mineral contents: Cinnabar and Chromite, weight: " << Weight << " kg" << endl;
        switch (ContentsType)
        {
            case 0: cout << ", Mineral type = Toxic waste" << endl;
                break;
            case 1: cout << ", Mineral type = General waste" << endl;
                break;
            case 2: cout << ", Mineral type = Ore" << endl;
                break;
            case 3: cout << ", Mineral type = Refined Ore" << endl;
                break;
        }
    }
};


//7 July 2015: Added new crate types for new materials supported
class SilverCrateSmall : public CrateBase
{
public:
    SilverCrateSmall()
        : CrateBase("Beryl", 800) { }
};
class SilverCrateMedium : public CrateBase
{
public:
    SilverCrateMedium()
        : CrateBase("Beryl", 1600) { }
};
class SilverCrateLarge : public CrateBase
{
public:
    SilverCrateLarge()
        : CrateBase("Beryl", 2400) { }
};

class BronzeCrateSmall : public CrateBase
{
public:
    BronzeCrateSmall()
        : CrateBase("Galena", 800) { }
};
class BronzeCrateMedium : public CrateBase
{
public:
    BronzeCrateMedium()
        : CrateBase("Galena", 1600) { }
};
class BronzeCrateLarge : public CrateBase
{
public:
    BronzeCrateLarge()
        : CrateBase("Galena", 2400) { }
};

class WhiteCrateSmall : public CrateBase
{
public:
    WhiteCrateSmall()
        : CrateBase("Tin", 800) { }
};
class WhiteCrateMedium : public CrateBase
{
public:
    WhiteCrateMedium()
        : CrateBase("Tin", 1600) { }
};
class WhiteCrateLarge : public CrateBase
{
public:
    WhiteCrateLarge()
        : CrateBase("Tin", 2400) { }
};

//Work in progress...
//Violet: Malachite
// 
// adding violet colour
class VioletCrateSmall :public CrateBase
{
public:
    VioletCrateSmall()
        : CrateBase("Malachite", 800) { }
};
class VioletCrateMedium : public CrateBase
{
public:
    VioletCrateMedium()
        : CrateBase("Malachite", 1600) { }
};
class VioletCrateLarge : public CrateBase
{
public:
    VioletCrateLarge()
        : CrateBase("Malachite", 2400) { }
};

// adding dark green colour
//DarkGreen: Uranium
class DarkGreenCrateSmall :public CrateBase
{
public:
    DarkGreenCrateSmall()
        : CrateBase("Uranium", 800) { }
};
class DarkGreenCrateMedium : public CrateBase
{
public:
    DarkGreenCrateMedium()
        : CrateBase("Uranium", 1600) { }
};
class DarkGreenCrateLarge : public CrateBase
{
public:
    DarkGreenCrateLarge()
        : CrateBase("Uranium", 2400) { }
};

// adding brown colour
//Brown: Barite
class BrownCrateSmall :public CrateBase
{
public:
    BrownCrateSmall()
        : CrateBase("Barite", 800) { }
};
class BrownCrateMedium : public CrateBase
{
public:
    BrownCrateMedium()
        : CrateBase("Barite", 1600) { }
};
class BrownCrateLarge : public CrateBase
{
public:
    BrownCrateLarge()
        : CrateBase("Barite", 2400) { }
};


//Lead + Maganese crates
// create blue + green for Lead + Maganese
class BlueGreenCrateSmall : public CrateBase
{
public:
    BlueGreenCrateSmall()
        : CrateBase("Lead+Maganese", 800) { }

    void PrintContainerDetails() override
    {
        cout << "Container Client name: " + ClientName + ", mineral contents: Lead and Maganese, weight: " << Weight << " kg" << endl;
        switch (ContentsType)
        {
            case 0: cout << ", Mineral type = Toxic waste" << endl;
                break;
            case 1: cout << ", Mineral type = General waste" << endl;
                break;
            case 2: cout << ", Mineral type = Ore" << endl;
                break;
            case 3: cout << ", Mineral type = Refined Ore" << endl;
                break;
        }
    }
};
class BlueGreenCrateMedium : public CrateBase
{
public:
    BlueGreenCrateMedium()
        : CrateBase("Lead+Maganese", 1600) { }

    void PrintContainerDetails() override
    {
        cout << "Container Client name: " << ClientName << ", mineral contents: Lead and Maganese, weight: " << Weight << " kg" << endl;
        switch (ContentsType)
        {
            case 0: cout << ", Mineral type = Toxic waste" << endl;
                break;
            case 1: cout << ", Mineral type = General waste" << endl;
                break;
            case 2: cout << ", Mineral type = Ore" << endl;
                break;
            case 3: cout << ", Mineral type = Refined Ore" << endl;
                break;
        }
    }
};
class BlueGreenCrateLarge : public CrateBase
{
public:
    BlueGreenCrateLarge()
        : CrateBase("Lead+Maganese", 2400) { }

    void PrintContainerDetails() override
    {
        cout << "Container Client name: " << ClientName << ", mineral contents: Lead and Maganese, weight: " << Weight << " kg" << endl;
        switch (ContentsType)
        {
            case 0: cout << ", Mineral type = Toxic waste" << endl;
                break;
            case 1: cout << ", Mineral type = General waste" << endl;
                break;
            case 2: cout << ", Mineral type = Ore" << endl;
                break;
            case 3: cout << ", Mineral type = Refined Ore" << endl;
                break;
        }
    }
};

//Write a string array to file, line by line
void FileWriteAllLines(string filename, vector<string> contents)
{
    ofstream file(filename);
    for (string& entry : contents)
        file << entry << endl;
    file.close();
}

//Read string array from file, line by line
vector<string> FileReadAllLines(string filename)
{
    vector<string> lines;
    ifstream file(filename);
    string entry;

    //Read all entries, line by line
    while (getline(file, entry))
        lines.push_back(entry);

    return lines;
}


//Function to check for existence of a file
bool IsFileExist(const std::string& name)
{
    ifstream file(name.c_str());
    return file.good();
}


//Read all client records from file
vector<CrateBase> ReadRecordsFromFile()
{
    vector<CrateBase> CrateList;

    if (IsFileExist("records.dat"))
    {
        vector<string> lines = FileReadAllLines("records.dat");

        //Parse the contents
        //4 lines per record
        for (size_t i = 0; i < lines.size(); i += 4)
        {
            CrateBase* newCrate = nullptr;
            int weight;

            if (lines[i].compare("Red") == 0)
            {
                switch (weight = stoi(lines[i + 1]))
                {
                    case 800: newCrate = new RedCrateSmall(); break;
                    case 1600: newCrate = new RedCrateMedium(); break;
                    case 2400: newCrate = new RedCrateLarge(); break;
                }
            }
            else if (lines[i].compare("Green") == 0)
            {
                switch (weight = stoi(lines[i + 1]))
                {
                    case 800: newCrate = new GreenCrateSmall(); break;
                    case 1600: newCrate = new GreenCrateMedium(); break;
                    case 2400: newCrate = new GreenCrateLarge(); break;
                }
            }
            else if (lines[i].compare("Blue") == 0)
            {
                switch (weight = stoi(lines[i + 1]))
                {
                    case 800: newCrate = new BlueCrateSmall(); break;
                    case 1600: newCrate = new BlueCrateMedium(); break;
                    case 2400: newCrate = new BlueCrateLarge(); break;
                }
            }
            else if (lines[i].compare("Yellow") == 0)
            {
                switch (weight = stoi(lines[i + 1]))
                {
                    case 800: newCrate = new YellowCrateSmall(); break;
                    case 1600: newCrate = new YellowCrateMedium(); break;
                    case 2400: newCrate = new YellowCrateLarge(); break;
                }
            }
            else if (lines[i].compare("Black") == 0)
            {
                switch (weight = stoi(lines[i + 1]))
                {
                    case 800: newCrate = new BlackCrateSmall(); break;
                    case 1600: newCrate = new BlackCrateMedium(); break;
                    case 2400: newCrate = new BlackCrateLarge(); break;
                }
            }
            else if (lines[i].compare("Pink") == 0)
            {
                switch (weight = stoi(lines[i + 1]))
                {
                    case 800: newCrate = new PinkCrateSmall(); break;
                    case 1600: newCrate = new PinkCrateMedium(); break;
                    case 2400: newCrate = new PinkCrateLarge(); break;
                }
            }
            else if (lines[i].compare("Orange") == 0)
            {
                switch (weight = stoi(lines[i + 1]))
                {
                    case 800: newCrate = new OrangeCrateSmall(); break;
                    case 1600: newCrate = new OrangeCrateMedium(); break;
                    case 2400: newCrate = new OrangeCrateLarge(); break;
                }
            }
            else if (lines[i].compare("Grey") == 0)
            {
                switch (weight = stoi(lines[i + 1]))
                {
                    case 800: newCrate = new GreyCrateSmall(); break;
                    case 1600: newCrate = new GreyCrateMedium(); break;
                    case 2400: newCrate = new GreyCrateLarge(); break;
                }
            }
            else if (lines[i].compare("GreyOrange") == 0)
            {
                switch (weight = stoi(lines[i + 1]))
                {
                    case 800: newCrate = new GreyOrangeCrateSmall(); break;
                    case 1600: newCrate = new GreyOrangeCrateMedium(); break;
                    case 2400: newCrate = new GreyOrangeCrateLarge(); break;
                }
            }
            else if (lines[i].compare("Silver") == 0)
            {
                switch (weight = stoi(lines[i + 1]))
                {
                    case 800: newCrate = new SilverCrateSmall(); break;
                    case 1600: newCrate = new SilverCrateMedium(); break;
                    case 2400: newCrate = new SilverCrateLarge(); break;
                }
            }
            else if (lines[i].compare("Bronze") == 0)
            {
                switch (weight = stoi(lines[i + 1]))
                {
                    case 800: newCrate = new BronzeCrateSmall(); break;
                    case 1600: newCrate = new BronzeCrateMedium(); break;
                    case 2400: newCrate = new BronzeCrateLarge(); break;
                }
            }
            else if (lines[i].compare("White") == 0)
            {
                switch (weight = stoi(lines[i + 1]))
                {
                    case 800: newCrate = new WhiteCrateSmall(); break;
                    case 1600: newCrate = new WhiteCrateMedium(); break;
                    case 2400: newCrate = new WhiteCrateLarge(); break;
                }
            }

            /// new ///
            // new violet colour
            else if (lines[i].compare("Violet") == 0)
            {
                switch (weight = stoi(lines[i + 1]))
                {
                    case 800: newCrate = new VioletCrateSmall(); break;
                    case 1600: newCrate = new VioletCrateMedium(); break;
                    case 2400: newCrate = new VioletCrateLarge(); break;
                }
            }
            // new dark green colour
            else if (lines[i].compare("DarkGreen") == 0)
            {
                switch (weight = stoi(lines[i + 1]))
                {
                    case 800: newCrate = new DarkGreenCrateSmall(); break;
                    case 1600: newCrate = new DarkGreenCrateMedium(); break;
                    case 2400: newCrate = new DarkGreenCrateLarge(); break;
                }
            }
            // new brown colour
            else if (lines[i].compare("Brown") == 0)
            {
                switch (weight = stoi(lines[i + 1]))
                {
                    case 800: newCrate = new BrownCrateSmall(); break;
                    case 1600: newCrate = new BrownCrateMedium(); break;
                    case 2400: newCrate = new BrownCrateLarge(); break;
                }
            }

            // new blue + green colour
            // new brown colour
            else if (lines[i].compare("BlueGreen") == 0)
            {
                switch (weight = stoi(lines[i + 1]))
                {
                    case 800: newCrate = new BlueGreenCrateSmall(); break;
                    case 1600: newCrate = new BlueGreenCrateMedium(); break;
                    case 2400: newCrate = new BlueGreenCrateLarge(); break;
                }
            }


            //Only add valid items to the crate
            if (newCrate != nullptr)
            {
                //Read the client name
                newCrate->ClientName = lines[i + 2];

                //Read the contents type
                newCrate->ContentsType = stoi(lines[i + 3]);

                //Compile the crate to the list
                CrateList.push_back(*newCrate);
            }
        }
    }

    return CrateList;
}

//Write all client records to file
void WriteRecordsToFile(vector<CrateBase> CrateList)
{
    vector<string> contents;

    for (CrateBase& crate : CrateList)
    {
        //Write crate colour
        if (crate.MineralName.compare("Iron") == 0)
            contents.push_back("Red");
        else if (crate.MineralName.compare("Maganese") == 0)
            contents.push_back("Green");
        else if (crate.MineralName.compare("Lead") == 0)
            contents.push_back("Blue");
        else if (crate.MineralName.compare("Gold") == 0)
            contents.push_back("Yellow");
        else if (crate.MineralName.compare("Copper") == 0)
            contents.push_back("Black");
        else if (crate.MineralName.compare("Aluminium") == 0)
            contents.push_back("Pink");
        else if (crate.MineralName.compare("Chromite") == 0)
            contents.push_back("Orange");
        else if (crate.MineralName.compare("Cinnabar") == 0)
            contents.push_back("Grey");
        else if (crate.MineralName.compare("Cinnabar+Chromite") == 0)
            contents.push_back("GreyOrange");
        else if (crate.MineralName.compare("Beryl") == 0)
            contents.push_back("Silver");
        else if (crate.MineralName.compare("Galena") == 0)
            contents.push_back("Bronze");
        else if (crate.MineralName.compare("Tin") == 0)
            contents.push_back("White");

        // new added colours
        // add violet
        else if (crate.MineralName.compare("Malachite") == 0)
            contents.push_back("Violet");
        // add  dark green
        else if (crate.MineralName.compare("Uranium") == 0)
            contents.push_back("DarkGreen");
        // add brown
        else if (crate.MineralName.compare("Barite") == 0)
            contents.push_back("Brown");
        // add blue + green
        else if (crate.MineralName.compare("Lead+Maganese") == 0)
            contents.push_back("BlueGreen");


        //Write crate weight
        contents.push_back(to_string(crate.Weight));

        //Write crate client name
        contents.push_back(crate.ClientName);

        //Write crate contents type
        contents.push_back(to_string(crate.ContentsType));
    }

    //Write contents to file
    FileWriteAllLines("records.dat", contents);
}


//Function to create a crate from mineral ID and crate size
CrateBase* CreateCrate(int mineralID, int sizeID)
{
    CrateBase* newCrate = nullptr;
    switch (mineralID)
    {
        case 1:
            switch (sizeID)
            {
                case 1: newCrate = new RedCrateSmall(); break;
                case 2: newCrate = new RedCrateMedium(); break;
                case 3: newCrate = new RedCrateLarge(); break;
            }
            break;
        case 2:
            switch (sizeID)
            {
                case 1: newCrate = new GreenCrateSmall(); break;
                case 2: newCrate = new GreenCrateMedium(); break;
                case 3: newCrate = new GreenCrateLarge(); break;
            }
            break;
        case 3:
            switch (sizeID)
            {
                case 1: newCrate = new BlueCrateSmall(); break;
                case 2: newCrate = new BlueCrateMedium(); break;
                case 3: newCrate = new BlueCrateLarge(); break;
            }
            break;
        case 4:
            switch (sizeID)
            {
                case 1: newCrate = new YellowCrateSmall(); break;
                case 2: newCrate = new YellowCrateMedium(); break;
                case 3: newCrate = new YellowCrateLarge(); break;
            }
            break;
        case 5:
            switch (sizeID)
            {
                case 1: newCrate = new BlackCrateSmall(); break;
                case 2: newCrate = new BlackCrateMedium(); break;
                case 3: newCrate = new BlackCrateLarge(); break;
            }
            break;
        case 6:
            switch (sizeID)
            {
                case 1: newCrate = new PinkCrateSmall(); break;
                case 2: newCrate = new PinkCrateMedium(); break;
                case 3: newCrate = new PinkCrateLarge(); break;
            }
            break;
        case 7:
            switch (sizeID)
            {
                case 1: newCrate = new OrangeCrateSmall(); break;
                case 2: newCrate = new OrangeCrateMedium(); break;
                case 3: newCrate = new OrangeCrateLarge(); break;
            }
            break;
        case 8:
            switch (sizeID)
            {
                case 1: newCrate = new GreyCrateSmall(); break;
                case 2: newCrate = new GreyCrateMedium(); break;
                case 3: newCrate = new GreyCrateLarge(); break;
            }
            break;
        case 9:
            switch (sizeID)
            {
                case 1: newCrate = new GreyOrangeCrateSmall(); break;
                case 2: newCrate = new GreyOrangeCrateMedium(); break;
                case 3: newCrate = new GreyOrangeCrateLarge(); break;
            }
            break;
        case 10:
            switch (sizeID)
            {
                case 1: newCrate = new SilverCrateSmall(); break;
                case 2: newCrate = new SilverCrateMedium(); break;
                case 3: newCrate = new SilverCrateLarge(); break;
            }
            break;
        case 11:
            switch (sizeID)
            {
                case 1: newCrate = new BronzeCrateSmall(); break;
                case 2: newCrate = new BronzeCrateMedium(); break;
                case 3: newCrate = new BronzeCrateLarge(); break;
            }
            break;
        case 12:
            switch (sizeID)
            {
                case 1: newCrate = new WhiteCrateSmall(); break;
                case 2: newCrate = new WhiteCrateMedium(); break;
                case 3: newCrate = new WhiteCrateLarge(); break;
            }
            break;

            // add new colour creates
            // add violet
        case 13:
            switch (sizeID)
            {
                case 1: newCrate = new VioletCrateSmall(); break;
                case 2: newCrate = new VioletCrateMedium(); break;
                case 3: newCrate = new VioletCrateLarge(); break;
            }
            break;

            // add dark green
        case 14:
            switch (sizeID)
            {
                case 1: newCrate = new DarkGreenCrateSmall(); break;
                case 2: newCrate = new DarkGreenCrateMedium(); break;
                case 3: newCrate = new DarkGreenCrateLarge(); break;
            }
            break;

            // add brown
        case 15:
            switch (sizeID)
            {
                case 1: newCrate = new BrownCrateSmall(); break;
                case 2: newCrate = new BrownCrateMedium(); break;
                case 3: newCrate = new BrownCrateLarge(); break;
            }
            break;

            // add blue + green
        case 16:
            switch (sizeID)
            {
                case 1: newCrate = new BlueGreenCrateSmall(); break;
                case 2: newCrate = new BlueGreenCrateMedium(); break;
                case 3: newCrate = new BlueGreenCrateLarge(); break;
            }
            break;

    }

    return newCrate;
}




//Main program body to manage client records
int main()
{
    //Read in records from file to ram into a vector of cratebase
    vector<CrateBase> ClientRecords = ReadRecordsFromFile();


    //Continually get user input
    int option;
    cout << "Container Management Program Options" << endl;
    cout << "====================================" << endl;
    cout << "1. View client records" << endl;
    cout << "2. Add client records" << endl;
    cout << "3. Delete client records" << endl;
    cout << "4. Exit" << endl;

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
                    for (CrateBase& record : ClientRecords)
                    {
                        cout << "#" << Counter++ << endl;
                        record.PrintContainerDetails();
                    }
                    cout << endl << endl;
                }
                break;

            case 2: //Add a record
                {
                    cout << "\n1.  Iron" << endl;
                    cout << "2.  Maganese" << endl;
                    cout << "3.  Lead" << endl;
                    cout << "4.  Gold" << endl;
                    cout << "5.  Copper" << endl;
                    cout << "6.  Aluminium" << endl;
                    cout << "7.  Chromite" << endl;
                    cout << "8.  Cinnabar" << endl;
                    cout << "9.  Cinnabar+Chromite" << endl;
                    cout << "10. Beryl" << endl;
                    cout << "11. Galena" << endl;
                    cout << "12. Tin" << endl;
                    // add new colour
                    cout << "13. Malachite" << endl;
                    cout << "14. Uranium" << endl;
                    cout << "15. Barite" << endl;
                    cout << "16. Lead+Maganese" << endl;

                    cout << "Please select the mineral option: " << endl;
                    int mineralID = 0;
                    cin >> mineralID;

                    cout << "\n1. Small" << endl;
                    cout << "2. Medium" << endl;
                    cout << "3. Large" << endl;
                    cout << "Please enter the size option: ";
                    int sizeID = 0;
                    cin >> sizeID;

                    //Create a new crate
                    CrateBase& newCrate = *CreateCrate(mineralID, sizeID);

                    cout << "\nPlease enter client name: " << endl;
                    cin.ignore();
                    getline(cin, newCrate.ClientName);

                    cout << "\n1. Toxic waste" << endl;
                    cout << "2. General waste" << endl;
                    cout << "3. Ore" << endl;
                    cout << "4. Refined Ore" << endl;
                    cout << "Please enter the storage type: " << endl;
                    int ContentsType = 0;
                    cin >> ContentsType;
                    newCrate.ContentsType = ContentsType - 1;
                    cout << endl;

                    //Add the crate to the list and save the contents to file
                    ClientRecords.push_back(newCrate); // add new record to vector
                    WriteRecordsToFile(ClientRecords); // write the whole vector to file
                }
                break;

            case 3: //Delete client records
                {
                    int recordID = 0;
                    cout << "\nPlease enter record number to delete: " << endl;
                    cin >> recordID;

                    //Delete and save the changes
                    if (recordID > 0 && recordID <= (int)ClientRecords.size())
                    {
                        ClientRecords.erase(ClientRecords.begin() + recordID - 1);
                        WriteRecordsToFile(ClientRecords); // from ram write to file (save all changes to file) but still keep old records in vector in ram, did not clear vector
                        // copy whole vector to file

                        cout << "Delete successful\n";
                    }
                    else
                        cout << "Invalid #ID\n";
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

