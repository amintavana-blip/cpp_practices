// Write a C++ program to exchange the first and last characters in a given string and return the result string.
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Function to modify a string based on certain conditions
string test(string str)
{
    // Check if the length of the string is greater than 1
    return str.length() > 1
        ? str.substr(str.length() - 1) + str.substr(1, str.length() - 2) + str.substr(0, 1) // Rearrange the string by moving the first character to the end
        : str; // Return the string as it is if its length is 1 or less
}

// Main function
int main() 
{
    cout << test("abcd") << endl;  // Output the result of test function with string "abcd"
    cout << test("a") << endl;     // Output the result of test function with string "a"
    cout << test("xy") << endl;    // Output the result of test function with string "xy"
    return 0;    // Return 0 to indicate successful execution of the program
}

// Sample Input:
// "abcd"
// "a"
// "xy"
// Sample output:
// dbca
// a
// yx