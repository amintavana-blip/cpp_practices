#ifndef DVD_H_
#define DVD_H_

#include "Medium.h"
#include <string>

class DVD : public Medium 
{
public:
    DVD(std::string initTitel, int initAltersfreigabe, std::string initGenre);
    bool ausleihen(Person person, Datum ausleihdatum) override;
    void ausgabe(std::ostream& out) const override;

private:
    int altersfreigabe;
    std::string genre;
};

#endif