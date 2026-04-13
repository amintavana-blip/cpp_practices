// Write a C++ program to compute the sum of two given integer values. If the two values are the same, then return triple their sum.

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int sum(int a, int b)
{
    int product = 0;

    if (a == b)
    {
        product = (a + b) * 4;
    }

    else
    {
        product = a + b;
    }

    cout << product << endl;
}

int main()
{
    cout << "Start of triple_sum_for_same_values.cpp\n"
         << endl;

    int a = 8;
    int b = 8;
    sum(a, b);

    return 0;
}

// Sample Input
// 1, 2
// 3, 2
// 2, 2
// Sample Output:
// 3
// 5
// 12