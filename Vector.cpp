/*
Target practise 2:
-	Develop an application that allows the user to set and read values from a 3-D space of 50 x 50 x 50 elements
  o	User is allowed to ether read, set or search a value
  o	For reading:
    >	User to key in x, y and z addresses and the stored value will be printed out
  o	For writing:
    >	User to key in x, y and z addresses and the value to be stored
  o	For searching:
    >	User to key in a value to be searched, and the address of the first instance found, if any, will be printed out

Restrictions, assumptions:
-	The result does not need to persist to disk
-	x, y, z are numbers
-	Input is always correct
*/

// 3D array practise
/* User to set, read & search values from 50x50x50 elements
1. Reading: key in x, y, z addresses and print stored value
2. Writing: key in x, y, z addresses and the value to be stored, then update the array w new value, print
3. Searching: key in a value to be searched, and the address of 1st instance found, if any, will be printed
4. Exit application

Idea: use switches to determine which actions to perform
*/

int main
{
  int array[50][50][50] = {};
  int choice, x, y, z, value;

  bool isalive = true;
  while (isalive) 
  {
  	cout << "Which action do you want to perform? Key in 1, 2, 3 or 4. \n";
  	cout << "1. Get value\n";
  	cout << "2. Set value\n";
  	cout << "3. Search value\n";
  	cout << "4. Exit\n";
  	cin >> choice;

  	switch (choice)
  	{
  	case 1:
  		cout << "Enter the x, y, z co-ordinates between 0 to 49 to get the value: \n";
  		cin >> x >> y >> z;
  		// if co-ord is correct, print the value 
	  	// else, re-enter
	  	if (x >= 0 && x < 50 && y >= 0 && y < 50 && z >= 0 && z < 50)
	  	{
	  		cout << "Value at address : " << x << "," << y << ", " << z << " is " << array[x][y][z] << ".\n";
	  	}
	  	else
	  	{
	  		cout << "Invalid address, please re-enter within value range. \n";
  		}
	  	break;

  	case 2:
	  	cout << "Enter the x, y, z co-ordinates between 0 to 49 to store the value: \n";
	  	cin >> x >> y >> z >> value;

  		cout << "The current value is: " << array[x][y][z] << endl;

	  	if (x >= 0 && x < 50 && y >= 0 && y < 50 && z >= 0 && z < 50)
  		{
		  	array[x][y][z] = value;
	  		cout << "Updated value at address : " << x << "," << y << ", " << z << " is " << array[x][y][z] << ".\n";
	  	}
	  	else
		  {
			  cout << "Invalid address, please re-enter within value range. \n";
		  }
		  break;
  	case 3:
	  {
  		int searchValue = 0;
	  	std::cin >> searchValue;
  		bool isFound = false;
	  	// output each element's value

	  	for (int i = 0; i < 50; ++i)
	  	{
		  	for (int j = 0; j < 50; ++j)
		  	{
  				for (int k = 0; k < 50; ++k)
		  		{
			  		if (array[i][j][k] == searchValue)
			  		{
			  			cout << "Value found: " << array[i][j][k] << endl;
			  			cout << "Address of value: " << i << ", " << j << ", " << k << endl;
			  			// return, will break out of the app
			  			// dont use go to although its convi
		  				// goto exitLoop;
			  			isFound = true;
		  				break;
			  		}

				  	// int a = 10 * i + (j + 1);
			  		// cout << "Element at array[%i][%i][%i] = %d\n", i, j, k, array[i][j][k];
		  			// array[i][j][k] = (some_value);

		  		}
		  		// cout << endl;
		  		if (isFound == true)
		  		{
		  			break;
		  		}

		  	}
		  	// cout << endl;
		  	if (isFound == true)
		  	{
			  	break;
		  	}
	  	}
	  	if (isFound == false)
	  	{
		  	cout << "Invalid address, please re-enter within value range. \n";
	  	}
	  	// exitLoop:
  	}
  	break;
	  case 4:
	  	isalive = false;
	  	break;

	  default:
	  	std::cout << "Invalid entry, please re-enter.\n";
  	}
  }

  return 0;
}
