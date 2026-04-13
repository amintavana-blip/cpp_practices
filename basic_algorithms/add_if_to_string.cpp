// Write a C++ program to create a string where 'if' is added to the front of a given string. If the string already begins with 'if', return the string unchanged.
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string test(string s)
{
    if (s.length() > 2 && s.substr(0, 2) == "if")
        return s;

    else
    {

        return "if " + s;
    }
}

int main()
{
    cout << "Start of add_if_to_string.cpp\n"
         << endl;

    cout << test("if else") << endl;  // Output the result of test function with argument "if else"
    cout << test("else") << endl;    // Output the result of test function with argument "else"

    return 0;
}

// Sample Input:
// "if else"
// "else"
// Sample Output:
// if else
// if else