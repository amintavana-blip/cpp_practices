//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 
// 
// Versuch 1.1: Datentypen und Typumwandlung
//
// Datei:  Variablen.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>

using namespace std;

int main() {
    // ==========================================
    // Aufgabenteil 1: Ganze Zahlen (int)
    // ==========================================
    cout << "--- Teil 1: Ganzzahl-Berechnungen ---" << endl;
    int iErste, iZweite;
    cout << "Bitte geben Sie die erste ganze Zahl ein: ";
    cin >> iErste;
    cout << "Bitte geben Sie die zweite ganze Zahl ein: ";
    cin >> iZweite;

    int iSumme = iErste + iZweite;
    // Achtung: Hier findet eine Ganzzahldivision statt (Nachkommastellen werden abgeschnitten)
    int iQuotient = iErste / iZweite; 

    cout << "Int-Summe (iSumme): " << iSumme << endl;
    cout << "Int-Quotient (iQuotient, Ganzzahldivision): " << iQuotient << endl;
    cout << "-------------------------------------" << endl << endl;


    // ==========================================
    // Aufgabenteil 2: Speichern in double ohne Cast
    // ==========================================
    cout << "--- Teil 2: Speichern in double (ohne Cast) ---" << endl;
    double dSumme = iErste + iZweite;
    // Auch hier: Die Division links ist INT/INT, das Ergebnis wird erst danach zu double!
    double dQuotient = iErste / iZweite; 

    cout << "Double-Summe (dSumme): " << dSumme << endl;
    cout << "Double-Quotient (dQuotient, da vorher int-Zerschneidung): " << dQuotient << endl;
    cout << "-----------------------------------------------" << endl << endl;


    // ==========================================
    // Aufgabenteil 3: Mit Typecasting
    // ==========================================
    cout << "--- Teil 3: Mit Typecasting ---" << endl;
    double dSummeCast = static_cast<double>(iErste) + static_cast<double>(iZweite);
    double dQuotientCast = static_cast<double>(iErste) / static_cast<double>(iZweite);

    cout << "Double-Summe mit Cast (dSummeCast): " << dSummeCast << endl;
    cout << "Double-Quotient mit Cast (dQuotientCast): " << dQuotientCast << endl;
    cout << "-------------------------------" << endl << endl;



    // ==========================================
    // Aufgabenteil 4: String-Operationen
    // ==========================================
    cout << "--- Teil 4: String-Operationen ---" << endl;
    string sVorname, sNachname;
    cout << "Bitte geben Sie Ihren Vornamen ein: ";
    cin >> sVorname;
    cout << "Bitte geben Sie Ihren Nachnamen ein: ";
    cin >> sNachname;

    string sVornameName = sVorname + " " + sNachname;
    string sNameVorname = sNachname + ", " + sVorname;

    cout << "Format 'Vorname Nachname': " << sVornameName << endl;
    cout << "Format 'Name, Vorname': " << sNameVorname << endl;
    cout << "----------------------------------" << endl << endl;


    // ==========================================
    // Aufgabenteil 5: Eigener Block {}
    // ==========================================
    cout << "--- Teil 5: Eigener Block und Arrays ---" << endl;
    {
        // a) 1D-Feld
        int iFeld[2] = {1, 2};
        cout << "iFeld[0]: " << iFeld[0] << ", iFeld[1]: " << iFeld[1] << endl;

        // b) 2D-Feld (2 Zeilen, 3 Spalten)
        int spielfeld[2][3] = {
            {1, 2, 3},
            {4, 5, 6}
        };
        cout << "Spielfeld Ausgabe:" << endl;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 3; j++) {
                cout << spielfeld[i][j] << " ";
            }
            cout << endl;
        }

        // c) Konstante im Block
        const int iZweite = 1;
        cout << "iZweite innerhalb des Blocks: " << iZweite << endl;
    } // Ende des Blocks. Die Block-Konstante 'iZweite' wird hier zerstört.

    // Erneute Ausgabe der ursprünglichen Variablen iZweite aus Teil 1
    cout << "iZweite nach dem Block (Wert aus Teil 1): " << iZweite << endl;
    cout << "----------------------------------------" << endl << endl;


    // ==========================================
    // Aufgabenteil 6 & 7: ASCII und Alphabet-Position
    // ==========================================
    cout << "--- Teil 6 & 7: ASCII und Alphabet ---" << endl;
    if (sVorname.length() >= 2) {
        // 6. ASCII-Werte bestimmen (impliziter Cast von char zu int)
        int iName1 = sVorname[0];
        int iName2 = sVorname[1];
        
        cout << "1. Buchstabe '" << sVorname[0] << "' hat ASCII-Wert: " << iName1 << endl;
        cout << "2. Buchstabe '" << sVorname[1] << "' hat ASCII-Wert: " << iName2 << endl;

        // 7. Alphabet-Position berechnen (A/a = 1, B/b = 2, ...)
        int pos1 = iName1 % 32;
        int pos2 = iName2 % 32;

        cout << "Position von '" << sVorname[0] << "' im Alphabet: " << pos1 << endl;
        cout << "Position von '" << sVorname[1] << "' im Alphabet: " << pos2 << endl;
    } else {
        cout << "Der Vorname ist zu kurz, um zwei Buchstaben auszuwerten." << endl;
    }
    cout << "---------------------------------------" << endl;

    return 0;
}