//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXVI
// Versuch 02
//
// Datei:  main.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include <iostream>

using namespace std;

// Rekursive Funktion zur Berechnung der n-ten Fibonacci-Zahl
int fibonacci(int n) {
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    
    // Rekursionsschritt
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    cout << "--- Fibonacci-Zahlen von n = 0 bis 25 ---" << endl;
    
    //Berechnung und Ausgabe der Werte von 0 bis 25
    for (int n = 0; n <= 42; n++) {
        cout << "f(" << n << ") = " << fibonacci(n) << endl;
    }
    
    cout << "----------------------------------------" << endl;
    return 0;
}