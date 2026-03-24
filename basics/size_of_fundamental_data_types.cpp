// Write a in C++ program to find the size of fundamental data types.
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    
    cout << "The sizeof(char) is: " << sizeof(char) << " bytes \n";
    cout << "The sizeof(short) is: " << sizeof(short) << " bytes \n";
    cout << "The sizeof(int) is: " << sizeof(int) << " bytes \n";
    cout << "The sizeof(long) is: " << sizeof(long) << " bytes \n";
    cout << "The sizeof(long long) is: " << sizeof(long long) << " bytes \n";
    cout << "The sizeof(float) is: " << sizeof(float) << " bytes \n";
    cout << "The sizeof(double) is: " << sizeof(double) << " bytes \n";
    cout << "The sizeof(long double) is: " << sizeof(long double) << " bytes \n";
    cout << "The sizeof(bool) is: " << sizeof(bool) << " bytes \n";

    return 0;
}
