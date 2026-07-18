/**
 * @file main.cpp
 * @brief Hauptprogramm für Versuch 06: Nutzung von std::vector und File-I/O
 */

#include <iostream>
#include <string>
#include <vector>
#include <fstream>   // NEU: Für Datei-Ein- und Ausgabe (ifstream, ofstream)
#include <iterator>  // NEU: Für die Iteratoren

#include "Student.h"

int main()
{
    // Die eigene "Liste" wird durch den C++ Standard-Vektor ersetzt
    std::vector<Student> studentenListe;
    Student student;

    char abfrage;

    // AUFGABE 6.4.2.5: Die alte Abfrage und das automatische Füllen auskommentieren!
    
    std::cout << "Wollen Sie die Liste selbst fuellen? (j)/(n) ";
    std::cin >> abfrage;
    std::cin.ignore(10, '\n');

    if (abfrage != 'j')
    {
        student = Student(34567, "Harro Simoneit", "19.06.1971", "Am Markt 1");
        studentenListe.push_back(student);
        student = Student(74567, "Vera Schmitt", "23.07.1982", "Gartenstr. 23");
        studentenListe.push_back(student);
        student = Student(12345, "Siggi Baumeister", "23.04.1983", "Ahornst.55");
        studentenListe.push_back(student);
        student = Student(64567, "Paula Peters", "9.01.1981", "Weidenweg 12");
        studentenListe.push_back(student);
        student = Student(23456, "Walter Rodenstock", "15.10.1963", "Wuellnerstr.9");
        studentenListe.push_back(student);
    }
    

    do
    {
        std::cout << "\nMenue:" << std::endl
                  << "-----------------------------" << std::endl
                  << "(1): Datenelement hinten hinzufuegen" << std::endl
                  << "(2): Datenelement vorne entfernen" << std::endl
                  << "(3): Datenbank ausgeben" << std::endl
                  << "(4): Datenbank in umgekehrter Reihenfolge ausgeben" << std::endl
                  << "(5): Datenelement loeschen (nach Matrikelnummer)" << std::endl
                  << "(6): Datenelement vorne hinzufuegen" << std::endl
                  << "(7): Daten aus einer Datei einlesen" << std::endl      // NEU
                  << "(8): Daten in eine Datei sichern" << std::endl         // NEU
                  << "(0): Beenden" << std::endl;
        std::cout << "Ihre Wahl: ";
        std::cin >> abfrage;
        std::cin.ignore(10, '\n');

        switch (abfrage)
        {
            case '1': // Hinten hinzufügen
                {
                    unsigned int matNr = 0;
                    std::string name, geburtstag, adresse;

                    std::cout << "Bitte geben sie die Daten fuer den Studenten ein.\nName: ";
                    getline(std::cin, name);
                    std::cout << "Geburtsdatum: ";
                    getline(std::cin, geburtstag);
                    std::cout << "Adresse: ";
                    getline(std::cin, adresse);
                    std::cout << "Matrikelnummer: ";
                    std::cin >> matNr;
                    std::cin.ignore(10, '\n');

                    student = Student(matNr, name, geburtstag, adresse);
                    studentenListe.push_back(student); // STL Funktion
                }
                break;

            case '2': // Vorne entfernen
                {
                    if(!studentenListe.empty()) // Sicherheitsabfrage!
                    {
                        std::cout << "Der folgende Student vorne ist geloescht worden:" << std::endl;
                        studentenListe.front().ausgabe();
                        
                        // Mit erase() und dem Iterator auf das 1. Element (begin) loeschen
                        studentenListe.erase(studentenListe.begin());
                    }
                    else
                    {
                        std::cout << "Der Vektor ist bereits leer!\n";
                    }
                }
                break;

            case '3': // Vorwärts ausgeben
                if(!studentenListe.empty())
                {
                    std::cout << "Inhalt des Vektors in fortlaufender Reihenfolge:" << std::endl;
                    // AUFGABE: Konstante Iteratoren (const_iterator) verwenden
                    for (std::vector<Student>::const_iterator it = studentenListe.cbegin(); it != studentenListe.cend(); ++it)
                    {
                        it->ausgabe();
                    }
                }
                else
                {
                    std::cout << "Der Vektor ist leer!\n\n";
                }
                break;

            case '4': // Rückwärts ausgeben
                if(!studentenListe.empty())
                {
                    std::cout << "Inhalt des Vektors in umgekehrter Reihenfolge:" << std::endl;
                    // AUFGABE: Konstante Reverse-Iteratoren (const_reverse_iterator) verwenden
                    for (std::vector<Student>::const_reverse_iterator rit = studentenListe.crbegin(); rit != studentenListe.crend(); ++rit)
                    {
                        rit->ausgabe();
                    }
                }
                else
                {
                    std::cout << "Der Vektor ist leer!\n\n";
                }
                break;

            case '5': // Gezielt löschen
                {
                    if (studentenListe.empty()) {
                        std::cout << "Der Vektor ist leer!\n";
                        break;
                    }

                    unsigned int matNrSuche = 0;
                    std::cout << "Bitte geben Sie die Matrikelnummer des zu loeschenden Studenten ein: ";
                    std::cin >> matNrSuche;
                    std::cin.ignore(10, '\n');

                    bool gefunden = false;
                    for (std::vector<Student>::iterator it = studentenListe.begin(); it != studentenListe.end(); ++it)
                    {
                        if (it->getMatNr() == matNrSuche)
                        {
                            std::cout << "Der folgende Student ist geloescht worden:" << std::endl;
                            it->ausgabe();
                            
                            // Element löschen
                            studentenListe.erase(it);
                            gefunden = true;
                            
                            // AUFGABE (Hinweis 12): Schleife UNBEDINGT abbrechen (break),
                            // da der Iterator 'it' nach erase() ungültig wird!
                            break; 
                        }
                    }

                    if (!gefunden) {
                        std::cout << "Ein Student mit der Matrikelnummer " << matNrSuche << " wurde nicht gefunden.\n";
                    }
                }
                break;

            case '6': // Vorne hinzufügen
                {
                    unsigned int matNr = 0;
                    std::string name, geburtstag, adresse;

                    std::cout << "Bitte geben sie die Daten fuer den Studenten ein, der VORNE hinzugefuegt werden soll.\nName: ";
                    getline(std::cin, name);
                    std::cout << "Geburtsdatum: ";
                    getline(std::cin, geburtstag);
                    std::cout << "Adresse: ";
                    getline(std::cin, adresse);
                    std::cout << "Matrikelnummer: ";
                    std::cin >> matNr;
                    std::cin.ignore(10, '\n');

                    student = Student(matNr, name, geburtstag, adresse);
                    // insert fügt das Element VOR dem angegebenen Iterator (hier begin = ganz vorne) ein
                    studentenListe.insert(studentenListe.begin(), student);
                }
                break;

            case '7': // Aus Datei laden
                {
                    std::string dateiname;
                    std::cout << "Bitte geben Sie den Dateinamen zum Einlesen ein (z.B. studierende.txt): ";
                    getline(std::cin, dateiname);

                    std::ifstream eingabeDatei(dateiname);
                    
                    if (!eingabeDatei.is_open())
                    {
                        std::cout << "Fehler: Datei '" << dateiname << "' konnte nicht geoeffnet werden!\n";
                    }
                    else
                    {
                        // AUFGABE: Alte Daten im Vektor löschen
                        studentenListe.clear(); 

                        unsigned int matNr;
                        std::string name, geburtstag, adresse;

                        // Einlesen, solange eine Matrikelnummer gefunden wird
                        while (eingabeDatei >> matNr)
                        {
                            eingabeDatei.ignore(1000, '\n'); // Den Zeilenumbruch nach der Nummer ignorieren
                            getline(eingabeDatei, name);
                            getline(eingabeDatei, geburtstag);
                            getline(eingabeDatei, adresse);

                            // Studenten-Objekt erstellen und zum Vektor hinzufügen
                            studentenListe.push_back(Student(matNr, name, geburtstag, adresse));
                        }
                        std::cout << "Daten wurden erfolgreich aus '" << dateiname << "' eingelesen.\n";
                        eingabeDatei.close();
                    }
                }
                break;

            case '8': // In Datei speichern
                {
                    std::string dateiname;
                    std::cout << "Bitte geben Sie den Dateinamen zum Speichern ein: ";
                    getline(std::cin, dateiname);

                    std::ofstream ausgabeDatei(dateiname);
                    
                    if (!ausgabeDatei.is_open())
                    {
                        std::cout << "Fehler: Datei '" << dateiname << "' konnte nicht erstellt werden!\n";
                    }
                    else
                    {
                        // Den gesamten Vektor durchlaufen und im gleichen Format schreiben,
                        // in dem auch gelesen wird.
                        for (std::vector<Student>::const_iterator it = studentenListe.cbegin(); it != studentenListe.cend(); ++it)
                        {
                            ausgabeDatei << it->getMatNr() << "\n"
                                         << it->getName() << "\n"
                                         << it->getGeburtstag() << "\n"
                                         << it->getAdresse() << "\n";
                        }
                        std::cout << "Daten wurden erfolgreich in '" << dateiname << "' gesichert.\n";
                        ausgabeDatei.close();
                    }
                }
                break;

            case '0':
                std::cout << "Das Programm wird nun beendet\n";
                break;

            default :
                std::cout << "Falsche Eingabe, bitte nochmal\n";
                break;
        }
    }
    while (abfrage != '0');

    return 0;
}