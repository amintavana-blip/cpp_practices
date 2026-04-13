// Write a C++ program to check two given integers, and return true if one of them is 30 or if their sum is 30.
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool test(int a, int b)
{
    return a == 30 || b == 30 || (a + b) == 30;
}

int main()
{
    cout << "Start of check_30_or_sum_30.cpp\n"
         << endl;

    cout << test(30, 0) << endl;  // Output the result of test function with arguments 30 and 0
    cout << test(25, 5) << endl;  // Output the result of test function with arguments 25 and 5
    cout << test(20, 30) << endl; // Output the result of test function with arguments 20 and 30
    cout << test(20, 25) << endl; // Output the result of test function with arguments 20 and 25

    return 0;
}

// Sample Input:
// 30, 0
// 25, 5
// 20, 30
// 20, 25
// Sample Output:
// 1
// 1
// 1
// 0