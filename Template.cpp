/*
Target practise #9: 
-	Develop a template function that computes the sum of an array.
  o	support for primitive data types (e.g. char, short, double… etc)

Restrictions, assumptions:
-	None
*/

#include <iostream>

using namespace std;

template <typename T>
T sum(T num1, T num2)
{
    return (num1 + num2);
}

//Template class
template <typename T>
//sort prototype
void SumOfArray(int n, T a[])
{
    T sumArray[] = a[];
    // declare seperately

    int addition = 0;
    for (int i = 0; i < 5; ++i)
    {
        cout << sumArray[i] << endl;
        addition += sumArray[i];
        // cout << addition << endl;

    }

    cout << "The sum is: " << addition << endl;
}


int main()
{
    int resultInt;
    double resultdouble;
    float resultfloat;

    int sumArray[10]{ 1,2,3,4,5 };
    // declare seperately

    int addition = 0;
    for (int i = 0; i < 5; ++i)
    {
        cout << sumArray[i] << endl;
        addition += sumArray[i];
        // cout << addition << endl;
    }

    cout << "The sum is: " << addition << endl;

    //int num1, num2;
    //float num1, num2; // 6 or 7 d.p
    //double num1, num2; // 14-15 d.p

    //// calling with int parameters
    //resultInt = sum<int>(num1, num2);
    //cout << "Sum= " << resultInt << endl;

    //
    //// calling with float parameters
    //resultfloat = sum<float>(num1, num2);
    //cout << "Sum= " << resultfloat << endl;
    //
    //// calling with double parameters
    //resultdouble = sum<double>(num1, num2);
    //cout << "Sum= " << resultdouble << endl;

    int sumArray[10]{ 1,2,3,4,5 };
    // declare seperately

    int addition = 0;
    for (int i = 0; i < 5; ++i)
    {
        cout << sumArray[i] << endl;
        addition += sumArray[i];
        // cout << addition << endl;
    }

    cout << "The sum is: " << addition << endl;

    std::cout << "Hello World!\n";
}

