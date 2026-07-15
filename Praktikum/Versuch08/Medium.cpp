/*!
 * Praktikum Informatik 1 MMXXVI
 *
 * @file Medium.cpp
 * @brief Implementierung der Basisklasse Medium für die Bibliotheksverwaltung.
 * * Diese Datei enthält die grundlegenden Logiken für die Verwaltung eines einzelnen 
 * Mediums, wie die automatische ID-Vergabe, den Ausleihstatus und die Rückgabe.
 */

#include "Medium.h"
#include <string>
#include <iostream>

// Initialisierung des statischen Zählers für eine eindeutige ID-Vergabe
unsigned int Medium::currentID = 1;

/**
 * @brief Konstruktor der Klasse Medium.
 * * Initialisiert ein neues Medium mit einem Titel, generiert eine eindeutige, 
 * fortlaufende ID über den statischen Zähler und setzt den Ausleihstatus auf verfügbar.
 * * @param initTitel Der Titel des Mediums.
 */
Medium::Medium(std::string initTitel)
: titel(initTitel)
, status(false)
{
    ID = currentID++;
}

/**
 * @brief Virtueller Destruktor der Klasse Medium.
 * * Sorgt für eine saubere Speicherbereinigung in abgeleiteten Klassen bei polymorpher Löschung.
 */
Medium::~Medium(void)
{
}

/**
 * @brief Gibt die Profildaten des Mediums in den übergebenen Ausgabestream aus.
 * * Schreibt die ID, den Titel sowie den aktuellen Ausleihstatus (inkl. Entleiher 
 * und Leihdatum, falls ausgeliehen) formatiert in den Stream.
 * * @param out Referenz auf den Ziel-Ausgabestream (z.B. std::cout oder ein Dateistream).
 */
void Medium::ausgabe(std::ostream& out) const
{
    // HINWEIS: Hier wurde std::cout durch out ersetzt, damit das Chaining des <<-Operators fehlerfrei funktioniert
    out << "ID: " << ID << std::endl;
    out << "Titel: " << titel << std::endl;

    if (status)
    {
        out << "Status : Das Medium ist seit dem " << datumAusgeliehen << " an " << personAusgeliehen.getName() << " ausgeliehen." << std::endl;
    }
    else
    {
        out << "Status: Medium ist zurzeit nicht verliehen." << std::endl;
    }
}

/**
 * @brief Verleiht das Medium an eine Person, sofern es aktuell verfügbar ist.
 * * Prüft den aktuellen Status. Ist das Medium frei, wird der Status auf ausgeliehen 
 * gesetzt, die Person sowie das Datum gespeichert und true zurückgegeben.
 * * @param person Die Person, die das Medium ausleihen möchte.
 * @param ausleihdatum Das aktuelle Kalenderdatum des Verleihvorgangs.
 * @return true Wenn der Verleihvorgang erfolgreich war, andernfalls false.
 */
bool Medium::ausleihen(Person person, Datum ausleihdatum)
{
    if (status)
    {
        std::cout << "Das Medium \"" << titel << "\" ist bereits verliehen!" << std::endl;
        return false;
    }
    else
    {
        status = true;
        personAusgeliehen = person;
        datumAusgeliehen = ausleihdatum;
        std::cout << "Das Medium \"" << titel << "\" wird an " << person.getName() << " verliehen." << std::endl;
        return true;
    }
}

/**
 * @brief Nimmt das Medium zurück und setzt den Verleihstatus wieder auf verfügbar.
 * * Prüft, ob das Medium überhaupt verliehen war, und setzt bei Erfolg den Status 
 * wieder auf false zurück.
 */
void Medium::zurueckgeben()
{
    if (status)
    {
        status = false;
        std::cout << "Das Medium \"" << titel << "\" wurde zurueckgegeben." << std::endl;
    }
    else
    {
        std::cout << "Das Medium \"" << titel << "\" ist nicht verliehen!" << std::endl;
    }
}

/**
 * @brief Getter für die eindeutige ID des Mediums.
 * @return Die ID des Objekts als unsigned int.
 */
unsigned int Medium::getID()
{
    return ID;
}

/**
 * @brief Überladener globaler Stream-Ausgabeoperator für die Klasse Medium.
 * * Ermöglicht die direkte Ausgabe eines Medium-Objekts per `std::cout << *mediumPointer;`.
 * * @param out Der Ausgabestream, in den geschrieben wird.
 * @param medium Das auszugebende Medium-Objekt.
 * @return std::ostream& Referenz auf den Ausgabestream für Verkettungen.
 */
std::ostream& operator<<(std::ostream& out, const Medium& medium) 
{
    medium.ausgabe(out);
    return out;
}

/**
 * @brief Gibt Auskunft über den aktuellen Ausleihstatus des Mediums.
 * @return true Wenn das Medium aktuell verliehen ist, andernfalls false.
 */
bool Medium::isAusgeliehen() const
{
    return status;
}