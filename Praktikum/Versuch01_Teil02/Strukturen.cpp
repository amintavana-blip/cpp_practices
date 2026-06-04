/////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXVI
// Versuch 1.2: Strukturen
//
// Datei:  Strukturen.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>

using namespace std;

struct Person {
    string sNachname;
    string sVorname;
    int iGeburtsjahr;
    int iAlter;
};

int main() {
    // Variable vom Typ Person definieren
    Person nBenutzer;

    // Eingabe der Daten durch den Benutzer
    cout << "Bitte geben Sie Ihren Vornamen ein: ";
    cin >> nBenutzer.sVorname;
    
    cout << "Bitte geben Sie Ihren Nachnamen ein: ";
    cin >> nBenutzer.sNachname;

    cout << "Bitte geben Sie Ihr Geburtsjahr ein: ";
    cin >> nBenutzer.iGeburtsjahr;

    cout << "Bitte geben Sie Ihr Alter ein: ";
    cin >> nBenutzer.iAlter;
    
    cout << endl;

    // Sinnvolle Ausgabe der gesamten Struktur nBenutzer
    cout << "--- Originaldaten (nBenutzer) ---" << endl;
    cout << "Vorname:     " << nBenutzer.sVorname << endl;
    cout << "Nachname:    " << nBenutzer.sNachname << endl;
    cout << "Geburtsjahr: " << nBenutzer.iGeburtsjahr << endl;
    cout << "Alter:       " << nBenutzer.iAlter << " Jahre" << endl;
    cout << "----------------------------------" << endl << endl;


    // ==========================================
    // 1. Jedes Element einzeln kopieren
    // ==========================================
    Person nKopieEinzeln;
    nKopieEinzeln.sNachname = nBenutzer.sNachname;
    nKopieEinzeln.sVorname = nBenutzer.sVorname;
    nKopieEinzeln.iGeburtsjahr = nBenutzer.iGeburtsjahr;
    nKopieEinzeln.iAlter = nBenutzer.iAlter;

    // Ausgabe der ersten Kopie
    cout << "--- Kopie 1: Einzeln kopiert (nKopieEinzeln) ---" << endl;
    cout << "Vorname:     " << nKopieEinzeln.sVorname << endl;
    cout << "Nachname:    " << nKopieEinzeln.sNachname << endl;
    cout << "Geburtsjahr: " << nKopieEinzeln.iGeburtsjahr << endl;
    cout << "Alter:       " << nKopieEinzeln.iAlter << " Jahre" << endl;
    cout << "------------------------------------------------" << endl << endl;


    // ==========================================
    // 2. Die gesamte Struktur kopieren
    // ==========================================
    Person nKopieGesamt = nBenutzer; 

    // Ausgabe der zweiten Kopie
    cout << "--- Kopie 2: Gesamt kopiert (nKopieGesamt) ---" << endl;
    cout << "Vorname:     " << nKopieGesamt.sVorname << endl;
    cout << "Nachname:    " << nKopieGesamt.sNachname << endl;
    cout << "Geburtsjahr: " << nKopieGesamt.iGeburtsjahr << endl;
    cout << "Alter:       " << nKopieGesamt.iAlter << " Jahre" << endl;
    cout << "----------------------------------------------" << endl;

    return 0;
}
