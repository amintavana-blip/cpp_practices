#include "DVD.h"
#include <iostream>

DVD::DVD(std::string initTitel, int initAltersfreigabe, std::string initGenre) 
    : Medium(initTitel), altersfreigabe(initAltersfreigabe), genre(initGenre) 
{
}

void DVD::ausgabe(std::ostream& out) const 
{
    Medium::ausgabe(out);
    std::cout << "FSK: ab " << altersfreigabe << " Jahren, Genre: " << genre << "\n";
}

bool DVD::ausleihen(Person person, Datum ausleihdatum) 
{
    // Calculate age in years: (Current Date - Birth Date) / 12
    int ageInMonths = ausleihdatum - person.getGeburtsdatum();
    int ageInYears = ageInMonths / 12;

    if (ageInYears < altersfreigabe) 
    {
        std::cout << "Fehler: Person ist zu jung (" << ageInYears 
                  << " Jahre), um diese DVD (FSK " << altersfreigabe << ") auszuleihen!\n";
        return false;
    }

    return Medium::ausleihen(person, ausleihdatum);
}