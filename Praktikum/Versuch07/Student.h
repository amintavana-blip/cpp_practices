#ifndef STUDENT_H_
#define STUDENT_H_

#include <string>
#include <ostream>

class Student
{
public:
    Student();
    Student(unsigned int matNr, std::string name, std::string geburtstag, std::string adresse);
    unsigned int getMatNr() const;
    std::string getName() const;
    std::string getGeburtstag() const;
    std::string getAdresse() const;

    // AUFGABE 7.2.1.2: Ausgabe-Funktion mit ostream-Parameter
    void ausgabe(std::ostream& out) const;

    // AUFGABE 7.2.1.1: Operatorenüberladung (Vergleich anhand der Matrikelnummer)
    bool operator==(const Student& other) const;
    bool operator<(const Student& other) const;
    bool operator>(const Student& other) const;

private:
    unsigned int matNr;
    std::string name;
    std::string geburtstag;
    std::string adresse;
};

// AUFGABE 7.2.1.3: Überladung des Ausgabe-Operators
std::ostream& operator<<(std::ostream& out, const Student& student);

#endif