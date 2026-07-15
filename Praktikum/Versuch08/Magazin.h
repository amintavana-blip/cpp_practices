#ifndef MAGAZIN_H_
#define MAGAZIN_H_

#include "Medium.h"
#include "Datum.h" // Required for the date object
#include <string>

class Magazin : public Medium 
{
public:
    Magazin(std::string initTitel, Datum initDatumAusgabe, std::string initSparte);
    bool ausleihen(Person person, Datum ausleihdatum) override;
    void ausgabe(std::ostream& out) const override;

private:
    Datum ausgabeDatum;
    std::string sparte;
};

#endif