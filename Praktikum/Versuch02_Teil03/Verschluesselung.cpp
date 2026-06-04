///////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 
// 
// Versuch 2.3: Felder
//
// Datei:  Verschuesselung.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>

using namespace std;

// ============================================================================
// 3. Funktion zur Verschlüsselung eines Wortes
// ============================================================================
string verschluesseln(string wort, char tabelle[2][26]) {
    string geheimtext = "";

    // Schleife durch jeden Buchstaben des eingegebenen Wortes
    for (int i = 0; i < wort.length(); i++) {
        char aktuellerBuchstabe = wort[i];
        bool gefunden = false;

        // Suche den Buchstaben in Zeile 1 (Klartext-Zeile) der Tabelle
        for (int j = 0; j < 26; j++) {
            if (tabelle[0][j] == aktuellerBuchstabe) {
                // Ersetze mit dem Buchstaben aus Zeile 2 (Geheimtext-Zeile)
                geheimtext += tabelle[1][j];
                gefunden = true;
                break; // Buchstabe gefunden, innere Schleife abbrechen
            }
        }

        // Falls ein Zeichen nicht im Alphabet von A-Z ist (z.B. Leerzeichen), bleibt es unverändert
        if (!gefunden) {
            geheimtext += aktuellerBuchstabe;
        }
    }
    return geheimtext;
}

// ============================================================================
// 5. Funktion zur Entschlüsselung eines Wortes
// ============================================================================
string entschluesseln(string geheimtext, char tabelle[2][26]) {
    string klartext = "";

    // Schleife durch jeden Buchstaben des Geheimtextes
    for (int i = 0; i < geheimtext.length(); i++) {
        char aktuellerBuchstabe = geheimtext[i];
        bool gefunden = false;

        // Bei der Entschlüsselung suchen wir in Zeile 2 (Geheimtext-Zeile)
        for (int j = 0; j < 26; j++) {
            if (tabelle[1][j] == aktuellerBuchstabe) {
                // ... und wechseln zurück zu Zeile 1 (Klartext-Zeile)
                klartext += tabelle[0][j];
                gefunden = true;
                break;
            }
        }

        if (!gefunden) {
            klartext += aktuellerBuchstabe;
        }
    }
    return klartext;
}

int main()
{
	// ============================================================================
    // 2. Lookup-Tabelle für die Verschlüsselung anlegen
    // ============================================================================
    char lookupTabelle[2][26];

    // Zeile 1: Klartext (A bis Z)
    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (int j = 0; j < 26; j++) {
        lookupTabelle[0][j] = alphabet[j];
    }

    // Zeile 2: Geheimtext (Zufällige Reihenfolge, jeder Buchstabe nur EINMAL!)
    // Hier wird das Alphabet z.B. rückwärts und gemischt eingetragen (Beispiel-Key)
    string schluessel = "QWERTYUIOPASDFGHJKLZXCVBNM"; 
    for (int j = 0; j < 26; j++) {
        lookupTabelle[1][j] = schluessel[j];
    }

    // ============================================================================
    // 4. Testen der Verschlüsselung mit Benutzereingabe
    // ============================================================================
    string benutzerWort;
    cout << "Bitte geben Sie ein Wort in GROSSBUCHSTABEN ein: ";
    cin >> benutzerWort;

    // Verschlüsselung aufrufen
    string verschluesseltesWort = verschluesseln(benutzerWort, lookupTabelle);

    // Ausgabe Klartext und Geheimtext
    cout << "\n--- Verschluesselung ---" << endl;
    cout << "Klartext:     " << benutzerWort << endl;
    cout << "Geheimtext:   " << verschluesseltesWort << endl;

    // ============================================================================
    // 6. Entschlüsseln und in der Konsole ausgeben
    // ============================================================================
    string entschluesseltesWort = entschluesseln(verschluesseltesWort, lookupTabelle);

    cout << "\n--- Entschluesselung ---" << endl;
    cout << "Entschluesselt: " << entschluesseltesWort << endl;
    cout << "------------------------" << endl;
    
	return 0;
}
