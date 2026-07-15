/**
 * @file main.cpp
 * @brief Hauptprogramm für Versuch 07: Operatorenüberladung und STL-Algorithmen
 */

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iterator>
#include <algorithm> // NEU: Für std::sort und std::find

#include "Student.h"

int main()
{
    std::vector<Student> studentenListe;
    Student student;
    char abfrage;

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
                  << "(7): Daten aus einer Datei einlesen" << std::endl
                  << "(8): Daten in eine Datei sichern" << std::endl
                  << "(9): Datenbank sortieren (nach Matrikelnummer)" << std::endl // NEU
                  << "(0): Beenden" << std::endl;
        std::cout << "Ihre Wahl: ";
        std::cin >> abfrage;
        std::cin.ignore(10, '\n');

        switch (abfrage)
        {
            case '1':
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

                    studentenListe.push_back(Student(matNr, name, geburtstag, adresse));
                }
                break;

            case '2':
                {
                    if(!studentenListe.empty())
                    {
                        std::cout << "Der folgende Student vorne ist geloescht worden:" << std::endl;
                        // NEU: Dank <<-Operator können wir das Objekt direkt an cout übergeben!
                        std::cout << studentenListe.front(); 
                        studentenListe.erase(studentenListe.begin());
                    }
                    else
                    {
                        std::cout << "Der Vektor ist bereits leer!\n";
                    }
                }
                break;

            case '3':
                if(!studentenListe.empty())
                {
                    std::cout << "Inhalt des Vektors in fortlaufender Reihenfolge:" << std::endl;
                    for (std::vector<Student>::const_iterator it = studentenListe.cbegin(); it != studentenListe.cend(); ++it)
                    {
                        std::cout << *it; // NEU: Nutzt den überladenen <<-Operator
                    }
                }
                else
                {
                    std::cout << "Der Vektor ist leer!\n\n";
                }
                break;

            case '4':
                if(!studentenListe.empty())
                {
                    std::cout << "Inhalt des Vektors in umgekehrter Reihenfolge:" << std::endl;
                    for (std::vector<Student>::const_reverse_iterator rit = studentenListe.crbegin(); rit != studentenListe.crend(); ++rit)
                    {
                        std::cout << *rit; // NEU
                    }
                }
                else
                {
                    std::cout << "Der Vektor ist leer!\n\n";
                }
                break;

            case '5': // AUFGABE 7.2.2.2: Löschen mit std::find
                {
                    if (studentenListe.empty()) {
                        std::cout << "Der Vektor ist leer!\n";
                        break;
                    }

                    unsigned int matNrSuche = 0;
                    std::cout << "Bitte geben Sie die Matrikelnummer des zu loeschenden Studenten ein: ";
                    std::cin >> matNrSuche;
                    std::cin.ignore(10, '\n');

                    // Genialer Trick: Wir erstellen einen "Dummy"-Studenten nur mit der gesuchten Matrikelnummer.
                    // Da std::find unseren neuen == Operator benutzt (der nur Matrikelnummern vergleicht), 
                    // findet er den richtigen Studenten!
                    Student dummyStudent(matNrSuche, "", "", "");

                    std::vector<Student>::iterator it = std::find(studentenListe.begin(), studentenListe.end(), dummyStudent);

                    if (it != studentenListe.end()) // Wurde gefunden?
                    {
                        std::cout << "Der folgende Student ist geloescht worden:\n";
                        std::cout << *it; // Ausgabe des gefundenen Studenten
                        studentenListe.erase(it);
                    }
                    else
                    {
                        std::cout << "Ein Student mit der Matrikelnummer " << matNrSuche << " wurde nicht gefunden.\n";
                    }
                }
                break;

            case '6':
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

                    studentenListe.insert(studentenListe.begin(), Student(matNr, name, geburtstag, adresse));
                }
                break;

            case '7':
                {
                    std::string dateiname;
                    std::cout << "Bitte geben Sie den Dateinamen zum Einlesen ein (z.B. studierende.txt): ";
                    getline(std::cin, dateiname);

                    std::ifstream eingabeDatei(dateiname);
                    
                    if (!eingabeDatei.is_open())
                    {
                        std::cout << "Fehler: Datei konnte nicht geoeffnet werden!\n";
                    }
                    else
                    {
                        studentenListe.clear(); 
                        unsigned int matNr;
                        std::string name, geburtstag, adresse;

                        while (eingabeDatei >> matNr)
                        {
                            eingabeDatei.ignore(1000, '\n'); 
                            getline(eingabeDatei, name);
                            getline(eingabeDatei, geburtstag);
                            getline(eingabeDatei, adresse);

                            studentenListe.push_back(Student(matNr, name, geburtstag, adresse));
                        }
                        std::cout << "Daten wurden erfolgreich eingelesen.\n";
                        eingabeDatei.close();
                    }
                }
                break;

            case '8':
                {
                    std::string dateiname;
                    std::cout << "Bitte geben Sie den Dateinamen zum Speichern ein: ";
                    getline(std::cin, dateiname);

                    std::ofstream ausgabeDatei(dateiname);
                    
                    if (!ausgabeDatei.is_open())
                    {
                        std::cout << "Fehler: Datei konnte nicht erstellt werden!\n";
                    }
                    else
                    {
                        for (std::vector<Student>::const_iterator it = studentenListe.cbegin(); it != studentenListe.cend(); ++it)
                        {
                            ausgabeDatei << it->getMatNr() << "\n"
                                         << it->getName() << "\n"
                                         << it->getGeburtstag() << "\n"
                                         << it->getAdresse() << "\n";
                        }
                        std::cout << "Daten wurden gesichert.\n";
                        ausgabeDatei.close();
                    }
                }
                break;

            case '9': // AUFGABE 7.2.2.1: Sortieren
                {
                    if(!studentenListe.empty())
                    {
                        // std::sort nutzt automatisch unseren neu überladenen <-Operator!
                        std::sort(studentenListe.begin(), studentenListe.end());
                        std::cout << "Die Datenbank wurde nach Matrikelnummern sortiert!\n";
                    }
                    else
                    {
                        std::cout << "Der Vektor ist leer!\n";
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