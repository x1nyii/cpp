Bootcamp Day 4 & 5
1.	Can you show an example of the difference between a constant pointer and a pointer to a constant and when do we use which?

2.	How does pointer arithmetic work and how it interacts with constant pointers?
3.	Declaration of string* ptr creates a pointer variable, when not used in declaration, it acts as a dereference operator, *ptr

string food = “Bread”; // variable declaration
string* ptr = & food // pointer declaration, get the location of the variable food is stored

4.	When should each cast be used? i.e static_cast, dynamic_cast, const_cast, reinterpret_cast
5.	Example on how optional parameters can simplify function overloading
6.	Storing of signed and unsigned integer
a.	Signed integers can hold both positive and negative numbers (& 0)
b.	Int is usually 16 bits
c.	8 bit integer can hold 2^8=256 values between -128 and 127, 1 bit is used to hold the sign
d.	Overflow? Happens when assign positive value to 8 bit signed integer
