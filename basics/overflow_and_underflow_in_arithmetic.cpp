#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    //cout << "Start of overflow_and_underflow_in_arithmetic.cpp\n" << endl;


    cout << "\n\n Check overflow/underflow during various arithmetical operation :\n"; // Outputting a message to check overflow/underflow
    cout << " Range of int is [-2147483648, 2147483647]"<< endl; // Displaying the range of int
	cout << "---------------------------------------------------------------------\n"; // Outputting a separator line

    int n1 = 2147483647; // Assigning the maximum range of integer to n1
    cout <<" Overflow the integer range and set in minimum range : " << n1 + 1 << endl; // Attempting to overflow by adding 1
    cout <<" Increasing from its minimum range : " << n1 + 2 << endl; // Trying to increase beyond the maximum limit
    cout <<" Product is :" << n1 * n1 << endl; // Calculating the product of n1 with itself

    int n2 = -2147483648; // Assigning the minimum range of integer to n2
    cout <<" Underflow the range and set in maximum range : " << n2 - 1 << endl; // Attempting to underflow by subtracting 1
    cout <<" Decreasing from its maximum range : " << n2 - 2 << endl; // Trying to decrease beyond the minimum limit
    cout <<" Product is : " << n2 * n2 << endl; // Calculating the product of n2 with itself

    cout << endl; // Outputting a blank line for better readability

    return 0;
}