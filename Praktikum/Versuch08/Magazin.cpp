#include "Magazin.h"
#include <iostream>

Magazin::Magazin(std::string initTitel, Datum initDatumAusgabe, std::string initSparte) 
    : Medium(initTitel), ausgabeDatum(initDatumAusgabe), sparte(initSparte) 
{
}

void Magazin::ausgabe(std::ostream& out) const 
{
    Medium::ausgabe(out);
    // Assuming the Datum class has an overloaded << operator
    out << "Ausgabe: " << ausgabeDatum << ", Sparte: " << sparte << "\n";
}

bool Magazin::ausleihen(Person person, Datum ausleihdatum) 
{
    int differenceInMonths = ausleihdatum - ausgabeDatum;

    if (differenceInMonths == 0) 
    {
        // Here we can use std::cout because error messages usually go to the console
        std::cout << "Fehler: Die neueste Ausgabe eines Magazins darf nicht ausgeliehen werden!\n";
        return false;
    }

    return Medium::ausleihen(person, ausleihdatum);
}