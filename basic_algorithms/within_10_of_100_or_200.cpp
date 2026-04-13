// Write a C++ program to check a given integer and return true if it is within 10 of 100 or 200.
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool check_range(int a)
{
    return abs(100 - a) < 10 || abs(200 - a) < 10;
}

int main() {
    cout << "Start of within_10_of_100_or_200.cpp\n" << endl;

    // TODO: Write your C++ code here

    cout << check_range(109) << endl;
    cout << check_range(193) << endl;
    cout << check_range(89) << endl;
    return 0;
}

// Sample Input:
// 103
// 90
// 89
// Sample Output:
// 1
// 1
// 0