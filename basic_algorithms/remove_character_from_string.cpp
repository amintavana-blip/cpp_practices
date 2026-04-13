// Write a C++ program to remove the character at a given position in the string. The given position will be in the range 0..string length -1 inclusive.
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string test(string str, int n)
{
    return str.erase(n, 1); // Erase one character at index 'n' from the string 'str' and return the modified string
}
int main() {
    cout << "Start of remove_character_from_string.cpp\n" << endl;

    cout << test("Python", 1) << endl;  // Output the result of test function with string "Python" and index 1
    cout << test("Python", 0) << endl;  // Output the result of test function with string "Python" and index 0
    cout << test("Python", 4) << endl;  // Output the result of test function with string "Python" and index 4

    return 0;
}
