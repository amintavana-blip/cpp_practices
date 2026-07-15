#include "Student.h"

/**
 * @brief Konstruktor für die Klasse Student mit allen Attributen.
 * * @param matNr Die Matrikelnummer des Studenten.
 * @param name Der vollständige Name des Studenten.
 * @param geburtstag Das Geburtsdatum des Studenten.
 * @param adresse Die Wohnadresse des Studenten.
 */
Student::Student(unsigned int matNr, std::string name, std::string geburtstag, std::string adresse) :
matNr(matNr), name(name), geburtstag(geburtstag), adresse(adresse)
{ }

/**
 * @brief Standardkonstruktor. Initialisiert den Studenten mit Standardwerten.
 * * Setzt die Matrikelnummer auf 0 und alle Strings auf einen leeren Text.
 */
Student::Student() : matNr(0), name(""), geburtstag(""), adresse("")
{ }

/**
 * @brief Getter für die Matrikelnummer.
 * @return Die Matrikelnummer als unsigned int.
 */
unsigned int Student::getMatNr() const { return matNr; }

/**
 * @brief Getter für den Namen des Studenten.
 * @return Der Name als std::string.
 */
std::string Student::getName() const { return name; }

/**
 * @brief Getter für das Geburtsdatum.
 * @return Das Geburtsdatum als std::string.
 */
std::string Student::getGeburtstag() const { return geburtstag; }

/**
 * @brief Getter für die Adresse.
 * @return Die Adresse als std::string.
 */
std::string Student::getAdresse() const { return adresse; }

/**
 * @brief Gibt die Daten des Studenten formatiert in einen Ausgabestream aus.
 * * @param out Referenz auf den Ziel-Ausgabestream (z.B. std::cout oder ein Dateistream).
 */
void Student::ausgabe(std::ostream& out) const
{
    out << name << ", MatNr. " << matNr << ", geb. am "
        << geburtstag << ", wohnhaft in " << adresse << "\n";
}

// === NEU: Implementierung der Operatoren ===

/**
 * @brief Überladener Vergleichsoperator (Gleichheit).
 * * Zwei Studenten gelten als identisch, wenn ihre Matrikelnummern übereinstimmen.
 * * @param other Der andere Student, mit dem verglichen wird.
 * @return true Wenn die Matrikelnummern gleich sind, andernfalls false.
 */
bool Student::operator==(const Student& other) const
{
    return this->matNr == other.matNr;
}

/**
 * @brief Überladener Vergleichsoperator (Kleiner-als).
 * * Ermöglicht das Sortieren von Studenten anhand der Matrikelnummer.
 * * @param other Der andere Student, mit dem verglichen wird.
 * @return true Wenn die Matrikelnummer dieses Studenten kleiner ist, andernfalls false.
 */
bool Student::operator<(const Student& other) const
{
    return this->matNr < other.matNr;
}

/**
 * @brief Überladener Vergleichsoperator (Größer-als).
 * * Ermöglicht den Vergleich von Studenten anhand der Matrikelnummer.
 * * @param other Der andere Student, mit dem verglichen wird.
 * @return true Wenn die Matrikelnummer dieses Studenten größer ist, andernfalls false.
 */
bool Student::operator>(const Student& other) const
{
    return this->matNr > other.matNr;
}

// === NEU: Globaler <<-Operator ===

/**
 * @brief Globaler Stream-Operator zur bequemen Ausgabe eines Studenten-Objekts.
 * * @param out Der Ausgabestream, in den geschrieben wird.
 * @param student Das auszugebende Student-Objekt.
 * @return std::ostream& Referenz auf den Ausgabestream für Verkettungen (Chaining).
 */
std::ostream& operator<<(std::ostream& out, const Student& student)
{
    student.ausgabe(out);
    return out;
}