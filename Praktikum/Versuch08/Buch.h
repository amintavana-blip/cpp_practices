#ifndef BUCH_H_
#define BUCH_H_

#include "Medium.h"
#include <string>

// Inherit publicly from Medium
class Buch : public Medium 
{
public:
    // Constructor
    Buch(std::string initTitel, std::string initAutor);
    
    // Override the output function
    void ausgabe(std::ostream& out) const override;

private:
    std::string autor;
};

#endif