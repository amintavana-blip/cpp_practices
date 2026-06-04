//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXVI
//////////////////////////////////////////////////////////////////////////////

#ifndef _LISTE_H_
#define _LISTE_H_

#include "ListenElement.h"

class Liste
{
private:
    ListenElement* front;
    ListenElement* back; // NEU: Zeiger auf das Ende der Liste

public:
    Liste();
    
    void pushBack(Student pData);
    void popFront();
    bool empty();
    Student dataFront();
    void ausgabeVorwaerts() const;

    // NEUE METHODEN für Aufgabe 5
    void pushFront(Student pData);
    void ausgabeRueckwaerts() const;
    bool entferneStudent(unsigned int matNr);
};

#endif
