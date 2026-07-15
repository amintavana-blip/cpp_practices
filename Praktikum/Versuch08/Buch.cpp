#include "Buch.h"
#include <iostream>

// Call the base class constructor Medium(initTitel) in the initializer list
Buch::Buch(std::string initTitel, std::string initAutor) 
    : Medium(initTitel), autor(initAutor) 
{
}

void Buch::ausgabe(std::ostream& out) const 
{
    // First, call the base class ausgabe() to print ID, Title, and Status
    Medium::ausgabe(out); 
    // Then, print the specific attributes of this subclass
    std::cout << "Autor: " << autor << "\n";
}