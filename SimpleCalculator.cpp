/*
  Target practise #7:
-	Ask the user for two numbers
-	Ask the user for an operation: plus, minus, multiplication, division, power
-	Return a result depending on the user input

Restrictions, assumptions:
-	Define 5 separate functions for plus, minus, multiplication, division, power
-	Use a function pointer/delegate and assign to it the correct function, before execution; do not call the function directly
*/

#include <iostream>
#include <limits>
#include <cmath>

using namespace std;

// Function for userinput
void userInputs(double& firstInputNumber, double& secondInputNumber, char& operatorInput)
{
    // ask user for 2 numbers
    // ask user for an operation
    std::cout << "Hello! Welcome to basic calculator. You have to enter 2 numbers and an operator.\n";
    cout << "Enter the first number: " << endl;

    // does not except a decimal number...

    while (!(cin >> firstInputNumber))
    {
        cin.clear();
        // Discards invalid input, but stops the whole function
        cin.ignore(numeric_limits < streamsize > ::max(), '\n');
        cout << "Error. Enter a number! Please re-enter the first number." << endl;
    }
    cout << "Success! First number registered: " << firstInputNumber << endl;
    cout << "Enter the second number:  " << endl;

    while (!(cin >> secondInputNumber))
    {
        cin.clear();
        // Discards invalid input, but stops the whole function
        cin.ignore(numeric_limits < streamsize > ::max(), '\n');
        cout << "Error. Enter a number! Please re-enter the second number." << endl;
    }
    cout << "Success! Second number registered: " << secondInputNumber << endl;
    cout << "Please enter a math operation, either + or - or * or / or ^." << endl;

    while (true)
    {
        cin >> operatorInput;
        if (operatorInput == '+' || operatorInput == '-' || operatorInput == '*' || operatorInput == '/' || operatorInput == '^')
        {
            break;
        }
        else
        {
            cin.clear();
            // Discards invalid input, but stops the whole function
            cin.ignore(numeric_limits < streamsize > ::max(), '\n');
            cout << "Invalid operation. Please re-enter a math operation: + or - or * or / or ^." << endl;
        }
    }
    cout << "Registered. You entered: " << operatorInput << endl;
}

// function declarations
// how to use the user input as a variable of a function

//int sumFunction(int firstInputNumber, int secondInputNumber)
//{
//    return firstInputNumber + secondInputNumber;
//}

double addFunction(double a, double b) 
{
    return a + b;
}

double subtractFunction(double a, double b) 
{
    return a - b;
}

double multiplyFunction(double a, double b) 
{
    return a * b;
}

double divideFunction(double a, double b) 
{
    if (b != 0) {
        return a / b;
    }
    else {
        cerr << "Error: Division by zero!" << std::endl;
        return 0;
    }
}

double powerFunction(double a, double b) {
    return std::pow(a, b);
}


int main()
{
    double firstNumber, secondNumber;
    char operatorInput;

    // get inputs from user
    userInputs(firstNumber, secondNumber, operatorInput);
    // pass the variables by reference
    // any changes made inside userInputs will be reflected in main

    // create pointer
    double (*operationFunction)(double, double) = nullptr;

    // use a function pointer and assign it to the correct function before execution
    // do not call the function directly

    // do a switch for each operator input
    // pointer exist in the switch for corresponding operator

    // double firstInputNumber, secondInputNumber;
    // char operatorInput;

    switch (operatorInput)
    {
        // pointer is called operationFunction
        // pointer points to the respective operation functions
        case '+':
            operationFunction = addFunction;
            break;
        case '-':
            operationFunction = subtractFunction;
            break;
        case '*':
            operationFunction = multiplyFunction;
            break;
        case '/':
            operationFunction = divideFunction;
            break;
        case '^':
            operationFunction = powerFunction;
            break;
        // no need default as i have already forced user input to be correct
    }
    // double result;
    double result = operationFunction(firstNumber, secondNumber);
    // if want to call directly from function, it will be userInputs(firstInputNumber)?
    cout << "Result: " << result << endl;
    
    return 0;
}
